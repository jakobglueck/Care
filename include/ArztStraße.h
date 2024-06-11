//
// Created by Jakob Glück on 29.05.24.
//

#pragma once
#include <iostream>
#include <regex>

class StreetName{
public:
    StreetName(std::string& streetName);
    StreetName();
    void setStreetName(const std::string& streetName);

    std::string getStreetName();

    bool checkStreetName(std::string& streetName);

    std::string correctStreetName(std::string& postalCode);
private:
    std::string streetName;
};