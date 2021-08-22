//
// Created by daraw on 10/04/2020.
//

#ifndef HW1_OOP_SHOESTORE_H
#define HW1_OOP_SHOESTORE_H
#pragma once

#include "ShoeStorage.h"

#define DEFAULT_DISCOUNT 0.0
#define NO_SHOES 0

namespace OOP_Hw1 {
    class ShoeStore
    {
        ShoeStorage shoeStorage;
        double currentDiscountPrecent;
    public:
        ShoeStore(double discountPercent = DEFAULT_DISCOUNT);// Default constructor

        void SetDiscountPercent(int discount);// Discount percent setter
        double GetDiscountPercent() const;//discount percent getter

        void AddShoes(const std::string& name, double price, int amount = 1);
        //Adding number of shoes as amount with specific price and name
        void RemoveOnePair(const std::string& name);//Removes one pair having the name provided

        double AverageShoePrice() const;// Calculator of the average price of all shoes after sale
        double GetShoePrice(const std::string& shoeName) const;// returning the price of shoes with
        // specific name after sale
    };
}

#endif //HW1_OOP_SHOESTORE_H
