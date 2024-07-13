//
// Created by Jakob Glück on 02.07.24.
//

#include "appl_Einheiten.h"

ApplicationUnits::ApplicationUnits(std::string amount) {
    this->setApplicationUnits(this->correctApplicationUnits(amount));
}

ApplicationUnits::ApplicationUnits() {}

void ApplicationUnits::setApplicationUnits(std::string amount) {
    this->amount = amount;
}

std::string ApplicationUnits::getApplicationUnits() {
    return this->amount;
}

bool ApplicationUnits::isValidNumber(std::string &amount) {
    if(amount.size() < 1){
        return false;
    }
    for(auto c : amount){
        if(!isdigit(c)) {
            return false;
        }
    }
    if(std::stoi(amount) < 1 && std::stoi(amount) > 20 ){
        return false;
    }
    return true;
}

std::string ApplicationUnits::correctApplicationUnits(std::string amount) {
    if(this->isValidNumber(amount)){
        return amount;
    }
    else{
        return "";
    }
}

bool ApplicationUnits::isEqual(ApplicationUnits &applicationUnits) {
    return this->amount == applicationUnits.amount;
}