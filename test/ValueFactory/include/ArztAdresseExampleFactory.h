//
// Created by Jakob Glück on 08.07.24.
//

#pragma once

#include "Adresse.h"

class AddressExampleFactory{
public:
    static City normalCity();
    static PostalCode normalPostalCode();
    static StreetName normalStreetName();
    static Address NormalAddress();
};
