//
// Created by Jakob Glück on 30.05.24.
//

#include "Datum.h"

Date::Date() {
    this->dateSet = false;
    this->inSpan = false;
}

Date::Date(std::string inputDate, std::string fileString) {
    this->dateSet = false;
    this->inSpan = false;

    std::string extractedSpan;
    std::tie(std::ignore, extractedSpan) = this->parseInput(fileString);

    std::vector<std::tm> tempspan = this->detectSpan(extractedSpan);
    std::tm formattedDate = this->formatDate(inputDate);

    if (this->detectDateInSpan(formattedDate, tempspan, DateSpan::span::vero_dat)) {
        this->setDate(inputDate);
        this->inSpan = true;
    } else {
        this->setDate("");
        this->inSpan = false;
    }
}

std::string Date::getDate() {
    return this->date;
}

void Date::setDate(std::string date) {
    this->date = date;
    if(date.empty() || date == ""){
        this->dateSet = false;
    }
    else{
        this->dateSet = true;
    }
}

DateFormat::format Date::detectFormat(std::string &date) {
    std::regex format1(R"(^\d{4}\d{2}\d{2}$)");      // jjjjmmtt
    std::regex format2(R"(^\d{2}\.\d{2}\.\d{4}$)");  // tt.mm.jjjj
    std::regex format3(R"(^\d{2}\d{2}\d{4}$)");      // ttmmjjjj

    if (std::regex_match(date, format2)) {
        return DateFormat::format::dd_mm_jjjj;
    } else if (std::regex_match(date, format1)) {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(4, 2));
        int day = std::stoi(date.substr(6, 2));
        if (year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            return DateFormat::format::jjjjmmdd;
        }
    }
    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(2, 2));
    int year = std::stoi(date.substr(4, 4));
    if (year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
        return DateFormat::format::ddmmjjjj;
    }
    return DateFormat::format::unknown;
}

std::vector<std::tm> Date::detectSpan(std::string &dateSpan) {
    std::regex regex(R"(^(\d{2}\.\d{2})-(\d{2}\.\d{2})$)"); // Allgemeingültiges Muster
    std::smatch matches;

    int startMonth, startYear, endMonth, endYear;

    if (std::regex_search(dateSpan, matches, regex)) {
        startMonth = std::stoi(matches[1].str().substr(0, 2));
        startYear = std::stoi("20" + matches[1].str().substr(3, 2));
        endMonth = std::stoi(matches[2].str().substr(0, 2));
        endYear = std::stoi("20" + matches[2].str().substr(3, 2));
    } else {
        throw std::invalid_argument("Ungültiges Datumsformat");
    }

    std::tm startDate = this->toTm(1, startMonth, startYear);
    std::tm endDate = this->toTm(31, endMonth, endYear);

    return {startDate, endDate};
}

std::tm Date::toTm(int day, int month, int year) {
    std::tm t = {};
    t.tm_mday = day;
    t.tm_mon = month - 1;
    t.tm_year = year - 1900;
    return t;
}

std::tm Date::formatDate(std::string &date) {
    DateFormat::format detectedFormat = this->detectFormat(date);

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
            throw std::invalid_argument("Ungültiges Datumsformat");
    }
    return formattedDate;
}

bool Date::detectDateInSpan(std::tm &date, std::vector<std::tm> &periodOfTime, DateSpan::span span) {
    std::tm startDate = periodOfTime[0];
    std::tm endDate = periodOfTime[1];
    std::tm tempdate = date;
    std::time_t startTimestamp = std::mktime(&startDate);
    std::time_t endTimestamp = std::mktime(&endDate);
    std::time_t dateTimestamp = std::mktime(&tempdate);

    if (span == DateSpan::span::vero_dat) {
        return dateTimestamp >= startTimestamp && dateTimestamp <= endTimestamp;
    } else if (span == DateSpan::span::abbr_dat) {
        return true;
    } else {
        return false;
    }
}

std::pair<std::string, std::string> Date::parseInput(std::string &input) {
    std::regex regex(R"(^(.*?)_(\d{8})_(.*?)$)");
    std::smatch matches;

    if (std::regex_search(input, matches, regex)) {
        std::string date = matches[2];
        std::string span = matches[3];
        span = std::regex_replace(span, std::regex("\\.xlsx$"), "");
        return {date, span};
    } else {
        throw std::invalid_argument("Ungültiges Eingabeformat");
    }
}

bool Date::isSet() {
    return this->dateSet;
}

bool Date::isInSpan() {
    return this->inSpan;
}

bool Date::isEqual(Date &date) {
    return this->date == date.date;
}