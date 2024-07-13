//
// Created by Jakob Glück on 10.07.24.
//

#pragma once

#include "Betriebsbezeichnung.h"

class OperationalDesignationExampleFactory{
public:
    static std::string normalOperationalDesignationValue();
    static OperationalDesignation normalOperationalDesignation();

    static std::string invalidOperationalDesignationNumberValue();
    static OperationalDesignation invalidOperationalDesignationNumber();

    static std::string invalidOperationalDesignation_OHG_Value();
    static OperationalDesignation invalidOperationalDesignation_OHG();

    static std::string invalidOperationalDesignation_CoKG_Value();
    static OperationalDesignation invalidOperationalDesignation_CoKG();

    static std::string invalidOperationalDesignation_InSideOfTheValue_Value();
    static OperationalDesignation invalidOperationalDesignation_InSideOfTheValue();

};