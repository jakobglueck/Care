//
// Created by Jakob Glück on 03.06.24.
//

#pragma once

#include "include.h"

class VOID {
public:
    VOID(std::string &vo_id);
    VOID();

    void setVOID(const std::string &vo_id);
    std::string getVOID() const;

    bool isSet(const std::string &vo_id) const;
    bool isEqual(VOID& avoid);

private:
    std::string vo_id;
};