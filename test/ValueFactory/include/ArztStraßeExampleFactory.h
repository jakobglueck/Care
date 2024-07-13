//
// Created by Jakob Glück on 08.07.24.
//

#pragma once

#include "ArztStraße.h"

class StreetExampleFactory {
public:
    static std::string normalStreetName();
    static StreetName normalStreet();

    static std::string longStreetName();
    static StreetName longStreet();


    static std::string streetNameWithStraßeShortcut();
    static StreetName streetNameWithStraße();

    static std::string streetNameWithStrasseShortcut();
    static StreetName streetNameWithStrasse();


    static std::string streetNameWithInvalidValue();
    static StreetName streetNameWithInvalid();
};
