//
// Created by Jakob Glück on 30.05.24.
//
#include "ArztOrt.h"
#include "ArztPostleitzahl.h"
#include "ArztStraße.h"
# include <iostream>

class Address{
public:
    Address(City& city, PostalCode& postalCode,StreetName& streetName);

    void setCity(City& city);
    void setPostalCode(PostalCode& postalCode);
    void setStreetName(StreetName& streetName);

    City getCity();
    PostalCode getPostalCode();
    StreetName getStreetName();

private:
    City city;
    PostalCode postalCode;
    StreetName streetName;
};