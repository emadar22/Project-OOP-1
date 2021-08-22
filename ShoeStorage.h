//
// Created by daraw on 10/04/2020.
//

#ifndef HW1_OOP_SHOESTORAGE_H
#define HW1_OOP_SHOESTORAGE_H
#pragma once

#include "PairOfShoes.h"
#define DEFAULT_INIT_STORAGE_SIZE 4
#define ZERO 0.0

namespace OOP_Hw1 {
    class ShoeStorage
    {
        PairOfShoes** shoes; // Array of pointers to PairOfShoes. Some of them are NULL
        int arraySize;
        int nextUse;// Pointer to the next empty index in the array
    public:
        ShoeStorage(int initStorageSize = DEFAULT_INIT_STORAGE_SIZE);//Default Constructor

        ShoeStorage(const ShoeStorage& storage);// Copy constructor
        ShoeStorage& operator=(const ShoeStorage& storage);// operator= overloading
        ~ShoeStorage();//Destructor

        void AddPairOfShoes(const PairOfShoes& pair);//Adding one pair of shoes

        void RemovePairOfShoes(const std::string& shoeName);// removing one pair of shoes having the provided name
        double GetPrice(const std::string& shoeName) const;// Price getter for the specific shoe name provided

        double AverageShoePrice() const;//average price calculator for all the shoe pairs in the storage

        int GetNumOfShoes()const;// returning number of shoes in the storage
    };
}

#endif //HW1_OOP_SHOESTORAGE_H
