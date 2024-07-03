//
// Created by Jakob Glück on 07.06.24.
//

#pragma once

#include "include.h"

class InsuredPseudonym {
public:
    InsuredPseudonym(std::string& insuredPseudonym);
    InsuredPseudonym();

    void setInsuredPseudonym(std::string& insuredPseudonym);
    std::string getInsuredPseudonym();

    bool isSet();
    bool isEqual(InsuredPseudonym& insuredPseudonym);

private:
    std::string insuredPseudonym;
};