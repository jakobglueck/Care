//
// Created by Jakob Glück on 02.07.24.
//

#include "Betriebsbezeichnung.h"

OperationalDesignation::OperationalDesignation(std::string operationalDesignation) {
    if (this->isValidOperationalDesignation(operationalDesignation)) {
        this->setOperationalDesignation(operationalDesignation);
    } else {
        this->setOperationalDesignation(this->correctOperationalDesignation(operationalDesignation));
    }
}

OperationalDesignation::OperationalDesignation() {}

void OperationalDesignation::setOperationalDesignation(std::string operationalDesignation) {
    operationalDesignation = this->trimSpaces(operationalDesignation);

    operationalDesignation = this->removeExtraSpaces(operationalDesignation);

    this->operationalDesignation = operationalDesignation;
}

std::string OperationalDesignation::getOperationalDesignation() {
    return this->operationalDesignation;
}

bool OperationalDesignation::isValidOperationalDesignation(std::string operationalDesignation) {
    std::vector<std::string> invalidSubstrings = this->keywords();

    for (const std::string& substr : invalidSubstrings) {
        if (operationalDesignation.find(substr) != std::string::npos) {
            return false;
        }
    }

    if (this->isNumber(operationalDesignation)) {
        return false;
    }

    return true;
}

std::string OperationalDesignation::removeSubstrings(std::string str, std::vector<std::string> substrings) {
    for (const std::string& substr : substrings) {
        size_t pos;
        while ((pos = str.find(substr)) != std::string::npos) {
            str.erase(pos, substr.length());
        }
    }
    return str;
}

std::string OperationalDesignation::correctOperationalDesignation(std::string operationalDesignation) {
    if(this->isNumber(operationalDesignation)){
        return "";
    }

    std::vector<std::string> invalidSubstrings = this->keywords();

    operationalDesignation = this->removeSubstrings(operationalDesignation, invalidSubstrings);

    operationalDesignation = this->trimSpaces(operationalDesignation);

    operationalDesignation = this->removeExtraSpaces(operationalDesignation);

    return operationalDesignation;
}

bool OperationalDesignation::isEqual(OperationalDesignation& operationalDesignation) {
    return this->operationalDesignation == operationalDesignation.operationalDesignation;
}

std::vector<std::string> OperationalDesignation::keywords() {
    return {"gGmbH", "GmbH", "e.V.", "e. V.", "e V", "e.V",
            "eV","B.V.", "OHG","e.Kfm","SAPV-Team","e. G.",
            "gKAöR","§117 SGBV","eG","&Co.KG","& Co.KG" ,"mbH",
            "+ Co.KG","GbR", "(Entlassungsmanagement 750200598)",
            "G: ",",Entlassungsmanagement", "Entlassungsmanagement",
            "UG","NULL","#","N/A","Pseudo Pseudo-Arzt",
            "Pseudoarzt KH-Entlassungsmanagement","#NV","ungültiger Wert",
            "et. al."};
}

bool OperationalDesignation::isNumber(std::string operationalDesignation) {
    int count = 0;
    for (char const &c : operationalDesignation) {
        if (std::isdigit(c)) {
            count++;
            if (count > 3) {
                return true;
            }
        } else {
            count = 0;
        }
    }
    return false;
}

std::string OperationalDesignation::removeExtraSpaces(std::string str) {
    std::istringstream iss(str);
    std::string result, word;
    bool firstWord = true;

    while (iss >> word) {
        if (firstWord) {
            result = word;
            firstWord = false;
        } else {
            result += " " + word;
        }
    }

    return result;
}

std::string OperationalDesignation::trimSpaces(std::string str) {
    str.erase(str.find_last_not_of(" \n\r\t") + 1);
    str.erase(0, str.find_first_not_of(" \n\r\t"));
    return str;
}
