//
// Created by Jakob Glück on 05.07.24.
//

#pragma once

#include "Preis.h"

class PriceExampleFactory {
public:
    static int normalAmount();
    static int highAmount();
    static int lowAmount();

    static float emptyPriceValue();
    static float normalPriceValue();
    static float highPriceValue();
    static float NULLPriceValue();


    static Price emptyPrice();
    static Price normalPrice();
    static Price highPrice();
    static Price NULLPrice();
};
