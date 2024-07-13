//
// Created by Jakob Glück on 05.07.24.
//

#include "include/DoktortitelExampleFactory.h"

std::string DoctorTitleExampleFactory::DR_DR() {
    return "Dr.Dr.";
}

DoctorTitle DoctorTitleExampleFactory::DR_DR_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::DR_DR());
    return tempDoctor;
}

std::string DoctorTitleExampleFactory::DR() {
    return "Dr.";
}

DoctorTitle DoctorTitleExampleFactory::DR_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::DR());
    return tempDoctor;
}

std::string DoctorTitleExampleFactory::DR_MED() {
    return "Dr.med";
}

DoctorTitle DoctorTitleExampleFactory::DR_MED_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::DR_MED());
    return tempDoctor;
}

std::string DoctorTitleExampleFactory::DR_MED_() {
    return "Dr. med";
}

DoctorTitle DoctorTitleExampleFactory::DR_MED_WithSpace_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::DR_MED_());
    return tempDoctor;
}

std::string DoctorTitleExampleFactory::PD() {
    return "PD Dr.";
}

DoctorTitle DoctorTitleExampleFactory::PD_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::PD());
    return tempDoctor;
}

std::string DoctorTitleExampleFactory::PROF_DR() {
    return "Prof.Dr.";
}

DoctorTitle DoctorTitleExampleFactory::PROF_DR_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::PROF_DR());
    return tempDoctor;
}

std::string DoctorTitleExampleFactory::PROF_DR_DR() {
    return "Prof.Dr.Dr.";
}

DoctorTitle DoctorTitleExampleFactory::PROF_DR_DR_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::PROF_DR_DR());
    return tempDoctor;
}

std::string DoctorTitleExampleFactory::NO_TITLE() {
    return "Diplom Mediziner";
}

DoctorTitle DoctorTitleExampleFactory::NO_TITLE_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::NO_TITLE());
    return tempDoctor;
}

std::string DoctorTitleExampleFactory::DR_WRITTEN() {
    return "Doktor der Medizin";
}

DoctorTitle DoctorTitleExampleFactory::DR_WRITTEN_Constructor() {
    DoctorTitle tempDoctor = DoctorTitle(DoctorTitleExampleFactory::DR_WRITTEN());
    return tempDoctor;
}
