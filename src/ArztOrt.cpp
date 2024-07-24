//
// Created by Jakob Glück on 29.05.24.
//
#include "ArztOrt.h"

City::City(std::string cityName) {
    if(this->checkCityName(cityName)){
        this->setCityName(cityName);
    }
    else{
        this->setCityName("");
    }
}

City::City() {}

void City::setCityName(std::string cityName) {
    this->cityName = cityName;
}

std::string City::getCityName() {
    return this->cityName;
}

bool City::checkCityName(std::string &cityName) {

    if (std::regex_match(cityName, std::regex("[A-Za-z]"))) {
        return false;
    }
    if (std::regex_match(cityName, std::regex("[0-9]+"))) {
        return false;
    }
    if(!std::regex_match(cityName, std::regex("([A-Z][a-zA-ZäöüßÄÖÜéÉàÀçÇ]+(?:\\s[A-Za-zA-ZäöüßÄÖÜéÉàÀçÇ]+)*)"))){
        return false;
    }
    return true;
}

bool City::isEqual(City &city) {
    return this->cityName == city.cityName;
}