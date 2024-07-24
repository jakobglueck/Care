//
// Created by Jakob Glück on 04.06.24.
//

#include "Arzneimittel.h"

Pharmaceutical::Pharmaceutical(std::string pharmaceuticalName, std::string pzn, Price price) {
    this->setPrice(price);
    if(this->detectWrongPZN(pzn)){
        this->setPZN(pzn);
    }
    std::string tempPharmaceuticalName = this->convertPharmaceuticalName(pharmaceuticalName);
    if(this->detectWrongPharmaceuticalName(tempPharmaceuticalName)){
        this->setPharmaceuticalName(this->convertNameForIHPE(pzn,tempPharmaceuticalName));
    }
    else{
        this->pharmaceuticalName = "";
        this->pzn = "";
    }
}

Pharmaceutical::Pharmaceutical() {}

void Pharmaceutical::setPharmaceuticalName(std::string pharmaceuticalName) {
    this->pharmaceuticalName = pharmaceuticalName;
}

void Pharmaceutical::setPZN(std::string pzn) {
    this->pzn = pzn;
}

void Pharmaceutical::setPrice(Price price) {
    this->price = price;
}

std::string Pharmaceutical::getPharmaceuticalName() {
    return this->pharmaceuticalName;
}

std::string Pharmaceutical::getPZN() {
    return this->pzn;
}

Price Pharmaceutical::getPrice() {
    return this->price;
}

std::string Pharmaceutical::convertPharmaceuticalName(std::string &name) {
    std::string result;
    bool capitalizeNextChar = true;

    for (char c : name) {
        if (std::isspace(c)) {
            result += c;
            capitalizeNextChar = true;
        } else if (capitalizeNextChar && std::isalpha(c)) {
            result += std::toupper(c);
            capitalizeNextChar = false;
        } else {
            result += std::tolower(c);
        }
    }
    return result;
}

bool Pharmaceutical::detectWrongPZN(std::string &pzn) {
    std::regex pattern("^[0-9]{5,8}$");
    return std::regex_match(pzn,pattern);
}

bool Pharmaceutical::detectWrongPharmaceuticalName(std::string &pharmaceuticalName) {
    std::regex pattern("^(?!\\d+$).+[A-Za-zäöüÄÖÜß?]+(?:\\s[A-Za-zäöüÄÖÜß?]+)*(?:\\s\\d+(?:\\s*[mg/ml])?)?(?:\\s\\d+)?$");
    return std::regex_match(pharmaceuticalName, pattern);
}

std::string Pharmaceutical::convertNameForIHPE(std::string &pzn, std::string& pharmaceuticalName) {
    std::string temp = pharmaceuticalName;
    if(pzn == "09999100" || pzn == "9999100"){
        temp = "Par.Ernährung (reg.)";
    }
    return temp;
}

bool Pharmaceutical::equalPrice(Price &price) {
    if(this->price.getAmount() == price.getAmount()){
        if(this->price.getPrice() >= price.getPrice()* 1.15 &&  this->price.getPrice() >= price.getPrice()* 0.75 ){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

bool Pharmaceutical::isSet() {
    if(this->pzn == ""){
        return false;
    }
    if(this->pharmaceuticalName == "" || this->price.isNULL()){
        return false;
    }
    return true;
}

bool Pharmaceutical::isEqual(Pharmaceutical &pharmaceutical) {
    return this->pzn == pharmaceutical.pzn && this->pharmaceuticalName == pharmaceutical.pharmaceuticalName &&
    this->price.isEqual(pharmaceutical.price);
}

bool Pharmaceutical::checkAmountForIHPE() {
    if(this->pharmaceuticalName == "Par.Ernährung (reg.)"){
        if(pzn == "09999100" || pzn == "9999100"){
            if(this->price.getAmount() == 1){
                return true;
            }
        }
    }
    return false;
}

bool Pharmaceutical::checkPriceForIHPE() {
    if(this->pharmaceuticalName == "Par.Ernährung (reg.)"){
        if(pzn == "09999100" || pzn == "9999100"){
            if(this->price.getPrice() >= 70.00){
                return true;
            }
        }
    }
    return false;
}