//
// Created by Jakob Glück on 29.05.24.
//

#include "DoktorTitel.h"

DoctorTitle::DoctorTitle(std::string title) {
    AcademicTitles::enumTitle tempTitle =  this->stringConverter(title);
    this->setDoctorTitle(this->enumConverter(tempTitle));
}

DoctorTitle::DoctorTitle() {}

void DoctorTitle::setDoctorTitle(const std::string doctorTitle) {
    this->doctorTitle = doctorTitle;
}

std::string DoctorTitle::getDoctorTitle() const{
    return this->doctorTitle;
}

AcademicTitles::enumTitle DoctorTitle::stringConverter(const std::string& stringTitle) {
    bool hasDr = (stringTitle.find("Dr.") != std::string::npos ||
                  stringTitle.find("Doctor") != std::string::npos ||
                  stringTitle.find("dr") != std::string::npos ||
                  stringTitle.find("MUDr") != std::string::npos ||
                  stringTitle.find("MD.") != std::string::npos ||
                  stringTitle.find("MBBS") != std::string::npos ||
                  stringTitle.find("M.D.") != std::string::npos ||
                  stringTitle.find("M.B.B.S.") != std::string::npos ||
                  stringTitle.find("doctor") != std::string::npos ||
                  stringTitle.find("docteur") != std::string::npos ||
                  stringTitle.find("doctoris") != std::string::npos ||
                  stringTitle.find("Doctoris") != std::string::npos ||
                  stringTitle.find("Doctora") != std::string::npos ||
                  stringTitle.find("Dott.") != std::string::npos ||
                  stringTitle.find("Doktor") != std::string::npos);

    bool hasProf = (stringTitle.find("Prof.") != std::string::npos ||
                    stringTitle.find("Professorin") != std::string::npos ||
                    stringTitle.find("Professor") != std::string::npos);

    bool hasPD = (stringTitle.find("PD") != std::string::npos ||
                  stringTitle.find("Privatdozent") != std::string::npos ||
                  stringTitle.find("Priv.") != std::string::npos);

    bool hasDrDr = (stringTitle.find("Dr.Dr.") != std::string::npos ||
                    stringTitle.find("Dr.med. Dr.med.") != std::string::npos ||
                    stringTitle.find("Dr.medDr.") != std::string::npos ||
                    stringTitle.find("Dr. med Dr.") != std::string::npos ||
                    stringTitle.find("DoktorDoktor") != std::string::npos);

    if (hasProf) {
        if (hasDrDr) {
            return AcademicTitles::Prof_Dr_Dr;
        } else if (hasDr) {
            return AcademicTitles::Prof_Dr;
        }
    } else if (hasPD) {
        if (hasDrDr) {
            return AcademicTitles::PD_Dr_Dr;
        } else if (hasDr) {
            return AcademicTitles::PD_Dr;
        }
    } else if (hasDrDr) {
        return AcademicTitles::Dr_Dr;
    } else if (hasDr) {
        return AcademicTitles::Dr;
    }

    return AcademicTitles::NoTitle;
}

std::string DoctorTitle::enumConverter(const AcademicTitles::enumTitle& enumTitle) {
    switch (enumTitle) {
        case AcademicTitles::enumTitle::NoTitle:
            return "";
        case AcademicTitles::enumTitle::Dr:
            return "Dr.";
        case AcademicTitles::enumTitle::Dr_Dr:
            return "Dr.Dr.";
        case AcademicTitles::enumTitle::Prof_Dr:
            return "Prof.Dr.";
        case AcademicTitles::enumTitle::Prof_Dr_Dr:
            return "Prof.Dr.Dr.";
        case AcademicTitles::enumTitle::PD_Dr:
            return "PD Dr.";
        case AcademicTitles::enumTitle::PD_Dr_Dr:
            return "PD Dr.Dr.";
        default:
            return "";
    }
}

bool DoctorTitle::isEqual(DoctorTitle &doctorTitle) {
    return this->doctorTitle == doctorTitle.doctorTitle;
}