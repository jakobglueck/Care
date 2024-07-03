//
// Created by Jakob Glück on 25.06.24.
//

#include "KV_Bezirk.h"

KV_Districts::KV_Districts(std::string &kvValue) {
    this->setNumberValue(this->StringConverterInEnumValue(kvValue));
    this->setValue(this->EnumConverterInStringValue(this->numberValue));
}

KV_Districts::KV_Districts() {}

void KV_Districts::setValue(std::string kvValue) {
    this->kvValue = kvValue;
}

void KV_Districts::setNumberValue(Districts::FederalStates numberValue) {
    this->numberValue = numberValue;
}

std::string KV_Districts::getValue() {
    return this->kvValue;
}

Districts::FederalStates KV_Districts::getNumberValue() {
    return this->numberValue;
}

bool KV_Districts::isSet(KV_Districts kvDistricts) {
    return this->getValue() == kvDistricts.getValue() && this->getNumberValue() ==  kvDistricts.getNumberValue();
}

Districts::FederalStates KV_Districts::parsePDFAndGetKV(const std::string& cityName) {
    std::string pdfPath = "PLZ_to_KV.pdf";
    auto doc = poppler::document::load_from_file(pdfPath);
    if (!doc) {
        std::cerr << "Error loading PDF file." << std::endl;
        return Districts::Unknown;
    }

    std::string lowercaseCity = cityName;
    std::transform(lowercaseCity.begin(), lowercaseCity.end(), lowercaseCity.begin(), ::tolower);

    for (int i = 0; i < doc->pages(); ++i) {
        auto page = doc->create_page(i);
        if (!page) continue;

        // Convert text to std::string
        auto utext = page->text();
        std::string text(utext.begin(), utext.end());

        std::istringstream iss(text);
        std::string line;
        while (std::getline(iss, line)) {
            std::string lowercaseLine = line;
            std::transform(lowercaseLine.begin(), lowercaseLine.end(), lowercaseLine.begin(), ::tolower);
            if (lowercaseLine.find(lowercaseCity) != std::string::npos) {

                if (line.find("Baden-Württemberg") != std::string::npos) return Districts::Baden_Württemberg;
                if (line.find("Bayern") != std::string::npos) return Districts::Bayern;
                if (line.find("Berlin") != std::string::npos) return Districts::Berlin;
                if (line.find("Brandenburg") != std::string::npos) return Districts::Brandenburg;
                if (line.find("Bremen") != std::string::npos) return Districts::Bremen;
                if (line.find("Hamburg") != std::string::npos) return Districts::Hamburg;
                if (line.find("Hessen") != std::string::npos) return Districts::Hessen;
                if (line.find("Mecklenburg-Vorpommern") != std::string::npos) return Districts::Mecklenburg_Vorpommern;
                if (line.find("Niedersachsen") != std::string::npos) return Districts::Niedersachsen;
                if (line.find("Nordrhein") != std::string::npos) return Districts::Nordrhein;
                if (line.find("Rheinland-Pfalz") != std::string::npos) return Districts::Rheinland_Pfalz;
                if (line.find("Saarland") != std::string::npos) return Districts::Saarland;
                if (line.find("Sachsen") != std::string::npos) return Districts::Sachsen;
                if (line.find("Sachsen-Anhalt") != std::string::npos) return Districts::Sachsen_Anhalt;
                if (line.find("Schleswig-Holstein") != std::string::npos) return Districts::Schleswig_Holstein;
                if (line.find("Thüringen") != std::string::npos) return Districts::Thüringen;
                if (line.find("Westfalen-Lippe") != std::string::npos) return Districts::Westfallen_Lippe;
            }
        }
    }
    return Districts::Unknown;
}


Districts::FederalStates KV_Districts::StringConverterInEnumValue(std::string& kvValue) {
    static const std::unordered_map<std::string, Districts::FederalStates> stringToEnumMap = {
            {"baden_württemberg", Districts::Baden_Württemberg},
            {"bayern", Districts::Bayern},
            {"berlin", Districts::Berlin},
            {"brandenburg", Districts::Brandenburg},
            {"bremen", Districts::Bremen},
            {"hamburg", Districts::Hamburg},
            {"hessen", Districts::Hessen},
            {"mecklenburg_vorpommern", Districts::Mecklenburg_Vorpommern},
            {"niedersachsen", Districts::Niedersachsen},
            {"nordrhein", Districts::Nordrhein},
            {"rheinland_pfalz", Districts::Rheinland_Pfalz},
            {"saarland", Districts::Saarland},
            {"sachsen", Districts::Sachsen},
            {"sachsen_anhalt", Districts::Sachsen_Anhalt},
            {"schleswig_holstein", Districts::Schleswig_Holstein},
            {"thüringen", Districts::Thüringen},
            {"westfallen_lippe", Districts::Westfallen_Lippe}
    };

    std::string kvValueLower = kvValue;
    std::transform(kvValueLower.begin(), kvValueLower.end(), kvValueLower.begin(), ::tolower);

    auto it = stringToEnumMap.find(kvValueLower);
    if (it != stringToEnumMap.end()) {
        return it->second;
    }

    return parsePDFAndGetKV(kvValue);
}

std::string KV_Districts::EnumConverterInStringValue(Districts::FederalStates& numberValue) {
    static const std::unordered_map<Districts::FederalStates, std::string> enumToStringMap = {
            {Districts::Baden_Württemberg, "1"},
            {Districts::Bayern, "2"},
            {Districts::Berlin, "3"},
            {Districts::Brandenburg, "4"},
            {Districts::Bremen, "5"},
            {Districts::Hamburg, "6"},
            {Districts::Hessen, "7"},
            {Districts::Mecklenburg_Vorpommern, "8"},
            {Districts::Niedersachsen, "9"},
            {Districts::Nordrhein, "10"},
            {Districts::Rheinland_Pfalz, "11"},
            {Districts::Saarland, "12"},
            {Districts::Sachsen, "13"},
            {Districts::Sachsen_Anhalt, "14"},
            {Districts::Schleswig_Holstein, "15"},
            {Districts::Thüringen, "16"},
            {Districts::Westfallen_Lippe, "17"},
            {Districts::Unknown, "0"}
    };

    auto it = enumToStringMap.find(numberValue);
    if (it != enumToStringMap.end()) {
        return it->second;
    } else {
        return (std::string)"";
    }
}

bool KV_Districts::isEqual(KV_Districts &kvDistricts) {
    return this->numberValue == kvDistricts.numberValue;
}