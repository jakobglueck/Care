//
// Created by Jakob Glück on 06.06.24.
//

#include "Krankenkasse.h"

HealthInsuranceCompany::HealthInsuranceCompany(std::string& healthInsuranceCompany) {
    this->setHealthInsuranceCompany(this->stringToEnumConverter(this->findHealthInsuranceCompany(healthInsuranceCompany)));
}

HealthInsuranceCompany::HealthInsuranceCompany() {}

void HealthInsuranceCompany::setHealthInsuranceCompany(const HealthInsuranceCompanyTypes::types &healthInsuranceCompany) {
    this->healthInsuranceCompany = healthInsuranceCompany;
}

HealthInsuranceCompanyTypes::types HealthInsuranceCompany::getHealthInsuranceCompany() {
    return this->healthInsuranceCompany;
}

std::string HealthInsuranceCompany::enumToStringConverter(HealthInsuranceCompanyTypes::types &type) {
    switch(type) {
        case HealthInsuranceCompanyTypes::AOK_SACHSEN_ANHALT: return "AOK SA";
        case HealthInsuranceCompanyTypes::AOK_PLUS: return "AOK Plus";
        case HealthInsuranceCompanyTypes::AOK_BAYERN: return "AOK Bayern";
        case HealthInsuranceCompanyTypes::AUDI_BKK: return "Audi BKK";
        case HealthInsuranceCompanyTypes::BARMER: return "Barmer";
        case HealthInsuranceCompanyTypes::BKK_AKZO_NOBEL_BAYERN: return "BKK Akzo Nobel Bayern";
        case HealthInsuranceCompanyTypes::BKK_BAHN: return "BKK Bahn";
        case HealthInsuranceCompanyTypes::BKK_BOSCH: return "BKK Bosch";
        case HealthInsuranceCompanyTypes::BKK_CONTINENTALE: return "BKK Continentale";
        case HealthInsuranceCompanyTypes::BKK_DEBEKA: return "BKK Debeka";
        case HealthInsuranceCompanyTypes::BKK_DUERKOPP_ADLER: return "BKK Dürkopp Adler";
        case HealthInsuranceCompanyTypes::BKK_ENERGIE: return "BKK Energie";
        case HealthInsuranceCompanyTypes::BKK_EUREGIO: return "BKK Euregio";
        case HealthInsuranceCompanyTypes::BKK_EXKLUSIV: return "BKK Exklusiv";
        case HealthInsuranceCompanyTypes::BKK_FREUDENBERG: return "BKK Freudenberg";
        case HealthInsuranceCompanyTypes::BKK_GILDEMEISTER_SEIDENSTICKER: return "BKK Gildemeister Seidensticker";
        case HealthInsuranceCompanyTypes::BKK_HEIMAT: return "BKK Heimat";
        case HealthInsuranceCompanyTypes::BKK_HERKULES: return "BKK Herkules";
        case HealthInsuranceCompanyTypes::BKK_MAHLE: return "BKK Mahle";
        case HealthInsuranceCompanyTypes::BKK_MHPLUS: return "BKK mhplus";
        case HealthInsuranceCompanyTypes::BKK_MIELE: return "BKK Miele";
        case HealthInsuranceCompanyTypes::BKK_VBU: return "BKK VBU";
        case HealthInsuranceCompanyTypes::BKK_PFALZ: return "BKK Pfalz";
        case HealthInsuranceCompanyTypes::BKK_PRONOVA: return "BKK pronova";
        case HealthInsuranceCompanyTypes::BKK_PROVITA: return "BKK proVita";
        case HealthInsuranceCompanyTypes::BKK_SALUS: return "BKK Salus";
        case HealthInsuranceCompanyTypes::BKK_SECURVITA: return "BKK Securvita";
        case HealthInsuranceCompanyTypes::BKK_SIEMENS: return "BKK Siemens";
        case HealthInsuranceCompanyTypes::BKK_SKD: return "BKK SKD";
        case HealthInsuranceCompanyTypes::BKK_VDN: return "BKK VDN";
        case HealthInsuranceCompanyTypes::BKK_VERBUNDPLUS: return "BKK VerbundPlus";
        case HealthInsuranceCompanyTypes::BKK_VIACTIV: return "BKK Viactiv";
        case HealthInsuranceCompanyTypes::BKK_VIVIDA: return "BKK vivida";
        case HealthInsuranceCompanyTypes::BKK_WERRA_MEISSNER: return "BKK Werra Meissner";
        case HealthInsuranceCompanyTypes::BKK_ZF_PARTNER: return "BKK ZF & Partner";
        case HealthInsuranceCompanyTypes::BKK24: return "BKK24";
        case HealthInsuranceCompanyTypes::HEK: return "HEK";
        case HealthInsuranceCompanyTypes::IKK_CLASSIC: return "IKK classic";
        case HealthInsuranceCompanyTypes::KAUFMANNISCHE_KRANKENKASSE: return "Kaufmännische Krankenkasse";
        case HealthInsuranceCompanyTypes::KNAPPSCHAFT: return "Knappschaft";
        case HealthInsuranceCompanyTypes::MOBILE_KRANKENKASSE: return "Mobile Krankenkasse";
        case HealthInsuranceCompanyTypes::TECHNIKER_KRANKENKASSE: return "Techniker Krankenkasse";
        default: return "Unknown";
    }
}

