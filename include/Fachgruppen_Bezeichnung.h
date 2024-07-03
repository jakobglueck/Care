//
// Created by Jakob Glück on 02.07.24.
//

#pragma once

#include "include.h"

class MedicalSpecialty{
public:
    MedicalSpecialty(std::string& medicalSpecialty);
    MedicalSpecialty();

    void setMedicalSpecialty(std::string& medicalSpecialty);
    std::string getMedicalSpecialty();

    bool isEqual(MedicalSpecialty& medicalSpecialty);

private:
    bool isValidMedicalSpecialty(std::string& medicalSpecialty);
    std::string& correctMedicalSpecialty(std::string& medicalSpecialty);
    void removeSubstrings(std::string& str, const std::vector<std::string>& substrings);

    std::string medicalSpecialty;
};