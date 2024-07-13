//
// Created by Jakob Glück on 10.07.24.
//

#include "include/VersichertenpsyeudonymExampleFactory.h"

std::string InsuredPseudonymExampleFactory::normalInsuredPseudonymValue() {
    return "324356";
}

InsuredPseudonym InsuredPseudonymExampleFactory::normalInsuredPseudonym() {
    return InsuredPseudonym(InsuredPseudonymExampleFactory::normalInsuredPseudonymValue());
}

std::string InsuredPseudonymExampleFactory::emptyInsuredPseudonymValue() {
    return "";
}

InsuredPseudonym InsuredPseudonymExampleFactory::emptyInsuredPseudonym() {
    return InsuredPseudonym(InsuredPseudonymExampleFactory::emptyInsuredPseudonymValue());
}

std::string InsuredPseudonymExampleFactory::emptyInsuredPseudonymCheckIsSetMethod() {
    return "#";
}

InsuredPseudonym InsuredPseudonymExampleFactory::CheckIsSetMethod() {
    return InsuredPseudonym(InsuredPseudonymExampleFactory::emptyInsuredPseudonymCheckIsSetMethod());
}