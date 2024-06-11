//
// Created by Jakob Glück on 30.05.24.
//

#include <iostream>
#include <vector>
#include <regex>
#include <ctime>

namespace DateSpan{
    enum span{
        abbr_dat,
        vero_dat
    };
}

namespace DateFormat{
    enum format{
        dd_mm_jjjj,
        jjjjmmdd,
        ddmmjjjj,
        unknown
    };
}

class Date{
public:
    Date(std::string& date,DateSpan::span& span, std::string& fileString);
    Date();

    void setDate(std::string& date);
    std::string getDate();

private:
    std::vector<std::tm> detectSpan(std::string& dateSpan);
    std::tm toTm(int day, int month, int year);

    bool detectDateInSpan(const std::tm &date,const std::vector<std::tm> &periodOfTime, DateSpan::span &span);

    DateFormat::format detectFormat(std::string& date);
    const std::tm formatDate(std::string &date);

    std::string convertEnumInString(DateFormat::format& format);

    std::string date;
};
