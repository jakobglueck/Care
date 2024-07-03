//
// Created by Jakob Glück on 02.07.24.
//

#include "Inhaber.h"

PharmacyOwner::PharmacyOwner(std::string &pharmacyOwner) {
    if(this->isValidPharmacyOwner(pharmacyOwner)){
        this->setPharmacyOwner(pharmacyOwner);
    }
    else{
        this->setPharmacyOwner(this->correctPharmacyOwner(pharmacyOwner));
    }
}

PharmacyOwner::PharmacyOwner() {}

void PharmacyOwner::setPharmacyOwner(std::string &pharmacyOwner) {
    this->pharmacyOwner = pharmacyOwner;
}

std::string PharmacyOwner::getPharmacyOwner() {
    return this->pharmacyOwner;
}

bool PharmacyOwner::isNumber(const std::string& pharmacyOwner) {
    for (char const &c : pharmacyOwner) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

bool PharmacyOwner::isValidPharmacyOwner(const std::string& pharmacyOwner) {

    if (this->isNumber(pharmacyOwner)) {
        return false;
    }

    std::vector<std::string> invalidSubstrings = {"gGmbH", "GmbH", "e.V.", "e. V.", "e V", "e.V", "eV","B.V.", "OHG","e.Kfm" };
    for (const std::string& substr : invalidSubstrings) {
        if (pharmacyOwner.find(substr) != std::string::npos) {
            return false;
        }
    }
    return true;
}

void PharmacyOwner::removeSubstrings(std::string& pharmacyOwner, const std::vector<std::string>& substrings) {
    for (const std::string& substr : substrings) {
        size_t pos;
        while ((pos = pharmacyOwner.find(substr)) != std::string::npos) {
            pharmacyOwner.erase(pos, substr.length());
        }
    }
}

std::string& PharmacyOwner::correctPharmacyOwner(std::string& pharmacyOwner) {
    if (this->isNumber(pharmacyOwner)) {
        return (std::string&) "";
    }

    std::vector<std::string> invalidSubstrings = {"gGmbH", "GmbH", "e.V.", "e. V.", "e V", "e.V", "eV","B.V.", "OHG","e.Kfm" };
    this->removeSubstrings(pharmacyOwner, invalidSubstrings);
    return pharmacyOwner;
}

bool PharmacyOwner::isEqual(PharmacyOwner &pharmacyOwner) {
    return this->pharmacyOwner == pharmacyOwner.pharmacyOwner;
}