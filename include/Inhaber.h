//
// Created by Jakob Glück on 02.07.24.
//

#pragma once

#include "include.h"

class PharmacyOwner{
public:
    PharmacyOwner(std::string pharmacyOwner);
    PharmacyOwner();

    void setPharmacyOwner(std::string pharmacyOwner);
    std::string getPharmacyOwner();

    bool isEqual(PharmacyOwner& pharmacyOwner);

private:
    bool isNumber(std::string str);
    bool isValidPharmacyOwner(std::string& pharmacyOwner);
    void removeSubstrings(std::string& str, std::vector<std::string>& substrings);
    std::string correctPharmacyOwner(std::string pharmacyOwner);

    std::vector<std::string> keywords();


    std::string pharmacyOwner;
};