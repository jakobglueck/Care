//
// Created by Jakob Glück on 04.06.24.
//

#pragma once
#include <iostream>
#include <regex>
#include "Preis.h"

class Pharmaceutical{
public:
    Pharmaceutical(std::string& pharmaceuticalName, std::string& pzn, Price& price);
    Pharmaceutical();

    void setPharmaceuticalName(std::string& pharmaceuticalName);
    void setPZN(std::string& pzn);
    void setPrice(Price& price);

    std::string getPharmaceuticalName();
    std::string getPZN();
    Price getPrice();

    bool detectWrongPZN(std::string& pzn);
    bool detectWrongPharmaceuticalName(std::string& pharmaceuticalName);
    std::string& convertNameForIHPE(std::string& pzn, std::string& pharmaceuticalName);

    bool equalPrice(Price& price);

private:
    std::string convertPharmaceuticalName(std::string& name);
    std::string pharmaceuticalName;
    std::string pzn;
    Price price;
};