//
// Created by Jakob Glück on 25.06.24.
//

#pragma once

#include "include.h"

class BSNR{
public:
    BSNR(std::string& bsnr);
    BSNR();

    void setBSNR(std::string& bsnr);
    std::string getBSNR();

    bool isEqual(BSNR& bsnr);

private:
    bool detectWrongBSNR(std::string& bsnr);
    std::string& convertWrongBSNR(std::string& bsnr);
    std::string bsnr;
};