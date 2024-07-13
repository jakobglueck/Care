//
// Created by Jakob Glück on 03.06.24.
//

#pragma once

#include "include.h"

class PharmacyName {
public:
    PharmacyName(std::string pharmacyName);
    PharmacyName();

    void setPharmacyName(std::string pharmacyName);
    std::string getPharmacyName();

    bool isEqual(PharmacyName& pharmacyName);

private:
    bool detectNameAttachment(std::string pharmacyName);
    std::string removeNameAttachments(std::string pharmacyName);

    std::vector<std::string> keywords();

    std::string pharmacyName;
};
