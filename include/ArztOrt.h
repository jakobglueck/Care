//
// Created by Jakob Glück on 29.05.24.
//

#pragma once

#include "include.h"

class City{
public:
    City(std::string cityName);
    City();

    void setCityName(std::string  cityName);
    std::string getCityName();

    bool isEqual(City& city);

private:
    bool checkCityName(std::string& cityName);

    std::string cityName;
};