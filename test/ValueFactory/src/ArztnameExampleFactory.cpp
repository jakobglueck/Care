//
// Created by Jakob Glück on 13.05.24.
//

#include "include/ArztnameExampleFactory.h"

std::string ArztnameExampleFactory::normalVorname(){
    return "Karl";
}

std::string ArztnameExampleFactory::normalNachname() {
    return "Bauer";
}

DoctorName ArztnameExampleFactory::normalName() {
    std::string vorName = ArztnameExampleFactory::normalVorname();
    std::string nachName = ArztnameExampleFactory::normalNachname();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::shortVorname() {
    return "Xi";
}

std::string ArztnameExampleFactory::shortNachname() {
    return "Ho";
}

DoctorName ArztnameExampleFactory::shortName() {
    std::string vorName = ArztnameExampleFactory::shortVorname();
    std::string nachName = ArztnameExampleFactory::shortNachname();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::longVorname() {
    return "Alexander";
}

std::string ArztnameExampleFactory::longNachname() {
    return "Rosenberg";
}

DoctorName ArztnameExampleFactory::longName() {
    std::string vorName = ArztnameExampleFactory::longVorname();
    std::string nachName = ArztnameExampleFactory::longNachname();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::doubleVorname() {
    return "Maximilian Alexander";
}

std::string ArztnameExampleFactory::doubleNachname() {
    return "Rosenberg Müller";
}

DoctorName ArztnameExampleFactory::doubleName() {
    std::string vorName = ArztnameExampleFactory::doubleVorname();
    std::string nachName = ArztnameExampleFactory::doubleNachname();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::tripleVorname() {
    return "Gabriel Maximilian Alexander";
}

std::string ArztnameExampleFactory::tripleNachname() {
    return "Schneider-Steinmann-von Hohenstein";
}

DoctorName ArztnameExampleFactory::tripleName() {
    std::string vorName = ArztnameExampleFactory::tripleVorname();
    std::string nachName = ArztnameExampleFactory::tripleNachname();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::validNumberVorname() {
    return "Karl II";
}

std::string ArztnameExampleFactory::validNumberNachname() {
    return "von Hohen";
}

DoctorName ArztnameExampleFactory::validNumberName() {
    std::string vorName = ArztnameExampleFactory::validNumberVorname();
    std::string nachName = ArztnameExampleFactory::validNumberNachname();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::emtpyVorname() {
    return "";
}

std::string ArztnameExampleFactory::emtpyNachname(){
    return "";
}

DoctorName ArztnameExampleFactory::emtpyName() {
    std::string vorName = ArztnameExampleFactory::emtpyVorname();
    std::string nachName = ArztnameExampleFactory::emtpyNachname();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::invalidNumberVorname1() {
    return "12";
}

std::string ArztnameExampleFactory::invalidNumberNachname1(){
    return "12";
}

DoctorName ArztnameExampleFactory::invalidNumberName1() {
    std::string vorName = ArztnameExampleFactory::invalidNumberVorname1();
    std::string nachName = ArztnameExampleFactory::invalidNumberNachname1();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::invalidNumberVorname2() {
    return "1232465834";
}

std::string ArztnameExampleFactory::invalidNumberNachname2() {
    return "1232465834";
}

DoctorName ArztnameExampleFactory::invalidNumberName2() {
    std::string vorName = ArztnameExampleFactory::invalidNumberVorname2();
    std::string nachName = ArztnameExampleFactory::invalidNumberNachname2();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::invalidNumberVorname3(){
    return "06618";
}

std::string ArztnameExampleFactory::invalidNumberNachname3(){
    return "06618";
}

DoctorName ArztnameExampleFactory::invalidNumberName3() {
    std::string vorName = ArztnameExampleFactory::invalidNumberVorname3();
    std::string nachName = ArztnameExampleFactory::invalidNumberNachname3();
    DoctorName name = DoctorName();
    return name;
}

std::string ArztnameExampleFactory::invalidNumberVorname4(){
    return "0000000000";
}
std::string ArztnameExampleFactory::invalidNumberNachname4(){
    return "0000000000";
}

DoctorName ArztnameExampleFactory::invalidNumberName4() {
    std::string vorName = ArztnameExampleFactory::invalidNumberVorname4();
    std::string nachName = ArztnameExampleFactory::invalidNumberNachname4();
    DoctorName name = DoctorName();
    return name;
}