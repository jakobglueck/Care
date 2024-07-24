//
// Created by Jakob Glück on 14.07.24.
//

#include "gtest/gtest.h"
#include "Compiler_Excel.h"

TEST(CompilerTest, ExcelTest){
    Compiler compiler = Compiler("AOK Bayern_01012024_01.24-12.24.xlsx");
    EXPECT_TRUE(true);
}

TEST(ExcelTest, FileExists) {
    std::string excelFilePath = "/Users/jakobgluck/Desktop/workspace/test.xlsx";  // Relativer Pfad zum Arbeitsverzeichnis des Tests

    std::ifstream file(excelFilePath);
    ASSERT_TRUE(file.good()) << "Die Excel-Datei konnte nicht gefunden werden: " << excelFilePath;
}