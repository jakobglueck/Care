//
// Created by Jakob Glück on 13.05.24.
//
#pragma once

#include "Arztname.h"

class ArztnameExampleFactory {
public:
    static DoctorTitle doktorTitle();
    static std::string normalFirstName();
    static std::string normalLastName();
    static DoctorName normalDoctorName();

    static DoctorTitle dr_dr_Title();
    static std::string longFirstName();
    static std::string longLastName();
    static DoctorName longDoctorName();

    static DoctorTitle emptyTitle();
    static std::string invalidFirstName();
    static std::string invalidLastName();
    static DoctorName invalidDoctorName();

    static std::string EmptyFirstName();
    static std::string FullLastName();
    static DoctorName FullLastNameDoctorName();

    static std::string FullFirstName();
    static std::string EmptyLastName();
    static DoctorName FullFirstNameDoctorName();
};

