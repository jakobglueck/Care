//
// Created by Jakob Glück on 29.05.24.
//

#include "DoktorTitel.h"

DoctorTitle::DoctorTitle(std::string &title) {
    AcademicTitles::enumTitle tempTitle =  this->stringConverter(title);
    this->setDoctorTitle(this->enumConverter(tempTitle));
}

DoctorTitle::DoctorTitle() {}

void DoctorTitle::setDoctorTitle(const std::string& doctorTitle) {
    this->doctorTitle = doctorTitle;
}

std::string DoctorTitle::getDoctorTitle() const{
    return this->doctorTitle;
}

AcademicTitles::enumTitle DoctorTitle::stringConverter(const std::string& stringTitle) {
    if (stringTitle.find_first_of("Dr.med") != std::string::npos  || stringTitle.find_first_of("Dr. med") != std::string::npos || stringTitle.find_first_of("Doktor") != std::string::npos){
        if (stringTitle.find("Pro.") != std::string::npos  || stringTitle.find("Professor") != std::string::npos){
                if (stringTitle.find("Dr.med") != std::string::npos  || stringTitle.find("Dr. med") != std::string::npos || stringTitle.find("Doktor") != std::string::npos){
                        return AcademicTitles::enumTitle::Prof_Dr_Dr;
                }
                else{
                    return AcademicTitles::enumTitle::Prof_Dr;
                }
        }
        if(stringTitle.find("PD") != std::string::npos  || stringTitle.find("Privatdozent") != std::string::npos || stringTitle.find("Priv.") != std::string::npos){
            if (stringTitle.find("Dr.med") != std::string::npos  || stringTitle.find("Dr. med") != std::string::npos || stringTitle.find("Doktor") != std::string::npos){
                return AcademicTitles::enumTitle::PD_Dr_Dr;
            }
            else{
                return AcademicTitles::enumTitle::PD_Dr;
            }
        }
        if (stringTitle.find("Dr.med") != std::string::npos  || stringTitle.find("Dr. med") != std::string::npos || stringTitle.find("Doktor") != std::string::npos){{
                return AcademicTitles::enumTitle::Dr_Dr;
            }
        }
        else{
            return AcademicTitles::enumTitle::Dr;
        }
    }
    else{
        return AcademicTitles::enumTitle::NoTitle;
    }
}

std::string DoctorTitle::enumConverter(const AcademicTitles::enumTitle& enumTitle) {
    switch (enumTitle) {
        case AcademicTitles::enumTitle::NoTitle:
            return "";
            break;
        case AcademicTitles::enumTitle::Dr:
            return "Dr.";
            break;
        case AcademicTitles::enumTitle::Dr_Dr:
            return "Dr.Dr.";
            break;
        case AcademicTitles::enumTitle::Prof_Dr:
            return "Prof.Dr.";
            break;
        case AcademicTitles::enumTitle::Prof_Dr_Dr:
            return "Prof.Dr.Dr.";
            break;
        case AcademicTitles::enumTitle::PD_Dr:
            return "PD Dr.";
            break;
        case AcademicTitles::enumTitle::PD_Dr_Dr:
            return "PD Dr.Dr.";
            break;
        default:
            return "";
            break;
    }
}