//
// Created by Jakob Glück on 09.07.24.
//

#pragma once

#include "BSNR.h"

class BsNrExampleFactory{
public:
    static std::string normalBsNrValue();
    static BSNR normalBsNr();

    static std::string longBsNrValue();
    static BSNR longBsNr();

    static std::string invalidShortBsNrValue();
    static BSNR invalidShortBsNr();

    static std::string invalid3BsNrValue();
    static BSNR invalid3BsNr();

    static std::string letterBsNrValue();
    static BSNR letterBsNr();

    static std::string invalidStartingNullBsNrValue();
    static BSNR invalidStartingNullBsNr();

};
