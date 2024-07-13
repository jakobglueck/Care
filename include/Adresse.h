//
// Created by Jakob Glück on 30.05.24.
//

#pragma once

#include "include.h"
#include "ArztOrt.h"
#include "ArztPostleitzahl.h"
#include "ArztStraße.h"


class Address{
public:
    Address(City city, PostalCode postalCode,StreetName streetName);
    Address();

    void setCity(City city);
    void setPostalCode(PostalCode postalCode);
    void setStreetName(StreetName streetName);

    City getCity();
    PostalCode getPostalCode();
    StreetName getStreetName();

    bool isEqual(Address& address);

private:
    City city;
    PostalCode postalCode;
    StreetName streetName;
};