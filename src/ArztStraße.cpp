//
// Created by Jakob Glück on 29.05.24.
//

#include "ArztStraße.h"

StreetName::StreetName(std::string &streetName) {
    this->setStreetName(this->correctStreetName(streetName));
}

StreetName::StreetName() {}

void StreetName::setStreetName(const std::string& streetName) {
    this->streetName = streetName;
}

std::string StreetName::getStreetName() {
    return this->streetName;
}

bool StreetName::checkStreetName(std::string &streetName) {
    if(std::regex_match(streetName, std::regex("[0-9]+"))){
        return false;
    }
    return true;
}

std::string StreetName::correctStreetName(std::string& postalCode) {
    std::string tempStreetName;
    if(!this->checkStreetName(postalCode)){
        tempStreetName = "";
    }
    if (postalCode.find("Straße")){
        tempStreetName = std::regex_replace(postalCode,std::regex("traße"), "tr.");
    }
    if (postalCode.find("Strasse")){
        tempStreetName = std::regex_replace(postalCode,std::regex("trasse"), "tr.");
    }
    if(!postalCode.find("Straße") && !postalCode.find("Strasse")){
        tempStreetName = postalCode;
    }
    return tempStreetName;
}

bool StreetName::isEqual(StreetName &streetName) {
    return this->streetName == streetName.streetName;
}
