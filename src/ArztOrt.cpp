//
// Created by Jakob Glück on 29.05.24.
//
#include "xls.h"
#include "ArztOrt.h"

City::City(std::string &cityName) {
    if(this->checkCityName(cityName)){
        this->setCityName(cityName);
    }
}

City::City() {}

void City::setCityName(std::string &cityName) {
    this->cityName = cityName;
}

std::string City::getCityName() {
    return this->cityName;
}

bool City::checkCityName(std::string &cityName) {

    if (std::regex_match(cityName, std::regex("[A-Za-z]"))) {
        return false;
    }
    if (std::regex_match(cityName, std::regex("[0-9]+"))) {
        return false;
    }
    if(!std::regex_match(cityName,  std::regex("([A-Z][a-z]+(?:\s[a-z]+)*)"))){
        return false;
    }
    if(!this->findCityNameInExcel(this->converterStringToChar(cityName))){
        return false;
    }
    return true;
}

bool City::findCityNameInExcel(const char* cityName) {
    xls::xlsWorkBook* pWB;
    xls::xlsWorkSheet* pWS;

    pWB = xls::xls_open("germanCitys.xlsx", "UTF-8");
    if (!pWB) {
        std::cerr << "Could not open Excel file " << std::endl;
        return false;
    }
    pWS = xls::xls_getWorkSheet(pWB, 0);
    if (!pWS) {
        std::cerr << "Could not open Excel sheet" << std::endl;
        xls::xls_close(pWB);
        return false;
    }
    for (int row = 1; row <= pWS->rows.lastrow; ++row) {
        xls::xlsCell* cell = xls::xls_cell(pWS, row, 1); // Column B (0-indexed)
        if (cell && cell->str && std::strcmp(cell->str, cityName) == 0) {
            xls::xls_close(pWB);
            return true;
        }
    }
    xls::xls_close(pWB);
    return false;
}

const char* City::converterStringToChar(const std::string &cityName) {
    return cityName.c_str();
}