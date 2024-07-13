//
// Created by Jakob Glück on 10.07.24.
//

#include "include/KrankenkassenExampleFactory.h"

std::string HealthInsuranceCompanyExampleFactory::normalHealthInsuranceValue() {
    return "AOK Bayern_01012024_01.2024-12.2024";
}

HealthInsuranceCompany HealthInsuranceCompanyExampleFactory::normalHealthInsurance() {
    return HealthInsuranceCompany(HealthInsuranceCompanyExampleFactory::normalHealthInsuranceValue());
}

std::string HealthInsuranceCompanyExampleFactory::normalHealthInsuranceValueLowerCase() {
    return "aok bayern_01012024_01.2024-12.2024";
}

HealthInsuranceCompany HealthInsuranceCompanyExampleFactory::normalHealthInsuranceLowerCase() {
    return HealthInsuranceCompany(HealthInsuranceCompanyExampleFactory::normalHealthInsuranceValueLowerCase());
}

std::string HealthInsuranceCompanyExampleFactory::emptyHealthInsuranceValue() {
    return "";
}

HealthInsuranceCompany HealthInsuranceCompanyExampleFactory::emptyHealthInsurance() {
    return HealthInsuranceCompany(HealthInsuranceCompanyExampleFactory::emptyHealthInsuranceValue());
}

std::string HealthInsuranceCompanyExampleFactory::existingHealthInsuranceValue() {
    return "BKK VBU_01012024_01.2024-12.2024";
}

HealthInsuranceCompany HealthInsuranceCompanyExampleFactory::existingHealthInsurance() {
    return HealthInsuranceCompany(HealthInsuranceCompanyExampleFactory::existingHealthInsuranceValue());
}

std::string HealthInsuranceCompanyExampleFactory::invalidHealthInsuranceValue() {
    return "München_01012024_01.2024-12.2024";
}

HealthInsuranceCompany HealthInsuranceCompanyExampleFactory::invalidHealthInsurance() {
    return HealthInsuranceCompany(HealthInsuranceCompanyExampleFactory::invalidHealthInsuranceValue());
}
