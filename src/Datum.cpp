//
// Created by Jakob Glück on 30.05.24.
//

#include "Datum.h"

Date::Date(){}

Date::Date(std::string &date, DateSpan::span &span, std::string& fileString) {
    DateFormat::format tempformat = this->detectFormat(date);
    std::vector<std::tm> tempspan = this->detectSpan(fileString);
    if(this->detectDateInSpan(this->formatDate(date),tempspan, span)){
        this->setDate(date);
    }
    else{
        this->setDate((std::string&)"");
    }
}

std::string Date::getDate() {
    return this->date;
}

void Date::setDate(std::string &date) {
    this->date = date;
}

DateFormat::format Date::detectFormat(std::string &date) {
    std::regex format1(R"(^\d{2}\d{2}\d{4}$)");      // ttmmjjjj
    std::regex format2(R"(^\d{2}\.\d{2}\.\d{4}$)");  // tt.mm.jjjj
    std::regex format3(R"(^\d{4}\d{2}\d{2}$)");      // jjjjmmtt

    if (std::regex_match(date, format1)) {
        return DateFormat::format::ddmmjjjj;
    } else if (std::regex_match(date, format2)) {
        return DateFormat::format::dd_mm_jjjj;
    } else if (std::regex_match(date, format3)) {
        return DateFormat::format::jjjjmmdd;
    } else {
        return DateFormat::format::unknown;
    }
}

std::vector<std::tm> Date::detectSpan(std::string &dateSpan) {
    std::regex regex1(R"(BKK_(\d{2}\.\d{4})_(\d{2}\.\d{4}))"); // BKK_01.2023_12.2023
    std::regex regex2(R"(BKK_(\d{4}\d{2})_(\d{4}\d{2}))"); // BKK_202301_202312
    std::regex regex3(R"(BKK_(\d{2}\d{4})_(\d{2}\d{4}))"); // BKK_012023_122023
    std::smatch matches;

    int startMonth, startYear, endMonth, endYear;

    if (std::regex_search(dateSpan, matches, regex1)) {
        startMonth = std::stoi(matches[1].str().substr(0, 2));
        startYear = std::stoi(matches[1].str().substr(3, 4));
        endMonth = std::stoi(matches[2].str().substr(0, 2));
        endYear = std::stoi(matches[2].str().substr(3, 4));
    } else if (std::regex_search(dateSpan, matches, regex2)) {
        startYear = std::stoi(matches[1].str().substr(0, 4));
        startMonth = std::stoi(matches[1].str().substr(4, 2));
        endYear = std::stoi(matches[2].str().substr(0, 4));
        endMonth = std::stoi(matches[2].str().substr(4, 2));
    } else if (std::regex_search(dateSpan, matches, regex3)) {
        startMonth = std::stoi(matches[1].str().substr(0, 2));
        startYear = std::stoi(matches[1].str().substr(2, 4));
        endMonth = std::stoi(matches[2].str().substr(0, 2));
        endYear = std::stoi(matches[2].str().substr(2, 4));
    } else {
        throw std::invalid_argument("Ungültiges Datumsformat");
    }

    std::tm startDate = toTm(1, startMonth, startYear);
    std::tm endDate = toTm(31, endMonth, endYear);

    return {startDate, endDate};
}

std::tm Date::toTm(int day, int month, int year) {
    std::tm t = {};
    t.tm_mday = day;
    t.tm_mon = month - 1;
    t.tm_year = year - 1900;
    return t;
}

const std::tm Date::formatDate(std::string &date) {
    DateFormat::format detectedFormat = detectFormat(date);

    std::tm formattedDate = {};

    switch (detectedFormat) {
        case DateFormat::format::ddmmjjjj: {
            int day = std::stoi(date.substr(0, 2));
            int month = std::stoi(date.substr(2, 2));
            int year = std::stoi(date.substr(4, 4));
            formattedDate.tm_mday = day;
            formattedDate.tm_mon = month - 1;
            formattedDate.tm_year = year - 1900;
            break;
        }
        case DateFormat::format::dd_mm_jjjj: {
            int day = std::stoi(date.substr(0, 2));
            int month = std::stoi(date.substr(3, 2));
            int year = std::stoi(date.substr(6, 4));
            formattedDate.tm_mday = day;
            formattedDate.tm_mon = month - 1;
            formattedDate.tm_year = year - 1900;
            break;
        }
        case DateFormat::format::jjjjmmdd: {
            int year = std::stoi(date.substr(0, 4));
            int month = std::stoi(date.substr(4, 2));
            int day = std::stoi(date.substr(6, 2));
            formattedDate.tm_mday = day;
            formattedDate.tm_mon = month - 1;
            formattedDate.tm_year = year - 1900;
            break;
        }
        default:
            // Ungültiges Datumformat
            break;
    }
    return formattedDate;
}

bool Date::detectDateInSpan(const std::tm &date,const std::vector<std::tm> &periodOfTime, DateSpan::span &span) {
    std::tm startDate = periodOfTime[0];
    std::tm endDate = periodOfTime[1];
    std::tm tempdate = date;
    std::time_t startTimestamp = std::mktime(&startDate);
    std::time_t endTimestamp = std::mktime(&endDate);
    std::time_t dateTimestamp = std::mktime(&tempdate);

    if (span == DateSpan::span::vero_dat) {
        if (dateTimestamp < startTimestamp || dateTimestamp > endTimestamp) {
            return false;
        } else {
            return true;
        }
    } else if (span == DateSpan::span::abbr_dat) {
        return true;
    } else {
        return false;
    }
}


bool Date::isSet() {
    return this->date != (std::string&)"";
}

bool Date::isEqual(Date &date) {
    return this->date == date.date;
}