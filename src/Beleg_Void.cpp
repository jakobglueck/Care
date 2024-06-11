//
// Created by Jakob Glück on 03.06.24.
//

#include "Beleg_Void.h"

Beleg_Void::Beleg_Void(BelegNr &belegNr, VOID &vo_id) {

}

Beleg_Void::Beleg_Void() {}

void Beleg_Void::setBelegNr(BelegNr &belegNr) {
    this->belegNr = belegNr;
}

void Beleg_Void::setVOID(VOID &vo_id) {
    this->vo_id = vo_id;
}

BelegNr Beleg_Void::getBelegNr() {
    return this->belegNr;
}

VOID Beleg_Void::getVOID() {
    return this->vo_id;
}

void Beleg_Void::replaceMIssingValue(BelegNr &belegNr, VOID &vo_id) {
    std::string tempBelegnr, tempVOID;
    tempBelegnr = belegNr.getBelegNr();
    tempVOID = vo_id.getVOID();
    if(!belegNr.isSet(tempBelegnr) && vo_id.isSet(tempVOID)){
        belegNr.setBelegNr(tempVOID);
    }
    else if(belegNr.isSet(tempBelegnr) && !vo_id.isSet(tempVOID)){
        vo_id.setVOID(tempBelegnr);
    }
    else{
        belegNr.setBelegNr(tempBelegnr);
        vo_id.setVOID(tempVOID);
    }
}