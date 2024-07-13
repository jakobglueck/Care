//
// Created by Jakob Glück on 07.06.24.
//

#include "Versichertenpsyeudonym.h"

InsuredPseudonym::InsuredPseudonym(std::string insuredPseudonym) {
    this->setInsuredPseudonym(insuredPseudonym);
}

InsuredPseudonym::InsuredPseudonym() {}

void InsuredPseudonym::setInsuredPseudonym(std::string insuredPseudonym) {
    this->insuredPseudonym = insuredPseudonym;
}

std::string InsuredPseudonym::getInsuredPseudonym() {
    return this->insuredPseudonym;
}

bool InsuredPseudonym::isSet() {
    if(this->insuredPseudonym == "" || this->insuredPseudonym == "#" || this->insuredPseudonym == "#NV" ){
        return false;
    }
    else {
        return true;
    }
}

bool InsuredPseudonym::isEqual(InsuredPseudonym &insuredPseudonym) {
    return this->insuredPseudonym == insuredPseudonym.insuredPseudonym;
}