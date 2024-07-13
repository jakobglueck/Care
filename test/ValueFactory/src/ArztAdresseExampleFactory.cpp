//
// Created by Jakob Glück on 08.07.24.
//

#include "include/ArztAdresseExampleFactory.h"

City AddressExampleFactory::normalCity() {
    City tempCity = City("Naumburg");
    return tempCity;
}

PostalCode AddressExampleFactory::normalPostalCode() {
    PostalCode tempPostalCode = PostalCode("06618");
    return tempPostalCode;
}

StreetName AddressExampleFactory::normalStreetName() {
    StreetName tempStreetName = StreetName("Hauptstraße 12");
    return tempStreetName;
}

Address AddressExampleFactory::NormalAddress() {
    Address tempAddress = Address(AddressExampleFactory::normalCity(),AddressExampleFactory::normalPostalCode(),AddressExampleFactory::normalStreetName());
    return tempAddress;
}