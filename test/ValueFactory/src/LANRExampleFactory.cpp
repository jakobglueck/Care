//
// Created by Jakob Glück on 08.07.24.
//

#include "include/LANRExampleFactory.h"

std::string LANRExampleFactory::allowedLanrValue() {
    return "2343546";
}

LANR LANRExampleFactory::allowedLanr() {
    return LANR(LANRExampleFactory::allowedLanrValue());
}

std::string LANRExampleFactory::invalidLanrValue1() {
    return "1111546";
}

LANR LANRExampleFactory::invalidLanr1() {
    return LANR(LANRExampleFactory::invalidLanrValue1());
}

std::string LANRExampleFactory::invalidLanrValue2() {
    return "2222221";
}

LANR LANRExampleFactory::invalidLanr2() {
    return LANR(LANRExampleFactory::invalidLanrValue2());
}

std::string LANRExampleFactory::invalidLanrValue3() {
    return "3333330";
}

LANR LANRExampleFactory::invalidLanr3() {
    return LANR(LANRExampleFactory::invalidLanrValue3());
}

std::string LANRExampleFactory::invalidLanrValue3Between() {
    return "13333300";
}

LANR LANRExampleFactory::invalidLanr3Between() {
    return LANR(LANRExampleFactory::invalidLanrValue3Between());
}

std::string LANRExampleFactory::shortLanrValue() {
    return "1333";
}

LANR LANRExampleFactory::shortLanr() {
    return LANR(LANRExampleFactory::shortLanrValue());
}

std::string LANRExampleFactory::longLanrValue() {
    return "1332343323";
}

LANR LANRExampleFactory::longLanr() {
    return LANR(LANRExampleFactory::longLanrValue());
}

std::string LANRExampleFactory::letterLanrValue() {
    return "Test";
}

LANR LANRExampleFactory::letterLanr() {
    return LANR(LANRExampleFactory::letterLanrValue());
}