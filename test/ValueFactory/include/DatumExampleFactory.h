//
// Created by Jakob Glück on 11.07.24.
//

#pragma once

#include "Datum.h"

class DateExampleFactory {
public:
    static std::string normalDateValue();
    static Date normalDate();

    static std::string outOfRangeDateValue();
    static Date outOfRangeDate();

    static std::string invalidDateFormatValue();
    static Date invalidDateFormat();

    static std::string differentSpanValue();
    static Date dateInDifferentSpan();

    static std::string spanStartDateValue();
    static Date spanStartDate();

    static std::string spanEndDateValue();
    static Date spanEndDate();

    static std::string validDateInRangeValue();
    static Date validDateInRange();
};