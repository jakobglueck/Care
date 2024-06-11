//
// Created by Jakob Glück on 04.06.24.
//

#include "Arzneimittel.h"

Pharmaceutical::Pharmaceutical(std::string &pharmaceuticalName, std::string &pzn, Price &price) {
    this->setPrice(price);
    if(this->detectWrongPZN(pzn)){
        this->setPZN(pzn);
    }
    std::string tempPharmaceuticalName = this->convertPharmaceuticalName(pharmaceuticalName);
    if(this->detectWrongPharmaceuticalName(tempPharmaceuticalName)){
        this->setPharmaceuticalName(this->convertNameForIHPE(pzn,tempPharmaceuticalName));
    }
    else{
        this->pharmaceuticalName = (std::string&)"";
        this->pzn = (std::string&)"";
    }
}

Pharmaceutical::Pharmaceutical() {}

void Pharmaceutical::setPharmaceuticalName(std::string &pharmaceuticalName) {
    this->pharmaceuticalName = pharmaceuticalName;
}

void Pharmaceutical::setPZN(std::string &pzn) {
    this->pzn = pzn;
}

void Pharmaceutical::setPrice(Price &price) {
    this->price = price;
}

std::string Pharmaceutical::getPharmaceuticalName() {
    this->pharmaceuticalName;
}

std::string Pharmaceutical::getPZN() {
    return this->pzn;
}

Price Pharmaceutical::getPrice() {
    return this->price;
}

std::string Pharmaceutical::convertPharmaceuticalName(std::string &name) {
    std::string result;
    bool capitalizeNextWord = true;
    for (char c : name) {
        if (capitalizeNextWord && std::isalpha(c)) {
            result += std::tolower(c);
            capitalizeNextWord = false;
        } else if (!std::isalpha(c)) {
            result += c;
        } else {

            result += std::toupper(c);
            capitalizeNextWord = true;
        }
    }
    return result;
}

bool Pharmaceutical::detectWrongPZN(std::string &pzn) {
    std::regex pattern("^[0-9]{5,8}$");
    return std::regex_match(pzn,pattern);
}
bool Pharmaceutical::detectWrongPharmaceuticalName(std::string &pharmaceuticalName) {
    std::regex pattern("^(?!(\\d+$)).+[A-Za-z]+(?:\\s[A-Za-z]+)*(?:\\s\\d+(?:\\s*[mg/ml])?)?(?:\\s\\d+)?$");
    return std::regex_match(pharmaceuticalName, pattern);
}

std::string& Pharmaceutical::convertNameForIHPE(std::string &pzn, std::string& pharmaceuticalName) {
    if(pzn == "09999100" || pzn == "9999100"){
        pharmaceuticalName = "Par.Ernährung (reg.)";
    }
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
}