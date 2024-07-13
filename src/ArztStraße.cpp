//
// Created by Jakob Glück on 29.05.24.
//

#include "ArztStraße.h"

StreetName::StreetName(std::string streetName) {
    this->setStreetName(this->correctStreetName(streetName));
}

StreetName::StreetName() {}

void StreetName::setStreetName(std::string streetName) {
    this->streetName = streetName;
}

std::string StreetName::getStreetName() {
    return this->streetName;
}

bool StreetName::checkStreetName(std::string streetName) {
    if(std::regex_match(streetName, std::regex("[0-9]+"))){
        return false;
    }
    return true;
}

std::string StreetName::replaceSubstring(std::string input, std::string search, std::string replace) {
    return std::regex_replace(input, std::regex(search), replace);
}

std::string StreetName::correctStreetName( std::string streetName) {
    if (!this->checkStreetName(streetName)) {
        return "";
    }

    std::string tempStreetName = streetName;

    if (streetName.find("straße") != std::string::npos) {
        return replaceSubstring(tempStreetName, "straße", "str.");
    }
    if (streetName.find("Straße") != std::string::npos) {
        return replaceSubstring(tempStreetName, "Straße", "Str.");
    }
    if (streetName.find("Strasse") != std::string::npos) {
        return replaceSubstring(tempStreetName, "Strasse", "Str.");
    }
    if (streetName.find("strasse") != std::string::npos) {
        return replaceSubstring(tempStreetName, "strasse", "str.");
    }

    return tempStreetName;
}

bool StreetName::isEqual(StreetName &streetName) {
    return this->streetName == streetName.streetName;
}
