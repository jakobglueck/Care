//
// Created by Jakob Glück on 08.05.24.
//

#pragma once

#include "include.h"
#include "DoktorTitel.h"

class DoctorName{
    public:
        DoctorName(DoctorTitle doctorTitle, std::string vorname, std::string nachname);
        DoctorName();

        void setVorname(std::string& vorname);
        void setNachname(std::string& nachname);
        void setDoctorTitle(DoctorTitle& doctorTitle);

        std::string getVorname();
        std::string getNachname();
        DoctorTitle getDoctorTitle();

        bool isEqual(DoctorName& doctorName);

    private:
    void ConvertFullName();

    void correctVorname(std::string& vorname);
    void correctNachname(std::string& nachname);
    void correctDoctorTitle(std::string& doctorTitle);

    bool checkStringEmpty(std::string& name);
    bool checkString(std::string& name);

    std::tuple<DoctorTitle, std::string, std::string> stringConverter(std::string& name);

    DoctorTitle doctorTitle;
    std::string vorname;
    std::string nachname;

};