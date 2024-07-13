//
// Created by Jakob Glück on 03.06.24.
//

#pragma once

#include "include.h"

class BelegNr {
public:
    BelegNr(std::string belegNr);
    BelegNr();

    void setBelegNr(std::string belegNr);
    std::string getBelegNr();

    bool isSet(std::string &belegNr);
    bool isEqual(BelegNr& belegNr);

private:
    std::string belegNr;
};