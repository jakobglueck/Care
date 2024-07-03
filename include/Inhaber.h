//
// Created by Jakob Glück on 02.07.24.
//

#pragma once

#include "include.h"

class PharmacyOwner{
public:
    PharmacyOwner(std::string& pharmacyOwner);
    PharmacyOwner();

    void setPharmacyOwner(std::string& pharmacyOwner);
    std::string getPharmacyOwner();

    bool isEqual(PharmacyOwner& pharmacyOwner);

private:
    bool isNumber(const std::string& str);
    bool isValidPharmacyOwner(const std::string& pharmacyOwner);
    void removeSubstrings(std::string& str, const std::vector<std::string>& substrings);
    std::string& correctPharmacyOwner(std::string& pharmacyOwner);

    std::string pharmacyOwner;
};