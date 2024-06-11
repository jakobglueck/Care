//
// Created by Jakob Glück on 06.06.24.
//

#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>


namespace HealthInsuranceCompanyTypes{
    enum types{
        AOK_SACHSEN_ANHALT,
        AOK_PLUS,
        AOK_BAYERN,
        AUDI_BKK,
        BARMER,
        BKK_AKZO_NOBEL_BAYERN,
        BKK_BAHN,
        BKK_BOSCH,
        BKK_CONTINENTALE,
        BKK_DEBEKA,
        BKK_DUERKOPP_ADLER,
        BKK_ENERGIE,
        BKK_EUREGIO,
        BKK_EXKLUSIV,
        BKK_FREUDENBERG,
        BKK_GILDEMEISTER_SEIDENSTICKER,
        BKK_HEIMAT,
        BKK_HERKULES,
        BKK_MAHLE,
        BKK_MHPLUS,
        BKK_MIELE,
        BKK_VBU,
        BKK_PFALZ,
        BKK_PRONOVA,
        BKK_PROVITA,
        BKK_SALUS,
        BKK_SECURVITA,
        BKK_SIEMENS,
        BKK_SKD,
        BKK_VDN,
        BKK_VERBUNDPLUS,
        BKK_VIACTIV,
        BKK_VIVIDA,
        BKK_WERRA_MEISSNER,
        BKK_ZF_PARTNER,
        BKK24,
        HEK,
        IKK_CLASSIC,
        KAUFMANNISCHE_KRANKENKASSE,
        KNAPPSCHAFT,
        MOBILE_KRANKENKASSE,
        TECHNIKER_KRANKENKASSE,
        Unknown
    };
}

class HealthInsuranceCompany{
public:
    HealthInsuranceCompany(std::string& healthInsuranceCompany);
    HealthInsuranceCompany();

    void setHealthInsuranceCompany(const HealthInsuranceCompanyTypes::types& healthInsuranceCompany);
    HealthInsuranceCompanyTypes::types getHealthInsuranceCompany();
    std::string enumToStringConverter(HealthInsuranceCompanyTypes::types& type);

     bool isSet(HealthInsuranceCompanyTypes::types& healthInsuranceCompany);
private:
    std::string findHealthInsuranceCompany(const std::string& pfad);
    HealthInsuranceCompanyTypes::types stringToEnumConverter( const std::string& healthInsuranceCompany);
    HealthInsuranceCompanyTypes::types healthInsuranceCompany;
};