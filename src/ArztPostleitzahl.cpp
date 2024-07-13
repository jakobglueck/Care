//
// Created by Jakob Glück on 29.05.24.
//

#include "ArztPostleitzahl.h"

PostalCode::PostalCode(std::string postalCode) {
    this->setPostalCode(this->correctPostalCode(postalCode));
}

PostalCode::PostalCode() {}

void PostalCode::setPostalCode(std::string postalCode) {
    this->postalCode = postalCode;
}

std::string PostalCode::getPostalCode() {
    return this->postalCode;
}

bool PostalCode::checkPostalCode(std::string &postalCode) {
    std::regex regexFiveDigits("^\\d{5}$");
    return std::regex_match(postalCode, regexFiveDigits);
}

std::string PostalCode::correctPostalCode(std::string &postalCode) {
    std::string tempPostalCode = "";
    if (this->checkPostalCode(postalCode)) {
        tempPostalCode = postalCode;
    } else if (postalCode.length() == 4 && std::regex_match(postalCode, std::regex("^\\d{4}$"))) {
        tempPostalCode = "0" + postalCode;
    }
    return tempPostalCode;
}

bool PostalCode::isEqual(PostalCode &postalCode) {
    return this->postalCode == postalCode.postalCode;
}