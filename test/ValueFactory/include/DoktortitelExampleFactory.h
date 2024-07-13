//
// Created by Jakob Glück on 05.07.24.
//

#pragma once
#include "DoktorTitel.h"

class DoctorTitleExampleFactory {
public:
    static std::string DR_DR();
    static DoctorTitle DR_DR_Constructor();

    static std::string DR();
    static DoctorTitle DR_Constructor();

    static std::string PD();
    static DoctorTitle PD_Constructor();

    static std::string DR_MED();
    static DoctorTitle DR_MED_Constructor();

    static std::string DR_MED_();
    static DoctorTitle DR_MED_WithSpace_Constructor();

    static std::string DR_WRITTEN();
    static DoctorTitle DR_WRITTEN_Constructor();

    static std::string PROF_DR();
    static DoctorTitle PROF_DR_Constructor();

    static std::string PROF_DR_DR();
    static DoctorTitle PROF_DR_DR_Constructor();

    static std::string NO_TITLE();
    static DoctorTitle NO_TITLE_Constructor();
};
