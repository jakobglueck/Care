//
// Created by Jakob Glück on 03.06.24.
//

#include "Beleg_Void.h"

Beleg_Void::Beleg_Void(BelegNr belegNr, VOID vo_id) {
    this->replaceMissingValue(belegNr,vo_id);
}

Beleg_Void::Beleg_Void() {}

void Beleg_Void::setBelegNr(BelegNr belegNr) {
    this->belegNr = belegNr;
}

void Beleg_Void::setVOID(VOID vo_id) {
    this->vo_id = vo_id;
}

BelegNr Beleg_Void::getBelegNr() {
    return this->belegNr;
}

VOID Beleg_Void::getVOID() {
    return this->vo_id;
}

void Beleg_Void::replaceMissingValue(BelegNr belegNr, VOID vo_id) {
    std::string tempBelegnr, tempVOID;
    tempBelegnr = belegNr.getBelegNr();
    tempVOID = vo_id.getVOID();
    if(!belegNr.isSet(tempBelegnr) && vo_id.isSet(tempVOID)){
        this->belegNr.setBelegNr(tempVOID);
        this->vo_id.setVOID(tempVOID);
    }
    else if(belegNr.isSet(tempBelegnr) && !vo_id.isSet(tempVOID)){
        this->vo_id.setVOID(tempBelegnr);
        this->belegNr.setBelegNr(tempBelegnr);
    }
    else{
        this->belegNr.setBelegNr(tempBelegnr);
        this->vo_id.setVOID(tempVOID);
    }
}

bool Beleg_Void::isSet() {
    return this->vo_id.getVOID() != "" && this->belegNr.getBelegNr() != "";
}

bool Beleg_Void::isEqual(Beleg_Void &belegVoid) {
    return this->belegNr.isEqual(belegVoid.belegNr) && this->vo_id.isEqual(belegVoid.vo_id);
}