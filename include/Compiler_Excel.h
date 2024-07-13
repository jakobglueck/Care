//
// Created by Jakob Glück on 12.07.24.
//

#pragma once

#include "include.h"
#include "FAM_SHEET.h"
#include "xls.h"
#undef BLANK_CELL
#include "xlsxwriter.h"
#undef BLANK_CELL

class Compiler{
public:
    Compiler(std::string pfad);
    Compiler();

    void readFAMData(std::string pfad);
    void readTMData(std::string pfad);

    void writeFAMData(std::string pfad);
    void writeTM();
private:
    FAM fam;
};