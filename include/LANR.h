//
// Created by Jakob Glück on 03.06.24.
//

#pragma once

#include "include.h"

class LANR {
public:
    LANR(std::string lanr);
    LANR();

    void setLANR(std::string lanr);
    void setTempLANR(std::string lanr);

    std::string getLANR();
    std::string getTempLANR();

    bool isEqual(LANR& lanr);

private:
    bool detectInvalidLANR( std::string& lanr);
    std::string removeLANR( std::string& lanr);

    std::string lanr;
    std::string templanr;
};