HealthInsuranceCompanyTypes::types HealthInsuranceCompany::stringToEnumConverter(const std::string &healthInsuranceCompany) {
    static const std::unordered_map<std::string, HealthInsuranceCompanyTypes::types> stringToEnum{
            {"AOK Sachsen Anhalt",             HealthInsuranceCompanyTypes::AOK_SACHSEN_ANHALT},
            {"AOK Plus",                       HealthInsuranceCompanyTypes::AOK_PLUS},
            {"AOK Bayern",                     HealthInsuranceCompanyTypes::AOK_BAYERN},
            {"Audi BKK",                       HealthInsuranceCompanyTypes::AUDI_BKK},
            {"Barmer",                         HealthInsuranceCompanyTypes::BARMER},
            {"BKK Akzo Nobel Bayern",          HealthInsuranceCompanyTypes::BKK_AKZO_NOBEL_BAYERN},
            {"BKK Bahn",                       HealthInsuranceCompanyTypes::BKK_BAHN},
            {"BKK Bosch",                      HealthInsuranceCompanyTypes::BKK_BOSCH},
            {"BKK Continentale",               HealthInsuranceCompanyTypes::BKK_CONTINENTALE},
            {"BKK Debeka",                     HealthInsuranceCompanyTypes::BKK_DEBEKA},
            {"BKK Dürkopp Adler",              HealthInsuranceCompanyTypes::BKK_DUERKOPP_ADLER},
            {"BKK Energie",                    HealthInsuranceCompanyTypes::BKK_ENERGIE},
            {"BKK Euregio",                    HealthInsuranceCompanyTypes::BKK_EUREGIO},
            {"BKK Exklusiv",                   HealthInsuranceCompanyTypes::BKK_EXKLUSIV},
            {"BKK Freudenberg",                HealthInsuranceCompanyTypes::BKK_FREUDENBERG},
            {"BKK Gildemeister Seidensticker", HealthInsuranceCompanyTypes::BKK_GILDEMEISTER_SEIDENSTICKER},
            {"BKK Heimat",                     HealthInsuranceCompanyTypes::BKK_HEIMAT},
            {"BKK Herkules",                   HealthInsuranceCompanyTypes::BKK_HERKULES},
            {"BKK Mahle",                      HealthInsuranceCompanyTypes::BKK_MAHLE},
            {"BKK mhplus",                     HealthInsuranceCompanyTypes::BKK_MHPLUS},
            {"BKK Miele",                      HealthInsuranceCompanyTypes::BKK_MIELE},
            {"BKK VBU",                        HealthInsuranceCompanyTypes::BKK_VBU},
            {"BKK Pfalz",                      HealthInsuranceCompanyTypes::BKK_PFALZ},
            {"BKK pronova",                    HealthInsuranceCompanyTypes::BKK_PRONOVA},
            {"BKK proVita",                    HealthInsuranceCompanyTypes::BKK_PROVITA},
            {"BKK Salus",                      HealthInsuranceCompanyTypes::BKK_SALUS},
            {"BKK Securvita",                  HealthInsuranceCompanyTypes::BKK_SECURVITA},
            {"BKK Siemens",                    HealthInsuranceCompanyTypes::BKK_SIEMENS},
            {"BKK SKD",                        HealthInsuranceCompanyTypes::BKK_SKD},
            {"BKK VDN",                        HealthInsuranceCompanyTypes::BKK_VDN},
            {"BKK VerbundPlus",                HealthInsuranceCompanyTypes::BKK_VERBUNDPLUS},
            {"BKK Viactiv",                    HealthInsuranceCompanyTypes::BKK_VIACTIV},
            {"BKK vivida",                     HealthInsuranceCompanyTypes::BKK_VIVIDA},
            {"BKK Werra Meissner",             HealthInsuranceCompanyTypes::BKK_WERRA_MEISSNER},
            {"BKK ZF & Partner",               HealthInsuranceCompanyTypes::BKK_ZF_PARTNER},
            {"BKK24",                          HealthInsuranceCompanyTypes::BKK24},
            {"HEK",                            HealthInsuranceCompanyTypes::HEK},
            {"IKK classic",                    HealthInsuranceCompanyTypes::IKK_CLASSIC},
            {"Kaufmännische Krankenkasse",     HealthInsuranceCompanyTypes::KAUFMANNISCHE_KRANKENKASSE},
            {"Knappschaft",                    HealthInsuranceCompanyTypes::KNAPPSCHAFT},
            {"Mobile Krankenkasse",            HealthInsuranceCompanyTypes::MOBILE_KRANKENKASSE},
            {"Techniker Krankenkasse",         HealthInsuranceCompanyTypes::TECHNIKER_KRANKENKASSE},
            {"Unknown",         HealthInsuranceCompanyTypes::Unknown},
    };
    auto it = stringToEnum.find(healthInsuranceCompany);
    if (it != stringToEnum.end()) {
        return it->second;
    } else {
        return HealthInsuranceCompanyTypes::Unknown;
    }
}

