//
// Created by Jakob Glück on 13.05.24.
//

#include "include/ArztnameExampleFactory.h"


DoctorTitle ArztnameExampleFactory::doktorTitle() {
    DoctorTitle doctorTitle = DoctorTitle("Dr.");
    return  doctorTitle;
}

std::string ArztnameExampleFactory::normalFirstName() {
    return "Mark";
}

std::string ArztnameExampleFactory::normalLastName() {
    return "Schiller";
}

DoctorName ArztnameExampleFactory::normalDoctorName() {
    DoctorName tempDoctorName = DoctorName(ArztnameExampleFactory::doktorTitle(), ArztnameExampleFactory::normalFirstName(), ArztnameExampleFactory::normalLastName());
    return tempDoctorName;
}

DoctorTitle ArztnameExampleFactory::dr_dr_Title() {
    DoctorTitle doctorTitle = DoctorTitle("Dr.Dr.");
    return  doctorTitle;
}

std::string ArztnameExampleFactory::longFirstName() {
    return "Mark Sebastian";
}

std::string ArztnameExampleFactory::longLastName() {
    return "Schiller-Steffen";
}

DoctorName ArztnameExampleFactory::longDoctorName() {
    DoctorName tempDoctorName = DoctorName(ArztnameExampleFactory::dr_dr_Title(), ArztnameExampleFactory::longFirstName(), ArztnameExampleFactory::longLastName());
    return tempDoctorName;
}

DoctorTitle ArztnameExampleFactory::emptyTitle() {
    DoctorTitle doctorTitle = DoctorTitle("");
    return  doctorTitle;
}

std::string ArztnameExampleFactory::invalidFirstName(){
    return "32435465786";
}

std::string ArztnameExampleFactory::invalidLastName() {
    return "1342536475";
}

DoctorName ArztnameExampleFactory::invalidDoctorName() {
    DoctorName tempDoctorName = DoctorName(ArztnameExampleFactory::emptyTitle(), ArztnameExampleFactory::invalidFirstName(), ArztnameExampleFactory::invalidLastName());
    return tempDoctorName;
}

std::string ArztnameExampleFactory::EmptyFirstName() {
    return "";
}

std::string ArztnameExampleFactory::FullLastName() {
    return "Dr. Mark Schiller";
}

DoctorName ArztnameExampleFactory::FullLastNameDoctorName() {
    DoctorName tempDoctorName = DoctorName(ArztnameExampleFactory::emptyTitle(), ArztnameExampleFactory::EmptyFirstName(), ArztnameExampleFactory::FullLastName());
    return tempDoctorName;
}

std::string ArztnameExampleFactory::FullFirstName() {
    return "Dr. Mark Schiller";
}

std::string ArztnameExampleFactory::EmptyLastName() {
    return "";
}

DoctorName ArztnameExampleFactory::FullFirstNameDoctorName() {
    DoctorName tempDoctorName = DoctorName(ArztnameExampleFactory::emptyTitle(), ArztnameExampleFactory::FullFirstName(), ArztnameExampleFactory::EmptyLastName());
    return tempDoctorName;
}
