//
// Created by Jakob Glück on 08.05.24.
//
#include "Arztname.h"

Arztname::Arztname(std::string &vorname, std::string &nachname, DoctorTitle& doctorTitle){
    this->correctVorname(vorname);
    this->correctNachname(nachname);
    this->setDoctorTitle(doctorTitle);
    this->ConvertFullName();
}

void Arztname::setVorname(std::string &vorname) {
    this->vorname = vorname;
}

void Arztname::setNachname(std::string &nachname) {
    this->nachname = nachname;
}

void Arztname::setDoctorTitle(DoctorTitle &doctorTitle) {
}

std::string Arztname::getVorname() {
    return this->vorname;
}

std::string Arztname::getNachname() {
    return this->vorname;
}

DoctorTitle Arztname::getDoctorTitle() {
    return this->doctorTitle;
}

bool Arztname::checkString(std::string &name) {
    if(name.empty()){
        return false;
    }
    if (std::regex_match(name, std::regex("[A-Za-z]"))) {
        return false;
    }
    if (std::regex_match(name, std::regex("[0-9]+"))) {
        return false;
    }
    std::regex pattern("^[\\p{L}]+(?:[ -][\\p{L}]+)*$");
    if(!std::regex_match(name, pattern)){
        return false;
    }
    return true;
}

void Arztname::correctVorname(std::string &vorname) {
    if(this->checkString(vorname)){
        this->vorname =  vorname;
    }
    else {
        this->vorname = "";
    }
}

void Arztname::correctNachname(std::string &nachname) {
    if (this->checkString(nachname)) {
        this->nachname = nachname;
    }
    else {
        this->nachname = "";
    }
}

void Arztname::correctDoctorTitle(std::string &doctorTitle) {
    this->doctorTitle = DoctorTitle(doctorTitle);
}

bool Arztname::checkStringEmpty(std::string &name) {
    if(name.empty()){
        return true;
    }
    return false;
}

void Arztname::ConvertFullName() {

    DoctorTitle doctorTitle = DoctorTitle((std::string &)"");
    std::tuple<DoctorTitle, std::string, std::string> fullname(doctorTitle, "","");

    if(this->checkStringEmpty(this->vorname) && !this->checkStringEmpty(this->nachname)  ){
        fullname = this->stringConverter(this->vorname);
        this->setDoctorTitle(std::get<0>(fullname));
        this->setVorname(std::get<1>(fullname));
        this->setNachname(std::get<2>(fullname));
    }
    else if(!this->checkStringEmpty(this->vorname) && this->checkStringEmpty(this->nachname)  ){
        fullname = this->stringConverter(this->nachname);
        this->setDoctorTitle(std::get<0>(fullname));
        this->setVorname(std::get<1>(fullname));
        this->setNachname(std::get<2>(fullname));
    }
    else{
        this->setVorname((std::string &) "");
        this->setNachname((std::string &)"");
        this->setDoctorTitle(doctorTitle);
    }
}

std::tuple<DoctorTitle, std::string, std::string> Arztname::stringConverter(std::string &name) {
    std::string firstName, lastName;
    DoctorTitle title = DoctorTitle((std::string &)"");
    std::istringstream iss(name);
    std::vector<std::string> tokens(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{});
    if (!tokens.empty()) {
        title = DoctorTitle(tokens[0]);
        tokens.erase(tokens.begin());
    }
    if (!tokens.empty()) {
        firstName = tokens[0];
        tokens.erase(tokens.begin());
    }
    for (const std::string& token : tokens) {
        if (!lastName.empty()) {
            lastName += " ";
        }
        lastName += token;
    }
    return std::make_tuple(title, firstName, lastName);
}
