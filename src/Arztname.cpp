//
// Created by Jakob Glück on 08.05.24.
//
#include "Arztname.h"

DoctorName::DoctorName(DoctorTitle doctorTitle, std::string vorname, std::string nachname){
    this->correctVorname(vorname);
    this->correctNachname(nachname);
    this->setDoctorTitle(doctorTitle);
    this->ConvertFullName();
}

DoctorName::DoctorName() {}

void DoctorName::setVorname(std::string &vorname) {
    this->vorname = vorname;
}

void DoctorName::setNachname(std::string &nachname) {
    this->nachname = nachname;
}

void DoctorName::setDoctorTitle(DoctorTitle &doctorTitle) {
    this->doctorTitle = doctorTitle;
}

std::string DoctorName::getVorname() {
    return this->vorname;
}

std::string DoctorName::getNachname() {
    return this->nachname;
}

DoctorTitle DoctorName::getDoctorTitle() {
    return this->doctorTitle;
}

bool DoctorName::checkString(std::string &name) {
    if(name.empty()){
        return false;
    }
    if (std::regex_match(name, std::regex("[A-Za-z]"))) {
        return false;
    }
    if (std::regex_match(name, std::regex("[0-9]+"))) {
        return false;
    }
    std::regex pattern("^(?:[A-Za-z]+\\.)?\\s*[A-Za-z]+(?:[ -][A-Za-z]+)*$");
    if(!std::regex_match(name, pattern)){
        return false;
    }
    return true;
}

void DoctorName::correctVorname(std::string &vorname) {
    if(this->checkString(vorname)){
        this->vorname =  vorname;
    }
    else {
        this->vorname = "";
    }
}

void DoctorName::correctNachname(std::string &nachname) {
    if (this->checkString(nachname)) {
        this->nachname = nachname;
    }
    else {
        this->nachname = "";
    }
}

void DoctorName::correctDoctorTitle(std::string &doctorTitle) {
    this->doctorTitle = DoctorTitle(doctorTitle);
}

bool DoctorName::checkStringEmpty(std::string &name) {
    if(name == ""){
        return true;
    }
    return false;
}

void DoctorName::ConvertFullName() {

    DoctorTitle doctorTitle = DoctorTitle(this->doctorTitle.getDoctorTitle());
    std::tuple<DoctorTitle, std::string, std::string> fullname(doctorTitle, "","");

    if(this->checkStringEmpty(this->vorname) && !this->checkStringEmpty(this->nachname)  ){
        fullname = this->stringConverter(this->nachname);
        this->setDoctorTitle(std::get<0>(fullname));
        this->setVorname(std::get<1>(fullname));
        this->setNachname(std::get<2>(fullname));
    }
    else if(!this->checkStringEmpty(this->vorname) && this->checkStringEmpty(this->nachname)  ){
        fullname = this->stringConverter(this->vorname);
        this->setDoctorTitle(std::get<0>(fullname));
        this->setVorname(std::get<1>(fullname));
        this->setNachname(std::get<2>(fullname));
    }
}

std::tuple<DoctorTitle, std::string, std::string> DoctorName::stringConverter(std::string &name) {
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

bool DoctorName::isEqual(DoctorName &doctorName) {
    return this->vorname == doctorName.vorname && this->nachname == doctorName.nachname && this->doctorTitle.isEqual(doctorName.doctorTitle);
}