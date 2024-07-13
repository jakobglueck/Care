//
// Created by Jakob Glück on 10.07.24.
//

#include "include/Fachgruppen_BezeichnungExampleFactory.h"

std::string MedicalSpecialtyExampleFactory::normalMedicalSpecialtyValue() {
    return "Onkologie";
}

MedicalSpecialty MedicalSpecialtyExampleFactory::normalMedicalSpecialty() {
    return MedicalSpecialty(MedicalSpecialtyExampleFactory::normalMedicalSpecialtyValue());
}

std::string MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_Number_Value() {
    return "13244546";
}

MedicalSpecialty MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_Number() {
    return MedicalSpecialty(MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_Number_Value());
}

std::string MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_ZurFreienVerfügung_Value() {
    return "Zur freien Verfügung für die KVen (Notfallärzte etc)";
}

MedicalSpecialty MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_ZurFreienVerfügung() {
    return MedicalSpecialty(MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_ZurFreienVerfügung_Value());
}

std::string MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_HausArzt1_Value() {
    return "Innere Medizin (Hausarzt)";
}

MedicalSpecialty MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_HausArzt1() {
    return MedicalSpecialty(MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_HausArzt1_Value());
}

std::string MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_HausArzt2_Value() {
    return "Innere Medizin Hausarzt";
}

MedicalSpecialty MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_HausArzt2() {
    return MedicalSpecialty(MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_HausArzt2_Value());
}

std::string MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_InSideOfTheValue_Value() {
    return "Innere Hausarzt Medizin";
}

MedicalSpecialty MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_InSideOfTheValue() {
    return MedicalSpecialty(MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_InSideOfTheValue_Value());
}
