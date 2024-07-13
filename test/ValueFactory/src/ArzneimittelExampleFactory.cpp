//
// Created by Jakob Glück on 05.07.24.
//

#include "include/ArzneimittelExampleFactory.h"

Price PharmaceuticalExampleFactory::normalPharmaceuticalPrice(){
    Price tempPrice = Price(123.33,2);
    return tempPrice;
}

std::string PharmaceuticalExampleFactory::normalPharmaceuticalPZN(){
    return "11057753";
}

std::string PharmaceuticalExampleFactory::normalPharmaceuticalName() {
    return "Addaven Fresenius";
}

std::string PharmaceuticalExampleFactory::normalPharmaceuticalNameWithCAPS() {
    return "ADDAVEN FREseNIUS";
}

Pharmaceutical PharmaceuticalExampleFactory::normalPharmaceutical() {
    Pharmaceutical tempPharmaceutical = Pharmaceutical(PharmaceuticalExampleFactory::normalPharmaceuticalName(),
                                                   PharmaceuticalExampleFactory::normalPharmaceuticalPZN(),
                                                   PharmaceuticalExampleFactory::normalPharmaceuticalPrice());
    return tempPharmaceutical;
}

Pharmaceutical PharmaceuticalExampleFactory::normalPharmaceuticalWithCAPS() {
    Pharmaceutical tempPharmaceutical = Pharmaceutical(PharmaceuticalExampleFactory::normalPharmaceuticalNameWithCAPS(),
                                                       PharmaceuticalExampleFactory::normalPharmaceuticalPZN(),
                                                       PharmaceuticalExampleFactory::normalPharmaceuticalPrice());
    return tempPharmaceutical;
}


Price PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPrice(){
    Price tempPrice = Price(124.54,1);
    return tempPrice;
}

std::string PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_PZN(){
    return "09999100";
}

std::string PharmaceuticalExampleFactory::normalPharmaceuticalIHPEName(){
    return "Pseudonym";
}

Pharmaceutical PharmaceuticalExampleFactory::normalPharmaceuticalIHPE(){
    Pharmaceutical tempPharmaceutical = Pharmaceutical(PharmaceuticalExampleFactory::normalPharmaceuticalIHPEName(),
                                                       PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_PZN(),
                                                       PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPrice());
    return tempPharmaceutical;
}

Price PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPriceWithWrongAmount() {
    Price tempPrice = Price(122.32,2);
    return tempPrice;
}

Pharmaceutical PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_WithWrongAmount() {
    Pharmaceutical tempPharmaceutical = Pharmaceutical(PharmaceuticalExampleFactory::normalPharmaceuticalIHPEName(),
                                                       PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_PZN(),
                                                       PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPriceWithWrongAmount());
    return tempPharmaceutical;
}

Price PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPriceWithWrongPrice() {
    Price tempPrice = Price(65.00,2);
    return tempPrice;
}

Pharmaceutical PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_WithWrongPrice() {
    Pharmaceutical tempPharmaceutical = Pharmaceutical(PharmaceuticalExampleFactory::normalPharmaceuticalIHPEName(),
                                                       PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_PZN(),
                                                       PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPriceWithWrongPrice());
    return tempPharmaceutical;
}
