//
// Created by Jakob Glück on 10.07.24.
//

#include "include/KV_BezirkExampleFactory.h"

std::string KV_DistrictsExampleFactory::normalKV_DistrictValue() {
    return "Bayern";
}

KV_Districts KV_DistrictsExampleFactory::normalKV_District() {
    return KV_Districts(KV_DistrictsExampleFactory::normalKV_DistrictValue(), "23424");
}

std::string KV_DistrictsExampleFactory::unknownKV_DistrictValue() {
    return "Paris";
}

KV_Districts KV_DistrictsExampleFactory::unknownKV_District() {
    return KV_Districts(KV_DistrictsExampleFactory::unknownKV_DistrictValue(),"");
}

std::string KV_DistrictsExampleFactory::KV_DistrictWithPostalCodeValue() {
    return "Postdam";
}

KV_Districts KV_DistrictsExampleFactory::KV_DistrictWithPostalCode() {
    KV_Districts tempKV_Districts = KV_Districts(KV_DistrictsExampleFactory::KV_DistrictWithPostalCodeValue(),"14467");
    return tempKV_Districts;
}