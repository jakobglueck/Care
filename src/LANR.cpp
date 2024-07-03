//
// Created by Jakob Glück on 03.06.24.
//

#include "LANR.h"

LANR::LANR(std::string &lanr) {
    this->setTempLANR(lanr);
    if (this->detectInvalidLANR(lanr)) {
        this->setLANR(this->removeLANR(lanr));
    } else {
        this->setLANR(lanr);
    }
}

LANR::LANR() {}

void LANR::setLANR(const std::string &lanr) {
    this->lanr = lanr;
}

void LANR::setTempLANR(const std::string &lanr) {
    this->templanr = lanr;
}

std::string LANR::getLANR() const {
    return this->lanr;
}

std::string LANR::getTempLANR() const {
    return this->templanr;
}

bool LANR::detectInvalidLANR(const std::string &lanr) const {
    if (!std::regex_match(lanr, std::regex(R"(\d+)"))) {
        return false;
    }
    if (lanr.length() < 5) {
        return false;
    }
    if (std::regex_search(lanr, std::regex(R"((\d)\1{3})"))) {
        return false;
    }
    return true;
}

std::string LANR::removeLANR(const std::string &lanr) const {
    return "";
}

bool LANR::isEqual(LANR &lanr) {
    return this->lanr == lanr.lanr && this->templanr == lanr.templanr;
}