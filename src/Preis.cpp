#include "Preis.h"

Price::Price(float price, int amount) {
    this->setPrice(price);
    this->setAmount(amount);
}

Price::Price() {}

void Price::setPrice( float price) {
    this->price = this->roundToTwoDecimalPlaces(price);
}

float Price::getPrice() {
    return price;
}

void Price::setAmount(int amount) {
    this->amount = this->checkAmount(amount);
}

int Price::getAmount() {
    return amount;
}

bool Price::isNULL() {
    return price == 0.0f;
}

bool Price::isEqual(Price &otherPrice) {
    return (this->price == otherPrice.getPrice() && this->amount == otherPrice.getAmount());
}

int Price::checkAmount(int &amount) {
    return (amount < 0) ? 0 : amount;
}

float Price::roundToTwoDecimalPlaces(float value) {
    std::stringstream stream;
    stream.precision(2);
    stream << std::fixed << value;
    float result;
    stream >> result;
    return result;
}