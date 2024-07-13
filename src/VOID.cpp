//
// Created by Jakob Glück on 03.06.24.
//

#include "VOID.h"

VOID::VOID(std::string vo_id) {
    if (this->isSet(vo_id)) {
        this->setVOID(vo_id);
    } else {
        this->setVOID("");
    }
}

VOID::VOID() {}

void VOID::setVOID(std::string vo_id) {
    this->vo_id = vo_id;
}

std::string VOID::getVOID() {
    return this->vo_id;
}

bool VOID::isSet(std::string vo_id) {
    return !vo_id.empty();
}

bool VOID::isEqual(VOID &avoid) {
    return this->vo_id == avoid.vo_id;
}