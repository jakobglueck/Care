//
// Created by Jakob Glück on 08.07.24.
//

#pragma once
#include "Beleg_Void.h"

class Beleg_VoidExampleFactory{
public:
    static BelegNr normalBeleg();
    static VOID normalVoid();
    static Beleg_Void normalBeleg_Void();

    static BelegNr onlyBeleg();
    static VOID emptyVoid();
    static Beleg_Void onlyBeleg_Void();

    static BelegNr emptyBeleg();
    static VOID onlyVoid();
    static Beleg_Void Beleg_onlyVoid();

};