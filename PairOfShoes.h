//
// Created by daraw on 10/04/2020.
//

#ifndef HW1_OOP_PAIROFSHOES_H
#define HW1_OOP_PAIROFSHOES_H
#pragma once

#include <string>

namespace OOP_Hw1 {
    class PairOfShoes
    {
        const std::string name;
        double price;
    public:
        PairOfShoes(const std::string& name, double price):name(name), price(price) {};// Constructor
        PairOfShoes(const PairOfShoes& other) :name(other.name), price(other.price) {}//Copy Constructor
        const std::string& GetName() const;// Name getter
        double GetPrice() const;// Price getter
        void SetPrice(double newPrice);// Price setter
    };
}


#endif //HW1_OOP_PAIROFSHOES_H
