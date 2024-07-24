//
// Created by Jakob Glück on 12.07.24.
//

#pragma once

#include "include.h"
#include "FAM_SHEET.h"
#include "xlnt/xlnt.hpp"
#undef BLANK_CELL
#include "/Users/jakobgluck/Desktop/workspace/C++/Carenoble/KrankenkassenDatenmanagment/build/_deps/libxlsxwriter-src/include/xlsxwriter.h"

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