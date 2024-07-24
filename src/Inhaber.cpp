//
// Created by Jakob Glück on 02.07.24.
//

#include "Inhaber.h"

PharmacyOwner::PharmacyOwner(std::string pharmacyOwner) {
    if(this->isValidPharmacyOwner(pharmacyOwner)){
        this->setPharmacyOwner(pharmacyOwner);
    }
    else{
        this->setPharmacyOwner(this->correctPharmacyOwner(pharmacyOwner));
    }
}

PharmacyOwner::PharmacyOwner() {}

void PharmacyOwner::setPharmacyOwner(std::string pharmacyOwner) {
    this->pharmacyOwner = pharmacyOwner;
}

std::string PharmacyOwner::getPharmacyOwner() {
    return this->pharmacyOwner;
}

bool PharmacyOwner::isNumber(std::string pharmacyOwner) {
    for (char &c : pharmacyOwner) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

bool PharmacyOwner::isValidPharmacyOwner(std::string& pharmacyOwner) {

    if (this->isNumber(pharmacyOwner)) {
        return false;
    }

    std::vector<std::string> invalidSubstrings = this->keywords();

    for (std::string& substr : invalidSubstrings) {
        if (pharmacyOwner.find(substr) != std::string::npos) {
            return false;
        }
    }
    return true;
}

void PharmacyOwner::removeSubstrings(std::string& pharmacyOwner, std::vector<std::string>& substrings) {
    for (std::string& substr : substrings) {
        size_t pos;
        while ((pos = pharmacyOwner.find(substr)) != std::string::npos) {
            pharmacyOwner.erase(pos, substr.length());
        }
    }
}

std::string PharmacyOwner::correctPharmacyOwner(std::string pharmacyOwner) {
    if (this->isNumber(pharmacyOwner)) {
        return "";
    }

    std::vector<std::string> invalidSubstrings = this->keywords();

    this->removeSubstrings(pharmacyOwner, invalidSubstrings);

    pharmacyOwner.erase(pharmacyOwner.find_last_not_of(" \n\r\t") + 1);
    pharmacyOwner.erase(0, pharmacyOwner.find_first_not_of(" \n\r\t"));

    return pharmacyOwner;
}

bool PharmacyOwner::isEqual(PharmacyOwner &pharmacyOwner) {
    return this->pharmacyOwner == pharmacyOwner.pharmacyOwner;
}

std::vector<std::string> PharmacyOwner::keywords() {
    return {"gGmbH", "GmbH", "e.V.", "e. V.",
            "e V", "e.V", "eV","B.V.", "OHG", "oHG","e.Kfm",
            "e. Kfm","e.Kfr.", "#","e.K.","e. K.","eK","e.K",
            "Inh.","Inhaber"};
}