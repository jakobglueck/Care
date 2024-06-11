//
// Created by Jakob Glück on 13.05.24.
//
#pragma once

#include "Arztname.h"

class ArztnameExampleFactory {
public:

    static std::string normalVorname();
    static std::string normalNachname();

    static std::string shortVorname();
    static std::string shortNachname();

    static std::string longVorname();
    static std::string longNachname();

    static std::string doubleVorname();
    static std::string doubleNachname();

    static std::string tripleVorname();
    static std::string tripleNachname();

    static std::string validNumberVorname();
    static std::string validNumberNachname();

    static std::string emtpyVorname();
    static std::string emtpyNachname();

    static std::string invalidNumberVorname1();
    static std::string invalidNumberNachname1();

    static std::string invalidNumberVorname2();
    static std::string invalidNumberNachname2();

    static std::string invalidNumberVorname3();
    static std::string invalidNumberNachname3();

    static std::string invalidNumberVorname4();
    static std::string invalidNumberNachname4();

    static Arztname normalName();
    static Arztname shortName();
    static Arztname longName();
    static Arztname doubleName();
    static Arztname tripleName();
    static Arztname validNumberName();
    static Arztname emtpyName();
    static Arztname invalidNumberName1();
    static Arztname invalidNumberName2();
    static Arztname invalidNumberName3();
    static Arztname invalidNumberName4();
};

