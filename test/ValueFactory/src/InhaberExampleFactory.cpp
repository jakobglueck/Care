//
// Created by Jakob Glück on 10.07.24.
//

#include "include/InhaberExampleFactory.h"

std::string PharmacyOwnerExampleFactory::normalPharmacyOwnerValue() {
    return "Markus Schiller";
}

PharmacyOwner PharmacyOwnerExampleFactory::normalPharmacyOwner() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::normalPharmacyOwnerValue());
}

std::string PharmacyOwnerExampleFactory::longPharmacyOwnerValue() {
    return "Markus Emilo Schiller";
}

PharmacyOwner PharmacyOwnerExampleFactory::longPharmacyOwner() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::longPharmacyOwnerValue());
}

std::string PharmacyOwnerExampleFactory::shortPharmacyOwnerValue() {
    return "Xi Hou";
}

PharmacyOwner PharmacyOwnerExampleFactory::shortPharmacyOwner() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::shortPharmacyOwnerValue());
}

std::string PharmacyOwnerExampleFactory::invalidPharmacyOwnerNumberValue() {
    return "324356";
}

PharmacyOwner PharmacyOwnerExampleFactory::invalidPharmacyOwnerNumber() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::invalidPharmacyOwnerNumberValue());
}

std::string PharmacyOwnerExampleFactory::invalidPharmacyOwner_eV_Value1() {
    return "Markus Schiller e.V.";
}

PharmacyOwner PharmacyOwnerExampleFactory::invalidPharmacyOwner_eV1() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::invalidPharmacyOwner_eV_Value1());
}

std::string PharmacyOwnerExampleFactory::invalidPharmacyOwner_eV_Value2() {
    return "Markus Schiller eV";
}

PharmacyOwner PharmacyOwnerExampleFactory::invalidPharmacyOwner_eV2() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::invalidPharmacyOwner_eV_Value2());
}

std::string PharmacyOwnerExampleFactory::invalidPharmacyOwner_OHG_Value() {
    return "Markus Schiller OHG";
}

PharmacyOwner PharmacyOwnerExampleFactory::invalidPharmacyOwner_OHG() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::invalidPharmacyOwner_OHG_Value());
}

std::string PharmacyOwnerExampleFactory::invalidPharmacyOwner_Inhaber_Value() {
    return "Inhaber Markus Schiller";
}

PharmacyOwner PharmacyOwnerExampleFactory::invalidPharmacyOwner_Inhaber() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::invalidPharmacyOwner_Inhaber_Value());
}

std::string PharmacyOwnerExampleFactory::invalidPharmacyOwner_GmbH_Value() {
    return "Markus Schiller GmbH";
}

PharmacyOwner PharmacyOwnerExampleFactory::invalidPharmacyOwner_GmbH() {
    return PharmacyOwner(PharmacyOwnerExampleFactory::invalidPharmacyOwner_GmbH_Value());
}