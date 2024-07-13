//
// Created by Jakob Glück on 08.07.24.
//

#include "gtest/gtest.h"
#include "include/ArztStraßeExampleFactory.h"

TEST(StreetNameTest, normalStreet){
    StreetName tempStreetName = StreetExampleFactory::normalStreet();
    EXPECT_EQ(tempStreetName.getStreetName(),StreetExampleFactory::normalStreetName());
}

TEST(StreetNameTest, longStreet){
    StreetName tempStreetName = StreetExampleFactory::longStreet();
    EXPECT_EQ(tempStreetName.getStreetName(),StreetExampleFactory::longStreetName());
}

TEST(StreetNameTest, StreetWithStraße){
    StreetName tempStreetName = StreetExampleFactory::streetNameWithStraße();
    EXPECT_EQ(tempStreetName.getStreetName(),"Bahnhofstr. 12");
}

TEST(StreetNameTest, StreetWithStrasse){
    StreetName tempStreetName = StreetExampleFactory::streetNameWithStrasse();
    EXPECT_EQ(tempStreetName.getStreetName(),"Schulstr. 22");
}

TEST(StreetNameTest, StreetWithInvalidInput){
    StreetName tempStreetName = StreetExampleFactory::streetNameWithInvalid();
    EXPECT_EQ(tempStreetName.getStreetName(),"");
}