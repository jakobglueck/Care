// Created by Jakob Glück on 02.07.24.

#pragma once

#include "include.h"

class MedicalSpecialty{
public:
    MedicalSpecialty(std::string medicalSpecialty);
    MedicalSpecialty();

    void setMedicalSpecialty(std::string medicalSpecialty);
    std::string getMedicalSpecialty();

    bool isEqual(MedicalSpecialty& medicalSpecialty);

private:
    bool isValidMedicalSpecialty(std::string medicalSpecialty);
    std::string correctMedicalSpecialty(std::string medicalSpecialty);
    std::string removeSubstrings(std::string str, std::vector<std::string> substrings);
    std::string removeExtraSpaces(std::string str);
    std::string trimSpaces(std::string str);
    bool isNumber(std::string& medicalSpecialty);
    std::vector<std::string> keywords();

    std::string medicalSpecialty;
};
