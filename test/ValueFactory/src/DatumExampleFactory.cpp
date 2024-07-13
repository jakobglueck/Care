//
// Created by Jakob Glück on 11.07.24.
//

#include "include/DatumExampleFactory.h"

// Normal Date
std::string DateExampleFactory::normalDateValue() {
    return "AOK Bayern_01012024_01.24-12.24";
}

Date DateExampleFactory::normalDate() {
    return Date("01012024", DateExampleFactory::normalDateValue());
}

// Date out of range
std::string DateExampleFactory::outOfRangeDateValue() {
    return "AOK Bayern_01012024_01.24-12.24";
}

Date DateExampleFactory::outOfRangeDate() {
    return Date("31122023", DateExampleFactory::outOfRangeDateValue());
}

// Invalid date format
std::string DateExampleFactory::invalidDateFormatValue() {
    return "AOK Bayern_01012024_01.24-12.24";
}

Date DateExampleFactory::invalidDateFormat() {
    return Date("2024-01-01", DateExampleFactory::invalidDateFormatValue());
}

// Different date span
std::string DateExampleFactory::differentSpanValue() {
    return "AOK Bayern_01012023_01.23-12.23";
}

Date DateExampleFactory::dateInDifferentSpan() {
    return Date("15062023", DateExampleFactory::differentSpanValue());
}

// Date at span start
std::string DateExampleFactory::spanStartDateValue() {
    return "AOK Bayern_01012024_01.24-12.24";
}

Date DateExampleFactory::spanStartDate() {
    return Date("01012024", DateExampleFactory::spanStartDateValue());
}

// Date at span end
std::string DateExampleFactory::spanEndDateValue() {
    return "AOK Bayern_01012024_01.24-12.24";
}

Date DateExampleFactory::spanEndDate() {
    return Date("31122024", DateExampleFactory::spanEndDateValue());
}

// Valid date in range
std::string DateExampleFactory::validDateInRangeValue() {
    return "AOK Bayern_01012024_01.24-12.24";
}

Date DateExampleFactory::validDateInRange() {
    return Date("01022024", DateExampleFactory::validDateInRangeValue());
}