//
// Created by Jakob Glück on 08.07.24.
//

#pragma once

#include "LANR.h"

class LANRExampleFactory{
public:
    static std::string allowedLanrValue();
    static LANR allowedLanr();

    static std::string invalidLanrValue1();
    static LANR invalidLanr1();

    static std::string invalidLanrValue2();
    static LANR invalidLanr2();

    static std::string invalidLanrValue3();
    static LANR invalidLanr3();

    static std::string invalidLanrValue3Between();
    static LANR invalidLanr3Between();

    static std::string shortLanrValue();
    static LANR shortLanr();

    static std::string longLanrValue();
    static LANR longLanr();

    static std::string letterLanrValue();
    static LANR letterLanr();

};