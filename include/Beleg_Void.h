//
// Created by Jakob Glück on 03.06.24.
//


#pragma once
#include <iostream>
#include "Belegnr.h"
#include "VOID.h"

class Beleg_Void{
public:
    Beleg_Void(BelegNr& belegNr,VOID& vo_id);
    Beleg_Void();

    void setVOID(VOID& vo_id);
    void setBelegNr(BelegNr& belegNr);

    VOID getVOID();
    BelegNr getBelegNr();

private:
    void replaceMIssingValue(BelegNr& belegNr,VOID& vo_id);

    BelegNr belegNr;
    VOID vo_id;
};