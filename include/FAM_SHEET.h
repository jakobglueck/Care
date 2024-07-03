//
// Created by Jakob Glück on 03.07.24.
//

#pragma once

#include "include.h"
#include "Verordnung.h"

class FAM{
public:
    FAM(std::vector<Prescription> database);
    FAM();

    void setDatabase(std::vector<Prescription>& database);
    void setApprovedData(std::vector<Prescription>& approvedData);
    void setUnapprovedData(std::vector<Prescription>& unapprovedData);

    std::vector<Prescription> getDatabase();
    std::vector<Prescription> getApprovedData();
    std::vector<Prescription> getUnapprovedData();


private:


    std::vector<Prescription> database;
    std::vector<Prescription> approvedData;
    std::vector<Prescription> unapprovedData;
};
