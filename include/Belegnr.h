//
// Created by Jakob Glück on 03.06.24.
//

#pragma once

#include "include.h"

class BelegNr {
public:
    BelegNr(std::string &belegNr);
    BelegNr();

    void setBelegNr(const std::string &belegNr);
    std::string getBelegNr() const;

    bool isSet(const std::string &belegNr) const;
    bool isEqual(BelegNr& belegNr);

private:
    std::string belegNr;
};