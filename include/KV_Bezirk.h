//
// Created by Jakob Glück on 25.06.24.
//

#pragma once

#include "/opt/homebrew/Cellar/poppler/24.04.0/include/poppler/cpp/poppler-document.h"
#include "/opt/homebrew/Cellar/poppler/24.04.0/include/poppler/cpp/poppler-page.h"

#include "include.h"

namespace Districts{
    enum FederalStates{
        Baden_Württemberg,
        Bayern,
        Berlin,
        Brandenburg,
        Bremen,
        Hamburg,
        Hessen,
        Mecklenburg_Vorpommern,
        Niedersachsen,
        Nordrhein,
        Rheinland_Pfalz,
        Saarland,
        Sachsen,
        Sachsen_Anhalt,
        Schleswig_Holstein,
        Thüringen,
        Westfallen_Lippe,
        Unknown
    };
}

class KV_Districts{
public:
    KV_Districts(std::string kvValue, std::string postalCode);
    KV_Districts();

    void setValue(std::string kvValue);
    void setNumberValue(Districts::FederalStates numberValue);
    std::string getValue();
    Districts::FederalStates getNumberValue();

    bool isSet(KV_Districts kvDistricts);
    bool isEqual(KV_Districts& kvDistricts);

    Districts::FederalStates parsePDFAndGetKV(std::string postalcode);

private:
    Districts::FederalStates StringConverterInEnumValue(std::string& kvValue, std::string& postalCode);
    std::string EnumConverterInStringValue(Districts::FederalStates& numberValue);

    Districts::FederalStates numberValue;
    std::string kvValue;
};