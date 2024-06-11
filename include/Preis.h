//
// Created by Jakob Glück on 03.06.24.
//

#pragma once
#include <iostream>

namespace PriceType{
    enum type{
        GP,
        EP
    };
}

class Price {
public:
    Price(float &price, int &amount);
    Price();

    void setPrice(const float &price);
    float getPrice() const;
    void setAmount(const int &amount);
    float getAmount() const;

    bool isNULL() const;

private:
    int checkAmount(int &amount);
    float price;
    int amount;
};
