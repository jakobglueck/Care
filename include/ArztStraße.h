//
// Created by Jakob Glück on 29.05.24.
//

#pragma once

#include "include.h"

class StreetName{
public:
    StreetName(std::string& streetName);
    StreetName();
    void setStreetName(const std::string& streetName);

    std::string getStreetName();

    bool isEqual(StreetName& streetName);

private:
    bool checkStreetName(std::string& streetName);

    std::string correctStreetName(std::string& postalCode);

    std::string streetName;
};