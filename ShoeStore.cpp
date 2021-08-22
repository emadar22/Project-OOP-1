//
// Created by daraw on 10/04/2020.
//

#include "ShoeStore.h"
using namespace OOP_Hw1;


OOP_Hw1::ShoeStore::ShoeStore(double discountPercent) {//Default constructor
    this->shoeStorage = ShoeStorage();//Create ShoesStorage using his default constructor and operator=

    this->currentDiscountPrecent = discountPercent;
}

void OOP_Hw1::ShoeStore::SetDiscountPercent(int discount) {
    this->currentDiscountPrecent = discount;
}
double OOP_Hw1::ShoeStore::GetDiscountPercent() const {
    return this->currentDiscountPrecent;
}

void OOP_Hw1::ShoeStore::AddShoes(const std::string &name, double price, int amount) {

    for (int i = 0; i < amount ;i++) {//Adding amount pair of shoes with this name and price to the store
        this->shoeStorage.AddPairOfShoes(PairOfShoes(name, price));
    }

}

double OOP_Hw1::ShoeStore::AverageShoePrice() const {
    if (shoeStorage.GetNumOfShoes() == NO_SHOES)//No Shoes found
    {
        return ZERO;
    }
    double avg = shoeStorage.AverageShoePrice();//Shoe price average before sale

    avg = (avg*((100 - currentDiscountPrecent) / (double)100));//New average after sale

    return avg;
}

double OOP_Hw1::ShoeStore::GetShoePrice(const std::string &shoeName) const {
    return (shoeStorage.GetPrice(shoeName)*((100 - currentDiscountPrecent) /(double) 100));//Shoe price after sale
}

void OOP_Hw1::ShoeStore::RemoveOnePair(const std::string &name) {
    this->shoeStorage.RemovePairOfShoes(name);
}