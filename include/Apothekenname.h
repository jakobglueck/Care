//
// Created by Jakob Glück on 03.06.24.
//

#pragma once

#include "include.h"

class PharmacyName {
public:
    PharmacyName(std::string &pharmacyName);
    PharmacyName();

    void setPharmacyName(const std::string &pharmacyName);
    std::string getPharmacyName() const;

    bool isEqual(PharmacyName& pharmacyName);

private:
    bool detectNameAttachment(const std::string &pharmacyName) const;
    void removeNameAttachments(std::string &pharmacyName) const;

    std::string pharmacyName;
};
