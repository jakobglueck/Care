//
// Created by Jakob Glück on 03.06.24.
//

#include "LANR.h"

LANR::LANR(std::string lanr) {
    this->setTempLANR(lanr);
    if (!this->detectInvalidLANR(lanr)) {
        this->setLANR(this->removeLANR(lanr));
    } else {
        this->setLANR(lanr);
    }
}

LANR::LANR() {}

void LANR::setLANR(std::string lanr) {
    this->lanr = lanr;
}

void LANR::setTempLANR(std::string lanr) {
    this->templanr = lanr;
}

std::string LANR::getLANR() {
    return this->lanr;
}

std::string LANR::getTempLANR() {
    return this->templanr;
}

bool LANR::detectInvalidLANR(std::string &lanr) {
    if (!std::regex_match(lanr, std::regex(R"(\d+)"))) {
        return false;
    }
    if (lanr.length() < 5) {
        return false;
    }
    if (lanr.length() > 9) {
        return false;
    }

    if (std::regex_search(lanr, std::regex(R"((\d)\1{3})"))) {
        return false;
    }
    return true;
}

std::string LANR::removeLANR(std::string& lanr) {
    return "";
}

bool LANR::isEqual(LANR &lanr) {
    return this->lanr == lanr.lanr && this->templanr == lanr.templanr;
}