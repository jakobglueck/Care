//
// Created by Jakob Glück on 02.07.24.
//

#include "Betriebsbezeichnung.h"

OperationalDesignation::OperationalDesignation(std::string &operationalDesignation) {
    if(this->isValidOperationalDesignation(operationalDesignation)){
        this->setOperationalDesignation(operationalDesignation);
    }
    else{
        this->setOperationalDesignation(this->correctOperationalDesignation(operationalDesignation));
    }
}

OperationalDesignation::OperationalDesignation() {}

void OperationalDesignation::setOperationalDesignation(std::string &operationalDesignation) {
    this->operationalDesignation = operationalDesignation;
}

std::string OperationalDesignation::getOperationalDesignation() {
    return this->operationalDesignation;
}

bool OperationalDesignation::isValidOperationalDesignation(std::string &operationalDesignation) {
    int count = 0;

    for (char const &c : operationalDesignation) {
        if (std::isdigit(c)) {
            count++;
            if (count > 3) return false;
        } else {
            count = 0;
        }
    }

    std::vector<std::string> invalidSubstrings = {"gGmbH", "GmbH", "e.V.", "e. V.", "e V", "e.V", "eV","B.V.", "OHG","e.Kfm" };
    for (const std::string& substr : invalidSubstrings) {
        if (operationalDesignation.find(substr) != std::string::npos) {
            return false;
        }
    }
    return true;
}

void OperationalDesignation::removeSubstrings(std::string& str, const std::vector<std::string>& substrings) {
    for (const std::string& substr : substrings) {
        size_t pos;
        while ((pos = str.find(substr)) != std::string::npos) {
            str.erase(pos, substr.length());
        }
    }
}

std::string& OperationalDesignation::correctOperationalDesignation(std::string& operationalDesignation) {
    std::vector<std::string> invalidSubstrings = {"gGmbH", "GmbH", "e.V.", "e. V.", "e V", "e.V", "eV","B.V.", "OHG","e.Kfm" };
    this->removeSubstrings(operationalDesignation, invalidSubstrings);
    return operationalDesignation;
}

bool OperationalDesignation::isEqual(OperationalDesignation &operationalDesignation) {
    return this->operationalDesignation == operationalDesignation.operationalDesignation;
}