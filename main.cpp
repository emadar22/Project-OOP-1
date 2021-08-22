#include <iostream> // IO
#include <iomanip> // Set floating point precision
#include "ShoeStore.h"

#define SANDLES "Sandles"
#define BOOTS "Boots"
#define FLIP_FLOPS "Flip Flops"
#define DISCOUNT_PERCENT 25

using OOP_Hw1::ShoeStore;

int main() {
    // Set floating point printing precision to two decimal points
    std::cout << std::fixed << std::setprecision(2);

    ShoeStore store;  // Initilized via default constructor
    store.AddShoes(SANDLES, 84.90, 10);
    store.AddShoes(BOOTS, 199.0, 5);
    store.AddShoes(FLIP_FLOPS, 19.90);
    std::cout << "Shoe Store Initilized!" << std::endl;
    std::cout << "**********************" << std::endl;

    {
        ShoeStore temporarySore = store; // copy constructor is called
        temporarySore.RemoveOnePair(BOOTS);
        temporarySore.RemoveOnePair(SANDLES);
        std::cout << "Temporary store average shoe price: " << temporarySore.AverageShoePrice() << std::endl;
    } // temporarySore's destructor will be called here

    std::cout << "Sandles Price: " << store.GetShoePrice(SANDLES) << std::endl;

    std::cout << "Average shoe price: " << store.AverageShoePrice() << std::endl;

    store.SetDiscountPercent(DISCOUNT_PERCENT);
    std::cout << "Discount was set to " << DISCOUNT_PERCENT << "%" << std::endl;

    std::cout << "Boots Price: " << store.GetShoePrice(BOOTS) << std::endl;
    std::cout << "Average shoe price: " << store.AverageShoePrice() << std::endl;

    store.RemoveOnePair(SANDLES);
    std::cout << "One pair of sandles removed" << std::endl;

    std::cout << "Average shoe price: " << store.AverageShoePrice() << std::endl;

    return 0;
}

