//
// Created by Jakob Glück on 08.07.24.
//

#pragma once
#include "ArztOrt.h"

class CityExampleFactory{
public :
    static std::string normalCityName();
    static City normalCity();

    static std::string longCityName();
    static City longCity();

    static std::string invalid1CityName();
    static City invalid1City();

    static std::string invalid2CityName();
    static City invalid2City();

    static std::string invalid3CityName();
    static City invalid3City();

};