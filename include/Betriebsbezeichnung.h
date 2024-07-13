// Created by Jakob Glück on 02.07.24.

#pragma once

#include "include.h"

class OperationalDesignation{
public:
    OperationalDesignation(std::string operationalDesignation);
    OperationalDesignation();

    void setOperationalDesignation(std::string operationalDesignation);
    std::string getOperationalDesignation();

    bool isEqual(OperationalDesignation& operationalDesignation);

private:
    bool isNumber(std::string operationalDesignation);
    bool isValidOperationalDesignation(std::string operationalDesignation);
    std::string correctOperationalDesignation(std::string operationalDesignation);
    std::string removeSubstrings(std::string str, std::vector<std::string> substrings);
    std::string removeExtraSpaces(std::string str);
    std::string trimSpaces(std::string str);
    std::vector<std::string> keywords();

    std::string operationalDesignation;
};
