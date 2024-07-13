//
// Created by Jakob Glück on 10.07.24.
//

#pragma once

#include "KV_Bezirk.h"

class KV_DistrictsExampleFactory{
public:
    static std::string normalKV_DistrictValue();
    static KV_Districts normalKV_District();

    static std::string unknownKV_DistrictValue();
    static KV_Districts unknownKV_District();

    static std::string KV_DistrictWithPostalCodeValue();
    static KV_Districts KV_DistrictWithPostalCode();
};