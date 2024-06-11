//
// Created by Jakob Glück on 03.06.24.
//

#include "Preis.h"

Price::Price(float &price, int& amount) {
    this->setPrice(price);
    this->setAmount(this->checkAmount(amount));
}

Price::Price() {}

void Price::setPrice(const float &price) {
    this->price = price;
}

void Price::setAmount(const int &amount) {
    this->amount = amount;
}

float Price::getPrice() const {
    return this->price;
}

float Price::getAmount() const {
    return this->amount;
}

bool Price::isNULL() const {
    return this->price == 0.0f;
}

int Price::checkAmount(int &amount) {
    int tempAmount;
    if(amount < 1){
        tempAmount  = 0;
    }
    else {
        tempAmount = amount;
    }
    return amount;
}