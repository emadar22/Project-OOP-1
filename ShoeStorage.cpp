#include "ShoeStorage.h"
using namespace OOP_Hw1;

OOP_Hw1::ShoeStorage::ShoeStorage(int initStorageSize) {// Default constructor
    this->arraySize = initStorageSize;
    shoes = new PairOfShoes*[arraySize];//Allocating memory for array with "arraysize" pointer to PairOfShoes
    for (int i = 0; i < arraySize ; i++)//All pointers initialized to NULL
    {
        shoes[i] = NULL;
    }
    this->nextUse = 0;// index 0 is the next free index to use
}

OOP_Hw1::ShoeStorage::ShoeStorage(const ShoeStorage& storage) {//Copy constructor
    this->arraySize = storage.arraySize; //Copying All  storage private elements
    this->nextUse = storage.nextUse;
    shoes = new PairOfShoes*[arraySize];// Allocating memory for array of pointer the same as in the copied element
    for (int i = 0; i < arraySize; i++)//the new array pointers will point to elements with same name and price as in
                                       // the copied array
    {
        if (i< storage.nextUse) {
            this->shoes[i] = new PairOfShoes(storage.shoes[i]->GetName(), storage.shoes[i]->GetPrice());
        }
        else
        {
            this->shoes[i] = NULL;
        }
    }
}


ShoeStorage& OOP_Hw1::ShoeStorage::operator=(const ShoeStorage &storage) {//Operator= implementation
    if (this == &storage) {//Check self assignment
        return *this;
    }

    delete[] shoes;// delete old data
    shoes = new PairOfShoes*[storage.arraySize];//Allocating array of pointers with same size as the right operand

    for (int i = 0;i < storage.arraySize ;i++) {//the new array pointers will point to elements with same name and price
                                               // as in the right operand

        if (storage.shoes[i] != NULL) {
            this->shoes[i] = new PairOfShoes(storage.shoes[i]->GetName(), storage.shoes[i]->GetPrice());
        }
        else
        {
            this->shoes[i] = NULL;
        }
    }

    this->arraySize = storage.arraySize;
    this->nextUse = storage.nextUse;// the left operand field now are the same as the right operand
    return *this;
}

OOP_Hw1::ShoeStorage::~ShoeStorage() {//Destructor
    for (int i = 0; i < nextUse; i++) {//Deleting the pointed elements so we don't loose any data

        delete (this->shoes[i]);

    }
    delete[]this->shoes;//delete the array
}


void ShoeStorage::AddPairOfShoes(const PairOfShoes &pair) {//Implementing dynamic array
    if (nextUse == arraySize) {// Check if there is place for another element expand if needed

        PairOfShoes** tmp = new PairOfShoes*[2*arraySize];//allocating new array with double size from the old one
        for (int i = 0;i < 2*arraySize;i++) {//copy the data of old array
            if (i < nextUse) {
                tmp[i] = new PairOfShoes(shoes[i]->GetName(), shoes[i]->GetPrice());
            }
            else
            {
                tmp[i] = NULL;
            }
        }
        for (int i = 0;i < nextUse;i++) {//Destroy old array
            delete this->shoes[i];
        }
        delete[]shoes;
        shoes = tmp;//updating old array
        this->arraySize = this->arraySize * 2;//new size update
    }

    shoes[nextUse] = new PairOfShoes(pair.GetName(), pair.GetPrice());//Add new element
    nextUse++;// update index of next free place in the array

}


void OOP_Hw1::ShoeStorage::RemovePairOfShoes(const std::string &shoeName) {
    for (int i = 0; i < this->nextUse;i++)// Search Pair with the provided name
    {
        if (shoes[i]->GetName() == shoeName)
        {

            for (int j = i;j < this->nextUse - 1;j++)//If founded move it to the "next_free-1" using bubble sort
            {
                PairOfShoes* tmp = shoes[j];
                shoes[j] = shoes[j + 1];
                shoes[j + 1] = tmp;
            }
            this->nextUse--;// update next free index to use
            delete shoes[nextUse];// delete the chosen element

            return;
        }
    }
    return;
}

double OOP_Hw1::ShoeStorage::GetPrice(const std::string &shoeName) const {
    for (int i = 0;i < nextUse;i++) {//Search for pair with this name and return this pair price
        if (shoes[i]->GetName() == shoeName)
        {
            return shoes[i]->GetPrice();
        }
    }
    return ZERO;// There no such pair with the provided name
}

double OOP_Hw1::ShoeStorage::AverageShoePrice() const {
    double sum = ZERO;
    if (nextUse == 0) {// There no shoes in the storage
        return ZERO;
    }
    for (int i = 0;i < nextUse;i++) {
        sum += shoes[i]->GetPrice();
    }
    return (sum / (double)nextUse);//casting from int to double
}

int OOP_Hw1::ShoeStorage::GetNumOfShoes() const {
    return (this->nextUse );
}

