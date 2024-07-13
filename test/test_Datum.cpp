//
// Created by Jakob Glück on 11.07.24.
//

#include "gtest/gtest.h"
#include "include/DatumExampleFactory.h"

// Test für normalDateValue Methode
TEST(DateExampleFactoryTest, normalDateValue) {
    EXPECT_EQ(DateExampleFactory::normalDateValue(), "AOK Bayern_01012024_01.24-12.24");
}

// Test für normalDate Methode
TEST(DateExampleFactoryTest, normalDate) {
    Date date = DateExampleFactory::normalDate();
    EXPECT_TRUE(date.isSet());
    EXPECT_TRUE(date.isInSpan());
    EXPECT_EQ(date.getDate(), "01012024");
}

// Test für ein Datum, das außerhalb der Spanne liegt
TEST(DateTest, DateOutOfRange) {
    Date date = DateExampleFactory::outOfRangeDate();
    EXPECT_FALSE(date.isInSpan());
}

// Test für ein Datum, das innerhalb der Spanne liegt
TEST(DateTest, DateInRange) {
    Date date = DateExampleFactory::validDateInRange();
    EXPECT_TRUE(date.isInSpan());
}

// Test für ein Datum mit falschem Format
TEST(DateTest, InvalidDateFormat) {
    try {
        Date date = DateExampleFactory::invalidDateFormat();
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument& e) {
        EXPECT_EQ(std::string(e.what()), "Ungültiges Datumsformat");
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

// Test für das Setzen und Abrufen eines Datums
TEST(DateTest, SetAndGetDate) {
    Date date;
    date.setDate("01012024");
    EXPECT_TRUE(date.isSet());
    EXPECT_EQ(date.getDate(), "01012024");
}

TEST(DateTest, DetectAndFormatDateViaPublicMethod) {
    Date date("12.12.2024", DateExampleFactory::normalDateValue());
    EXPECT_TRUE(date.isSet());
    EXPECT_EQ(date.getDate(), "12.12.2024");
}

TEST(DateTest, SetEmptyDate) {
    Date date;
    date.setDate("");
    EXPECT_FALSE(date.isSet());
}

TEST(DateTest, DateInDifferentSpan) {
    Date date = DateExampleFactory::dateInDifferentSpan();
    EXPECT_TRUE(date.isInSpan());
}

TEST(DateTest, DateAtSpanStart) {
    Date date = DateExampleFactory::spanStartDate();
    EXPECT_TRUE(date.isInSpan());
}


TEST(DateTest, DateAtSpanEnd) {
    Date date = DateExampleFactory::spanEndDate();
    EXPECT_TRUE(date.isInSpan());
}

TEST(DateTest, AudiBkkFormat) {
    std::string fileString = "Audi BKK_20240512_01.24-12.24";
    Date date("20240512", fileString);
    EXPECT_TRUE(date.isInSpan());
}
