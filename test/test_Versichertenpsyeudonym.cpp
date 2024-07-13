//
// Created by Jakob Glück on 10.07.24.
//

#include "gtest/gtest.h"
#include "include/VersichertenpsyeudonymExampleFactory.h"

TEST(InsuredPseudonymTest, normalInsuredPseudonym){
    InsuredPseudonym tempInsuredPseudonym = InsuredPseudonymExampleFactory::normalInsuredPseudonym();
    EXPECT_EQ(tempInsuredPseudonym.getInsuredPseudonym(),InsuredPseudonymExampleFactory::normalInsuredPseudonymValue());
}

TEST(InsuredPseudonymTest, normalInsuredPseudonymCheckIsSet){
    InsuredPseudonym tempInsuredPseudonym = InsuredPseudonymExampleFactory::normalInsuredPseudonym();
    EXPECT_EQ(tempInsuredPseudonym.isSet(),true);
}

TEST(InsuredPseudonymTest, emptyInsuredPseudonym){
    InsuredPseudonym tempInsuredPseudonym = InsuredPseudonymExampleFactory::emptyInsuredPseudonymValue();
    EXPECT_EQ(tempInsuredPseudonym.getInsuredPseudonym(),"");
}

TEST(InsuredPseudonymTest, CheckIsSetMethod){
    InsuredPseudonym tempInsuredPseudonym = InsuredPseudonymExampleFactory::emptyInsuredPseudonymCheckIsSetMethod();
    EXPECT_EQ(tempInsuredPseudonym.isSet(),false);
}