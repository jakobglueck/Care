//
// Created by Jakob Glück on 08.07.24.
//

#include "include/ArztStraßeExampleFactory.h"

std::string StreetExampleFactory::normalStreetName() {
    return "Gartenweg 3";
}

StreetName StreetExampleFactory::normalStreet() {
    return StreetName(StreetExampleFactory::normalStreetName());
}

std::string StreetExampleFactory::longStreetName() {
    return "Hinter der Großen Mauer 123";
}

StreetName StreetExampleFactory::longStreet() {
    return  StreetName(StreetExampleFactory::longStreetName());
}

std::string StreetExampleFactory::streetNameWithStraßeShortcut() {
    return "Bahnhofstraße 12";
}

StreetName StreetExampleFactory::streetNameWithStraße() {
    return StreetName(StreetExampleFactory::streetNameWithStraßeShortcut() );
}

std::string StreetExampleFactory::streetNameWithStrasseShortcut() {
    return "Schulstrasse 22";
}

StreetName StreetExampleFactory::streetNameWithStrasse() {
    return StreetName(StreetExampleFactory::streetNameWithStrasseShortcut() );
}

std::string StreetExampleFactory::streetNameWithInvalidValue() {
    return "1294835";
}

StreetName StreetExampleFactory::streetNameWithInvalid() {
    return StreetName(StreetExampleFactory::streetNameWithInvalidValue());
}