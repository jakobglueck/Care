//
// Created by Jakob Glück on 08.07.24.
//

#pragma once

#include "ArztPostleitzahl.h"

class PostalCodeExampleFactory{
public:
    static std::string normalPostalCodeValue();
    static PostalCode normalPostalCode();

    static std::string shortPostalCodeValue();
    static PostalCode shortPostalCode();

    static std::string invalidPostalCodeValue();
    static PostalCode invalidPostalCode();

};