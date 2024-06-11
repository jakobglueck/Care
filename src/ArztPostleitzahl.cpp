//
// Created by Jakob Glück on 29.05.24.
//

#include "ArztPostleitzahl.h"

PostalCode::PostalCode(std::string &postalCode) {
    this->setPostalCode(this->correctPostalCode(postalCode));
}

PostalCode::PostalCode() {}

void PostalCode::setPostalCode(std::string& postalCode) {
    this->postalCode = postalCode;
}

std::string PostalCode::getPostalCode() {
    return this->postalCode;
}

bool PostalCode::checkPostalCode(std::string &postalCode) {

    std::regex regexMoreThanFive("\\d{6,}");
    if (!std::regex_match(postalCode, regexMoreThanFive)) {
        std::cout << "Die Postleitzahl hat nicht mehr als 5 Stellen." << std::endl;
        return false;
    }
    std::regex regexLessThanThree("\\d{0,2}");
    if (std::regex_match(postalCode, regexLessThanThree)) {
        std::cout << "Die Postleitzahl hat weniger als 3 Stellen." << std::endl;
        return false;
    }
    return true;
}

std::string& PostalCode::correctPostalCode(std::string &postalCode) {
    std::string tempPostalCode;
    if(this->checkPostalCode(postalCode)){
        if (postalCode.length() == 4) {
            tempPostalCode = "0" + postalCode;
        }
        else{
            tempPostalCode = postalCode;
        }
    }
    else{
        tempPostalCode = "";
    }
    return tempPostalCode;
}