//
// Created by Jakob Glück on 02.07.24.
//

#include "Fachgruppen_Bezeichnung.h"

MedicalSpecialty::MedicalSpecialty(std::string &medicalSpecialty) {
    if(this->isValidMedicalSpecialty(medicalSpecialty)){
        this->setMedicalSpecialty(medicalSpecialty);
    }
    else{
        this->setMedicalSpecialty(this->correctMedicalSpecialty(medicalSpecialty));
    }
}

MedicalSpecialty::MedicalSpecialty() {}

void MedicalSpecialty::setMedicalSpecialty(std::string &medicalSpecialty) {
    this->medicalSpecialty = medicalSpecialty;
}

std::string MedicalSpecialty::getMedicalSpecialty() {
    return this->medicalSpecialty;
}

bool MedicalSpecialty::isValidMedicalSpecialty(std::string &medicalSpecialty) {

    for(char c : medicalSpecialty){
        if(isdigit(c)){
            return false;
        }
    }

    std::vector<std::string> invalidSubstrings = {"(Facharzt)", "(Hausarzt)", "Hausarzt", "Facharzt", "Praktischer Arzt"};
    for (const std::string& substr : invalidSubstrings) {
        if (medicalSpecialty.find(substr) != std::string::npos) {
            return false;
        }
    }

    return true;
}

void MedicalSpecialty::removeSubstrings(std::string& str, const std::vector<std::string>& substrings) {
    for (const std::string& substr : substrings) {
        size_t pos;
        while ((pos = str.find(substr)) != std::string::npos) {
            str.erase(pos, substr.length());
        }
    }
}

std::string& MedicalSpecialty::correctMedicalSpecialty(std::string& pharmacyOwner) {
    std::vector<std::string> invalidSubstrings = {"(Facharzt)", "(Hausarzt)", "Hausarzt", "Facharzt", "Praktischer Arzt"};
    removeSubstrings(pharmacyOwner, invalidSubstrings);

    return pharmacyOwner;
}

bool MedicalSpecialty::isEqual(MedicalSpecialty &medicalSpecialty) {
    return this->medicalSpecialty == medicalSpecialty.medicalSpecialty;
}