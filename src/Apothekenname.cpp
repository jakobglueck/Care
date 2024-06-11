//
// Created by Jakob Glück on 03.06.24.
//

#include "Apothekenname.h"

PharmacyName::PharmacyName(std::string &pharmacyName) {
    if (this->detectNameAttachment(pharmacyName)) {
        this->removeNameAttachments(pharmacyName);
    }
    this->setPharmacyName(pharmacyName);
}

PharmacyName::PharmacyName() {}

void PharmacyName::setPharmacyName(const std::string &pharmacyName) {
    this->pharmacyName = pharmacyName;
}

std::string PharmacyName::getPharmacyName() const {
    return this->pharmacyName;
}

bool PharmacyName::detectNameAttachment(const std::string &pharmacyName) const {
    std::vector<std::string> keywords = {
            "e.K.", "e. K.", "e.K ", "e. K",
            "gGmbH", "GmbH", "Inh.", "Inhaber"
    };

    for (const auto& keyword : keywords) {
        if (pharmacyName.find(keyword) != std::string::npos) {
            return true;
        }
    }

    return false;
}

void PharmacyName::removeNameAttachments(std::string &pharmacyName) const {
    std::vector<std::string> keywords = {
            "e.K.", "e. K.", "e.K ", "e. K",
            "gGmbH", "GmbH", "Inh.", "Inhaber"
    };

    for (const auto& keyword : keywords) {
        size_t pos;
        while ((pos = pharmacyName.find(keyword)) != std::string::npos) {
            pharmacyName.replace(pos, keyword.length(), "");
        }
    }
}