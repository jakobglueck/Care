//
// Created by Jakob Glück on 08.05.24.
//
#pragma once
#include "DoktorTitel.h"

#include <iostream>
#include <regex>
#include <vector>
#include <sstream>


class Arztname{
    public:
        Arztname(std::string& vorname, std::string& nachname, DoctorTitle& doctorTitle);

        void setVorname(std::string& vorname);
        void setNachname(std::string& nachname);
        void setDoctorTitle(DoctorTitle& doctorTitle);

        std::string getVorname();
        std::string getNachname();
        DoctorTitle getDoctorTitle();

        void ConvertFullName();

        void correctVorname(std::string& vorname);
        void correctNachname(std::string& nachname);
        void correctDoctorTitle(std::string& doctorTitle);
    private:
    bool checkStringEmpty(std::string& name);
    bool checkString(std::string& name);

    std::tuple<DoctorTitle, std::string, std::string> stringConverter(std::string& name);

    DoctorTitle doctorTitle;
    std::string vorname;
    std::string nachname;

};