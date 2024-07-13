//
// Created by Jakob Glück on 10.07.24.
//

#pragma once
#include "Versichertenpsyeudonym.h"

class InsuredPseudonymExampleFactory{
public:
    static std::string normalInsuredPseudonymValue();
    static InsuredPseudonym normalInsuredPseudonym();

    static std::string emptyInsuredPseudonymValue();
    static InsuredPseudonym emptyInsuredPseudonym();

    static std::string emptyInsuredPseudonymCheckIsSetMethod();
    static InsuredPseudonym CheckIsSetMethod();

};