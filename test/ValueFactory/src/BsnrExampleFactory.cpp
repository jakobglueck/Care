//
// Created by Jakob Glück on 09.07.24.
//


#include "include/BsnrExampleFactory.h"

std::string BsNrExampleFactory::normalBsNrValue() {
    return "3245624";
}

BSNR BsNrExampleFactory::normalBsNr() {
    return BSNR(BsNrExampleFactory::normalBsNrValue());
}

std::string BsNrExampleFactory::longBsNrValue() {
    return "3245632435424";
}

BSNR BsNrExampleFactory::longBsNr() {
    return BSNR(BsNrExampleFactory::longBsNrValue());
}

std::string BsNrExampleFactory::invalidShortBsNrValue() {
    return "3245";
}

BSNR BsNrExampleFactory::invalidShortBsNr() {
    return BSNR(BsNrExampleFactory::invalidShortBsNrValue());
}

std::string BsNrExampleFactory::invalid3BsNrValue() {
    return "3333345";
}

BSNR BsNrExampleFactory::invalid3BsNr() {
    return BSNR(BsNrExampleFactory::invalid3BsNrValue());
}

std::string BsNrExampleFactory::letterBsNrValue() {
    return "Test";
}

BSNR BsNrExampleFactory::letterBsNr() {
    return BSNR(BsNrExampleFactory::letterBsNrValue());
}

std::string BsNrExampleFactory::invalidStartingNullBsNrValue() {
    return "0000121";
}

BSNR BsNrExampleFactory::invalidStartingNullBsNr() {
    return BSNR(BsNrExampleFactory::invalidStartingNullBsNrValue());
}

