//
// Created by Jakob Glück on 10.07.24.
//

#pragma once

#include "Krankenkasse.h"

class HealthInsuranceCompanyExampleFactory{
public:
    static std::string normalHealthInsuranceValue();
    static HealthInsuranceCompany normalHealthInsurance();

    static std::string normalHealthInsuranceValueLowerCase();
    static HealthInsuranceCompany normalHealthInsuranceLowerCase();

    static std::string emptyHealthInsuranceValue();
    static HealthInsuranceCompany emptyHealthInsurance();

    static std::string existingHealthInsuranceValue();
    static HealthInsuranceCompany existingHealthInsurance();

    static std::string invalidHealthInsuranceValue();
    static HealthInsuranceCompany invalidHealthInsurance();

};