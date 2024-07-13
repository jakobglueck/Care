//
// Created by Jakob Glück on 03.06.24.
//

#include "Apothekenname.h"

PharmacyName::PharmacyName(std::string pharmacyName) {
    if (this->detectNameAttachment(pharmacyName)) {
        pharmacyName = this->removeNameAttachments(pharmacyName);
    }
    this->setPharmacyName(pharmacyName);
}

PharmacyName::PharmacyName() {}

void PharmacyName::setPharmacyName(std::string pharmacyName) {
    // Entfernen von führenden und nachfolgenden Leerzeichen
    pharmacyName.erase(pharmacyName.find_last_not_of(" \n\r\t") + 1);
    pharmacyName.erase(0, pharmacyName.find_first_not_of(" \n\r\t"));
    this->pharmacyName = pharmacyName;
}

std::string PharmacyName::getPharmacyName() {
    return this->pharmacyName;
}

bool PharmacyName::detectNameAttachment(std::string pharmacyName) {
    std::vector<std::string> keywords = this->keywords();

    for (const auto& keyword : keywords) {
        if (pharmacyName.find(keyword) != std::string::npos) {
            return true;
        }
    }

    return false;
}

std::string PharmacyName::removeNameAttachments(std::string pharmacyName) {
    std::vector<std::string> keywords = this->keywords();

    for (const auto& keyword : keywords) {
        size_t pos;
        while ((pos = pharmacyName.find(keyword)) != std::string::npos) {
            pharmacyName.replace(pos, keyword.length(), "");
        }
    }

    pharmacyName.erase(pharmacyName.find_last_not_of(" \n\r\t") + 1);
    pharmacyName.erase(0, pharmacyName.find_first_not_of(" \n\r\t"));

    return pharmacyName;
}

bool PharmacyName::isEqual(PharmacyName &pharmacyName) {
    return this->pharmacyName == pharmacyName.pharmacyName;
}

std::vector<std::string> PharmacyName::keywords() {
    return { "e.K.", "e. K.", "e.K ", "e. K","B.V.","PE","Filiale","e.Kfm","e. Kfm","e.Kfr.",
             "Zytostatika","eK","OHG","oHG","e.K","gGmbH", "GmbH", "Inh.", "Inhaber"};
}
