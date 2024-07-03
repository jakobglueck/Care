//
// Created by Jakob Glück on 29.05.24.
//

#pragma once

#include "include.h"
#include <xls.h>

class City{
public:
    City(std::string& cityName);
    City();

    void setCityName(std::string&  cityName);
    std::string getCityName();

    bool isEqual(City& city);

private:
    bool checkCityName(std::string& cityName);
    const char* converterStringToChar(const std::string& cityName);
    bool findCityNameInExcel(const char* cityName);

    std::string cityName;
};