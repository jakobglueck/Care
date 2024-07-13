//
// Created by Jakob Glück on 10.07.24.
//
#include "include/BetriebsbezeichnungExampleFactory.h"

std::string OperationalDesignationExampleFactory::normalOperationalDesignationValue() {
    return "MyCare";
}

OperationalDesignation OperationalDesignationExampleFactory::normalOperationalDesignation() {
    return OperationalDesignation(OperationalDesignationExampleFactory::normalOperationalDesignationValue());
}

std::string OperationalDesignationExampleFactory::invalidOperationalDesignationNumberValue() {
    return "1425663";
}

OperationalDesignation OperationalDesignationExampleFactory::invalidOperationalDesignationNumber() {
    return OperationalDesignation(OperationalDesignationExampleFactory::invalidOperationalDesignationNumberValue());
}

std::string OperationalDesignationExampleFactory::invalidOperationalDesignation_OHG_Value() {
    return "MyCare OHG";
}

OperationalDesignation OperationalDesignationExampleFactory::invalidOperationalDesignation_OHG() {
    return OperationalDesignation(OperationalDesignationExampleFactory::invalidOperationalDesignation_OHG_Value());
}

std::string OperationalDesignationExampleFactory::invalidOperationalDesignation_CoKG_Value() {
    return "MyCare & Co.KG";
}

OperationalDesignation OperationalDesignationExampleFactory::invalidOperationalDesignation_CoKG() {
    return OperationalDesignation(OperationalDesignationExampleFactory::invalidOperationalDesignation_CoKG_Value());
}

std::string OperationalDesignationExampleFactory::invalidOperationalDesignation_InSideOfTheValue_Value() {
    return "MyCare e.V. Team";
}

OperationalDesignation OperationalDesignationExampleFactory::invalidOperationalDesignation_InSideOfTheValue() {
    return OperationalDesignation(OperationalDesignationExampleFactory::invalidOperationalDesignation_InSideOfTheValue_Value());
}