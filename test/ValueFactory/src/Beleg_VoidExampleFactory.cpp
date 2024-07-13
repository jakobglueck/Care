//
// Created by Jakob Glück on 08.07.24.
//

#include "include/Beleg_VoidExampleFactory.h"

BelegNr Beleg_VoidExampleFactory::normalBeleg() {
    BelegNr tempBeleg = BelegNr("23242533");
    return tempBeleg;
}

VOID Beleg_VoidExampleFactory::normalVoid() {
    VOID tempVoid = VOID("23242533132");
    return tempVoid;
}

Beleg_Void Beleg_VoidExampleFactory::normalBeleg_Void() {
    return Beleg_Void(Beleg_VoidExampleFactory::normalBeleg(),Beleg_VoidExampleFactory::normalVoid() );
}

BelegNr Beleg_VoidExampleFactory::emptyBeleg(){
    BelegNr tempBeleg = BelegNr("");
    return tempBeleg;
}

VOID Beleg_VoidExampleFactory::onlyVoid() {
    VOID tempVoid = VOID("23242533132");
    return tempVoid;
}

Beleg_Void Beleg_VoidExampleFactory::Beleg_onlyVoid() {
    return Beleg_Void(Beleg_VoidExampleFactory::emptyBeleg(),Beleg_VoidExampleFactory::onlyVoid() );
}

BelegNr Beleg_VoidExampleFactory::onlyBeleg() {
    BelegNr tempBeleg = BelegNr("23242533132");
    return tempBeleg;
}

VOID Beleg_VoidExampleFactory::emptyVoid() {
    VOID tempVoid = VOID("");
    return tempVoid;
}

Beleg_Void Beleg_VoidExampleFactory::onlyBeleg_Void() {
    return Beleg_Void(Beleg_VoidExampleFactory::onlyBeleg(),Beleg_VoidExampleFactory::emptyVoid() );
}
