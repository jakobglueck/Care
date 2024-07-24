//
// Created by Jakob Glück on 30.05.24.
//

#include "Adresse.h"

Address::Address(City city, PostalCode postalCode, StreetName streetName) {
    this->setCity(city);
    this->setPostalCode(postalCode);
    this->setStreetName(streetName);
}

Address::Address() {}

void Address::setStreetName(StreetName streetName) {
    this->streetName = streetName;
}

void Address::setPostalCode(PostalCode postalCode) {
    this->postalCode = postalCode;
}

void Address::setCity(City city) {
    this->city = city;
}

City Address::getCity() {
    return this->city;
}

PostalCode Address::getPostalCode() {
    return this->postalCode;
}

StreetName Address::getStreetName() {
    return this->streetName;
}

bool Address::isEqual(Address &address) {
    return this->streetName.isEqual(address.streetName) && this->postalCode.isEqual(address.postalCode) &&
    this->city.isEqual(address.city);
}