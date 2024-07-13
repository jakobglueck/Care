//
// Created by Jakob Glück on 10.07.24.
//

#pragma once

#include "Inhaber.h"

class PharmacyOwnerExampleFactory{
public:
    static std::string normalPharmacyOwnerValue();
    static PharmacyOwner normalPharmacyOwner();

    static std::string longPharmacyOwnerValue();
    static PharmacyOwner longPharmacyOwner();

    static std::string shortPharmacyOwnerValue();
    static PharmacyOwner shortPharmacyOwner();

    static std::string invalidPharmacyOwnerNumberValue();
    static PharmacyOwner  invalidPharmacyOwnerNumber();

    static std::string invalidPharmacyOwner_eV_Value1();
    static PharmacyOwner  invalidPharmacyOwner_eV1();

    static std::string invalidPharmacyOwner_eV_Value2();
    static PharmacyOwner  invalidPharmacyOwner_eV2();

    static std::string invalidPharmacyOwner_OHG_Value();
    static PharmacyOwner  invalidPharmacyOwner_OHG();

    static std::string invalidPharmacyOwner_Inhaber_Value();
    static PharmacyOwner  invalidPharmacyOwner_Inhaber();

    static std::string invalidPharmacyOwner_GmbH_Value();
    static PharmacyOwner  invalidPharmacyOwner_GmbH();

};