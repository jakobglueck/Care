//
// Created by Jakob Glück on 10.07.24.
//

#pragma once

#include "Fachgruppen_Bezeichnung.h"

class MedicalSpecialtyExampleFactory{
public:
    static std::string normalMedicalSpecialtyValue();
    static MedicalSpecialty normalMedicalSpecialty();

    static std::string invalidMedicalSpecialty_Number_Value();
    static MedicalSpecialty invalidMedicalSpecialty_Number();

    static std::string invalidMedicalSpecialty_ZurFreienVerfügung_Value();
    static MedicalSpecialty invalidMedicalSpecialty_ZurFreienVerfügung();

    static std::string invalidMedicalSpecialty_HausArzt1_Value();
    static MedicalSpecialty invalidMedicalSpecialty_HausArzt1();

    static std::string invalidMedicalSpecialty_HausArzt2_Value();
    static MedicalSpecialty invalidMedicalSpecialty_HausArzt2();

    static std::string invalidMedicalSpecialty_InSideOfTheValue_Value();
    static MedicalSpecialty invalidMedicalSpecialty_InSideOfTheValue();
};