//
// Created by Jakob Glück on 03.06.24.
//

#pragma once
#include <iostream>

class BelegNr {
public:
    BelegNr(std::string &belegNr);
    BelegNr();

    void setBelegNr(const std::string &belegNr);
    std::string getBelegNr() const;

    bool isSet(const std::string &belegNr) const;

private:
    std::string belegNr;
};