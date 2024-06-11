//
// Created by Jakob Glück on 29.05.24.
//

#pragma once
#include <iostream>
#include <regex>
#include "xls.h"

class City{
public:
    City(std::string& cityName);
    City();

    void setCityName(std::string&  cityName);
    std::string getCityName();

    bool checkCityName(std::string& cityName);

private:
    const char* converterStringToChar(const std::string& cityName);
    bool findCityNameInExcel(const char* cityName);
    std::string cityName;
};