//
// Created by Jakob Glück on 08.07.24.
//

#include "include/PostleitzahlExampleFactory.h"

std::string PostalCodeExampleFactory::normalPostalCodeValue() {
    return "06618";
}

PostalCode PostalCodeExampleFactory::normalPostalCode() {
    return PostalCode(PostalCodeExampleFactory::normalPostalCodeValue());
}

std::string PostalCodeExampleFactory::shortPostalCodeValue() {
    return "6618";
}

PostalCode PostalCodeExampleFactory::shortPostalCode() {
    return PostalCode(PostalCodeExampleFactory::shortPostalCodeValue() );
}

std::string PostalCodeExampleFactory::invalidPostalCodeValue() {
    return "12";
}

PostalCode PostalCodeExampleFactory::invalidPostalCode() {
    return PostalCode(PostalCodeExampleFactory::invalidPostalCodeValue() );
}