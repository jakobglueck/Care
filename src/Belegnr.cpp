//
// Created by Jakob Glück on 03.06.24.
//

#include "Belegnr.h"

BelegNr::BelegNr(std::string belegNr) {
    if (this->isSet(belegNr)) {
        this->setBelegNr(belegNr);
    } else {
        this->setBelegNr("");
    }
}

BelegNr::BelegNr() {}

void BelegNr::setBelegNr(std::string belegNr) {
    this->belegNr = belegNr;
}

std::string BelegNr::getBelegNr(){
    return this->belegNr;
}

bool BelegNr::isSet (std::string &belegNr) {
    return !belegNr.empty();
}

bool BelegNr::isEqual(BelegNr &belegNr) {
    return this->belegNr == belegNr.belegNr;
}