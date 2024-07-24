//
// Created by Jakob Glück on 02.07.24.
//

#include "Fachgruppen_Bezeichnung.h"

MedicalSpecialty::MedicalSpecialty(std::string medicalSpecialty) {
    if (this->isValidMedicalSpecialty(medicalSpecialty)) {
        this->setMedicalSpecialty(medicalSpecialty);
    } else {
        this->setMedicalSpecialty(this->correctMedicalSpecialty(medicalSpecialty));
    }
}

MedicalSpecialty::MedicalSpecialty() {}

void MedicalSpecialty::setMedicalSpecialty(std::string medicalSpecialty) {
    medicalSpecialty = this->trimSpaces(medicalSpecialty);

    medicalSpecialty = this->removeExtraSpaces(medicalSpecialty);

    this->medicalSpecialty = medicalSpecialty;
}

std::string MedicalSpecialty::getMedicalSpecialty() {
    return this->medicalSpecialty;
}

bool MedicalSpecialty::isValidMedicalSpecialty(std::string medicalSpecialty) {
    for (char c : medicalSpecialty) {
        if (isdigit(c)) {
            return false;
        }
    }

    std::vector<std::string> invalidSubstrings = this->keywords();

    for (const std::string& substr : invalidSubstrings) {
        if (medicalSpecialty.find(substr) != std::string::npos) {
            return false;
        }
    }

    return true;
}

std::string MedicalSpecialty::removeSubstrings(std::string str, std::vector<std::string> substrings) {
    for (const std::string& substr : substrings) {
        size_t pos;
        while ((pos = str.find(substr)) != std::string::npos) {
            str.erase(pos, substr.length());
        }
    }
    return str;
}

std::string MedicalSpecialty::correctMedicalSpecialty(std::string medicalSpecialty) {
    if(this->isNumber(medicalSpecialty)){
        return "";
    }
    std::vector<std::string> invalidSubstrings = this->keywords();

    medicalSpecialty = this->removeSubstrings(medicalSpecialty, invalidSubstrings);

    medicalSpecialty = this->trimSpaces(medicalSpecialty);

    medicalSpecialty = this->removeExtraSpaces(medicalSpecialty);

    return medicalSpecialty;
}

bool MedicalSpecialty::isEqual(MedicalSpecialty& medicalSpecialty) {
    return this->medicalSpecialty == medicalSpecialty.medicalSpecialty;
}

std::vector<std::string> MedicalSpecialty::keywords() {
    return {"(Facharzt)", "(Hausarzt)", "Hausarzt", "Facharzt",
            "Praktischer Arzt / Hausarzt","F: ","0","unbekannt","keine Angaben",
            "Zur freien Verfügung für die KVen (Notfallärzte etc.)",
            "Zur freien Verfügung für die KVen (Notfallärzte etc)",
            "Zur freien Verfügung für die KVen","Sonstige Ärzte","00","k.A.",
            "XXX","NULL","nicht referenziert",
            "KV-interne Kennzeichnung, z.B. Notfallärzte",
            "Nicht zugeordnet","ungültiger Wert","zur freien Verfügung",
            "ungültige Facharztgruppe","(SP)","KV-interne Vergabe"," / "};
}

std::string MedicalSpecialty::removeExtraSpaces(std::string str) {
    std::istringstream iss(str);
    std::string result, word;
    bool firstWord = true;

    while (iss >> word) {
        if (firstWord) {
            result = word;
            firstWord = false;
        } else {
            result += " " + word;
        }
    }

    return result;
}

std::string MedicalSpecialty::trimSpaces(std::string str) {
    str.erase(str.find_last_not_of(" \n\r\t") + 1);
    str.erase(0, str.find_first_not_of(" \n\r\t"));
    return str;
}

bool MedicalSpecialty::isNumber(std::string& medicalSpecialty) {
    int count = 0;
    for (char const &c : medicalSpecialty) {
        if (std::isdigit(c)) {
            count++;
            if (count > 3) {
                return true;
            }
        } else {
            count = 0;
        }
    }
    return false;
}