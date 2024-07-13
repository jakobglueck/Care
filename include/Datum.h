//
// Created by Jakob Glück on 30.05.24.
//

#pragma once

#include "include.h"

namespace DateSpan {
    enum span {
        abbr_dat,
        vero_dat
    };

    inline std::string toString(span s) {
        switch (s) {
            case abbr_dat: return "abbr_dat";
            case vero_dat: return "vero_dat";
            default: return "unknown";
        }
    }
}

namespace DateFormat {
    enum format {
        dd_mm_jjjj,
        jjjjmmdd,
        ddmmjjjj,
        unknown
    };

    inline std::string toString(format f) {
        switch (f) {
            case dd_mm_jjjj: return "dd_mm_jjjj";
            case jjjjmmdd: return "jjjjmmdd";
            case ddmmjjjj: return "ddmmjjjj";
            default: return "unknown";
        }
    }
}

class Date {
public:
    Date(std::string inputDate, std::string fileString);
    Date();

    void setDate(std::string date);
    std::string getDate();

    bool isSet();
    bool isInSpan();
    bool isEqual(Date &date);

private:
    std::vector<std::tm> detectSpan(std::string& dateSpan);
    std::tm toTm(int day, int month, int year);

    bool detectDateInSpan(std::tm &date, std::vector<std::tm> &periodOfTime, DateSpan::span span);

    DateFormat::format detectFormat(std::string &date);
    std::tm formatDate(std::string &date);

    std::pair<std::string, std::string> parseInput(std::string &input);

    std::string date;
    bool dateSet;
    bool inSpan;
};
