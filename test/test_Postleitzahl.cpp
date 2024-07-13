//
// Created by Jakob Glück on 08.07.24.
//

#include "gtest/gtest.h"
#include "include/PostleitzahlExampleFactory.h"

TEST(PostalCodeTest, normalPostalCode){
    PostalCode tempPostalCode = PostalCodeExampleFactory::normalPostalCode();
    EXPECT_EQ(tempPostalCode.getPostalCode(),PostalCodeExampleFactory::normalPostalCodeValue());
}

TEST(PostalCodeTest, shortPostalCode){
    PostalCode tempPostalCode = PostalCodeExampleFactory::shortPostalCode();
    EXPECT_EQ(tempPostalCode.getPostalCode(),PostalCodeExampleFactory::normalPostalCodeValue());
}

TEST(PostalCodeTest, invalidPostalCode){
    PostalCode tempPostalCode = PostalCodeExampleFactory::invalidPostalCode();
    EXPECT_EQ(tempPostalCode.getPostalCode(), "");
}