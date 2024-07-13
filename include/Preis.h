//
// Created by Jakob Glück on 03.06.24.
//

#pragma once

#include "include.h"

namespace PriceType {
    enum type {
        GP,
        EP
    };
}

class Price {
public:
    Price(float price, int amount);
    Price();

    void setPrice( float price);
    float getPrice();
    void setAmount( int amount);
    int getAmount();

    bool isNULL();
    bool isEqual(Price &price);

private:
    int checkAmount(int &amount);
    float roundToTwoDecimalPlaces(float value);

    float price;
    int amount;
};
