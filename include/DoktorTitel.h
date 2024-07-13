//
// Created by Jakob Glück on 29.05.24.
//

#pragma once

#include "include.h"

namespace AcademicTitles{
    enum enumTitle {
        Dr,
        Dr_Dr,
        Prof_Dr,
        Prof_Dr_Dr,
        PD_Dr,
        PD_Dr_Dr,
        NoTitle
    };
}

class DoctorTitle{
public:
    DoctorTitle(std::string title);
    DoctorTitle();

    void setDoctorTitle(const std::string doctorTitle);
    std::string getDoctorTitle() const;

    bool isEqual(DoctorTitle& doctorTitle);

private:
    std::string doctorTitle;

    AcademicTitles::enumTitle stringConverter(const std::string& stringTitle);
    std::string enumConverter(const AcademicTitles::enumTitle& enumTitle);
};