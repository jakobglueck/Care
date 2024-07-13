//
// Created by Jakob Glück on 05.07.24.
//

#pragma once
#include "Arzneimittel.h"

class PharmaceuticalExampleFactory {
public:
    static Price normalPharmaceuticalPrice();
    static std::string normalPharmaceuticalPZN();
    static std::string normalPharmaceuticalName();
    static  Pharmaceutical normalPharmaceutical();

    static std::string normalPharmaceuticalNameWithCAPS();
    static  Pharmaceutical normalPharmaceuticalWithCAPS();

    static Price normalPharmaceuticalIHPEPrice();
    static std::string normalPharmaceuticalIHPE_PZN();
    static std::string normalPharmaceuticalIHPEName();
    static  Pharmaceutical normalPharmaceuticalIHPE();

    static Price normalPharmaceuticalIHPEPriceWithWrongAmount();
    static  Pharmaceutical normalPharmaceuticalIHPE_WithWrongAmount();

    static Price normalPharmaceuticalIHPEPriceWithWrongPrice();
    static  Pharmaceutical normalPharmaceuticalIHPE_WithWrongPrice();

};