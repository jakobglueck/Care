//
// Created by Jakob Glück on 05.07.24.
//

#include "include/PreisExampleFactory.h"
#include <optional>


int PriceExampleFactory::normalAmount() {
    return 2;
}

int PriceExampleFactory::highAmount() {
    return 20;
}

int PriceExampleFactory::lowAmount() {
    return 0;
}

float PriceExampleFactory::NULLPriceValue() {
    return 0.00;
}

float PriceExampleFactory::emptyPriceValue() {
    std::optional<float> emptyFloat;
    return emptyFloat.has_value();
}

float PriceExampleFactory::highPriceValue() {
    return 13425346.00;
}

float PriceExampleFactory::normalPriceValue() {
    return 1235.23f;
}

Price PriceExampleFactory::emptyPrice(){
    Price tempPrice = Price(PriceExampleFactory::emptyPriceValue(),PriceExampleFactory::lowAmount());
    return tempPrice;
}

Price PriceExampleFactory::normalPrice(){
    Price tempPrice = Price(PriceExampleFactory::normalPriceValue(),PriceExampleFactory::normalAmount());
    return tempPrice;
}

Price PriceExampleFactory::highPrice(){
    Price tempPrice = Price(PriceExampleFactory::highPriceValue(),PriceExampleFactory::highAmount());
    return tempPrice;
}

Price PriceExampleFactory::NULLPrice(){
    Price tempPrice = Price(PriceExampleFactory::NULLPriceValue(),PriceExampleFactory::lowAmount());
    return tempPrice;
}