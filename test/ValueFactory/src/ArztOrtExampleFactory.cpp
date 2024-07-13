//
// Created by Jakob Glück on 08.07.24.
//

#include "include/ArztOrtExampleFactory.h"

std::string CityExampleFactory::normalCityName() {
    return "Hamburg";
}

City CityExampleFactory::normalCity() {
    return City(CityExampleFactory::normalCityName());
}

std::string CityExampleFactory::longCityName() {
    return "Ludwigshafen am Rhein";
}

City CityExampleFactory::longCity() {
    return City(CityExampleFactory::longCityName());
}

std::string CityExampleFactory::invalid1CityName() {
    return "Paris";
}

City CityExampleFactory::invalid1City() {
    return City(CityExampleFactory::invalid1CityName());
}

std::string CityExampleFactory::invalid2CityName() {
    return "Müchen";
}

City CityExampleFactory::invalid2City() {
    return City(CityExampleFactory::invalid2CityName());
}

std::string CityExampleFactory::invalid3CityName() {
    return "#";
}

City CityExampleFactory::invalid3City() {
    return City(CityExampleFactory::invalid3CityName());
}