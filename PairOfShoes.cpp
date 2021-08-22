#include "PairOfShoes.h"

#include <string>
using std::string;

const std::string& OOP_Hw1::PairOfShoes::GetName() const {
    return this->name;
}

double OOP_Hw1::PairOfShoes::GetPrice() const {
    return this->price;
}

void OOP_Hw1::PairOfShoes::SetPrice(double newPrice) {
    this->price = newPrice;
}