std::string HealthInsuranceCompany::findHealthInsuranceCompany(const std::string &pfad) {

    size_t firstUnderscore = pfad.find('_');
    if (firstUnderscore == std::string::npos) {
        throw std::invalid_argument("Invalid file path format: " + pfad);
    }
    std::string company = pfad.substr(0, firstUnderscore);

    std::transform(company.begin(), company.end(), company.begin(), ::toupper);
    static const std::unordered_map<std::string, std::string> knownCompanies {
            {"AOK SACHSEN ANHALT", "AOK Sachsen Anhalt"},
            {"AOK PLUS", "AOK Plus"},
            {"AOK BAYERN", "AOK Bayern"},
            {"AUDI BKK", "Audi BKK"},
            {"BARMER", "Barmer"},
            {"BKK AKZO NOBEL BAYERN", "BKK Akzo Nobel Bayern"},
            {"BKK BAHN", "BKK Bahn"},
            {"BKK BOSCH", "BKK Bosch"},
            {"BKK CONTINENTALE", "BKK Continentale"},
            {"BKK DEBEKA", "BKK Debeka"},
            {"BKK DUERKOPP ADLER", "BKK Dürkopp Adler"},
            {"BKK ENERGIE", "BKK Energie"},
            {"BKK EUREGIO", "BKK Euregio"},
            {"BKK EXKLUSIV", "BKK Exklusiv"},
            {"BKK FREUDENBERG", "BKK Freudenberg"},
            {"BKK GILDEMEISTER SEIDENSTICKER", "BKK Gildemeister Seidensticker"},
            {"BKK HEIMAT", "BKK Heimat"},
            {"BKK HERKULES", "BKK Herkules"},
            {"BKK MAHLE", "BKK Mahle"},
            {"BKK MHPLUS", "BKK mhplus"},
            {"BKK MIELE", "BKK Miele"},
            {"BKK VBU", "BKK VBU (jetzt mkk - meine Krankenkasse)"},
            {"BKK PFALZ", "BKK Pfalz"},
            {"BKK PRONOVA", "BKK pronova"},
            {"BKK PROVITA", "BKK proVita"},
            {"BKK SALUS", "BKK Salus"},
            {"BKK SECURVITA", "BKK Securvita"},
            {"BKK SIEMENS", "BKK Siemens"},
            {"BKK SKD", "BKK SKD"},
            {"BKK VDN", "BKK VDN"},
            {"BKK VERBUNDPLUS", "BKK VerbundPlus"},
            {"BKK VIACTIV", "BKK Viactiv"},
            {"BKK VIVIDA", "BKK vivida"},
            {"BKK WERRA MEISSNER", "BKK Werra Meissner"},
            {"BKK ZF PARTNER", "BKK ZF & Partner"},
            {"BKK24", "BKK24"},
            {"HEK", "HEK"},
            {"IKK CLASSIC", "IKK classic"},
            {"KAUFMANNISCHE KRANKENKASSE", "Kaufmännische Krankenkasse"},
            {"KNAPPSCHAFT", "Knappschaft"},
            {"MOBILE KRANKENKASSE", "Mobile Krankenkasse"},
            {"TECHNIKER KRANKENKASSE", "Techniker Krankenkasse"},
            {"Unknown", "Unknown"},
    };


    auto it = knownCompanies.find(company);
    if (it != knownCompanies.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Unknown health insurance company in file path: " + company);
    }
}

bool HealthInsuranceCompany::isSet() {
    if(this->healthInsuranceCompany == HealthInsuranceCompanyTypes::types::Unknown){
        return false;
    }
    else{
        return true;
    }
}

bool HealthInsuranceCompany::isEqual(HealthInsuranceCompany &healthInsuranceCompany) {
    return this->healthInsuranceCompany ==  healthInsuranceCompany.healthInsuranceCompany;
}