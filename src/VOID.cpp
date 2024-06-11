//
// Created by Jakob Glück on 03.06.24.
//

#include "VOID.h"

VOID::VOID(std::string &vo_id) {
    if (this->isSet(vo_id)) {
        this->setVOID(vo_id);
    } else {
        this->setVOID((std::string&)"");
    }
}

VOID::VOID() {}

void VOID::setVOID(const std::string &vo_id) {
    this->vo_id = vo_id;
}

std::string VOID::getVOID() const {
    return this->vo_id;
}

bool VOID::isSet(const std::string &vo_id) const {
    return !vo_id.empty();
}