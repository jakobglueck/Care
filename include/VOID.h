//
// Created by Jakob Glück on 03.06.24.
//

#pragma once

#include "include.h"

class VOID {
public:
    VOID(std::string vo_id);
    VOID();

    void setVOID(std::string vo_id);
    std::string getVOID();

    bool isSet(std::string vo_id);
    bool isEqual(VOID& avoid);

private:
    std::string vo_id;
};