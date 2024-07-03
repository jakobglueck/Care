//
// Created by Jakob Glück on 02.07.24.
//

#pragma once

#include "include.h"

class OperationalDesignation{
public:
    OperationalDesignation(std::string& operationalDesignation);
    OperationalDesignation();

    void setOperationalDesignation(std::string& operationalDesignation);
    std::string getOperationalDesignation();

    bool isEqual(OperationalDesignation& operationalDesignation);

private:
    bool isValidOperationalDesignation(std::string& operationalDesignation);
    std::string& correctOperationalDesignation(std::string& operationalDesignation);
    void removeSubstrings(std::string& str, const std::vector<std::string>& substrings);
    std::string operationalDesignation;
};