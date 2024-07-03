//
// Created by Jakob Glück on 25.06.24.
//

#include "BSNR.h"

BSNR::BSNR(std::string &bsnr) {
    if(this->detectWrongBSNR(bsnr)){
        this->setBSNR(this->convertWrongBSNR(bsnr));
    }
    else{
        this->setBSNR(bsnr);
    }
}

BSNR::BSNR() {}

void BSNR::setBSNR(std::string &bsnr) {
    this->bsnr = bsnr;
}

std::string BSNR::getBSNR() {
    return this->bsnr;
}

bool BSNR::detectWrongBSNR(std::string &bsnr) {
    std::string digits;
    std::copy_if(bsnr.begin(), bsnr.end(), std::back_inserter(digits), ::isdigit);

    if (digits.length() < 5) {
        return true;
    }

    std::regex fourIdenticalDigitsPattern(R"((\d)\1{3,})");
    if (std::regex_search(digits, fourIdenticalDigitsPattern)) {
        return true;
    }

    if (digits.find_first_not_of('0') >= 4) {
        return true;
    }

    return false;
}

std::string& BSNR::convertWrongBSNR(std::string &bsnr) {
    return (std::string&)"";
}

bool BSNR::isEqual(BSNR &bsnr) {
    return this->bsnr == bsnr.bsnr;
}