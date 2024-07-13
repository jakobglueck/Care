//
// Created by Jakob Glück on 02.07.24.
//

#pragma once

#include "include.h"

class ApplicationUnits{
public:
    ApplicationUnits(std::string amount);
    ApplicationUnits();

    void setApplicationUnits(std::string amount);
    std::string getApplicationUnits();

    bool isEqual(ApplicationUnits& applicationUnits);

private:
    bool isValidNumber(std::string& amount);
    std::string correctApplicationUnits(std::string amount);

    std::string amount;
};