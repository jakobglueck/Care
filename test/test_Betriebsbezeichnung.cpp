//
// Created by Jakob Glück on 10.07.24.
//

#include "gtest/gtest.h"
#include "include/BetriebsbezeichnungExampleFactory.h"

TEST(OperationalDesignationTest, normalOperationalDesignation){
    OperationalDesignation tempOperationalDesignation = OperationalDesignationExampleFactory::normalOperationalDesignation();
    EXPECT_EQ(tempOperationalDesignation.getOperationalDesignation(),OperationalDesignationExampleFactory::normalOperationalDesignationValue());
}

TEST(OperationalDesignationTest, invalidOperationalDesignationNumber){
    OperationalDesignation tempOperationalDesignation = OperationalDesignationExampleFactory::invalidOperationalDesignationNumber();
    EXPECT_EQ(tempOperationalDesignation.getOperationalDesignation(),"");
}

TEST(OperationalDesignationTest, invalidOperationalDesignation_OHG){
    OperationalDesignation tempOperationalDesignation = OperationalDesignationExampleFactory::invalidOperationalDesignation_OHG();
    EXPECT_EQ(tempOperationalDesignation.getOperationalDesignation(),OperationalDesignationExampleFactory::normalOperationalDesignationValue());
}

TEST(OperationalDesignationTest, invalidOperationalDesignation_CoKG_Value){
    OperationalDesignation tempOperationalDesignation = OperationalDesignationExampleFactory::invalidOperationalDesignation_CoKG();
    EXPECT_EQ(tempOperationalDesignation.getOperationalDesignation(),OperationalDesignationExampleFactory::normalOperationalDesignationValue());
}

TEST(OperationalDesignationTest, invalidOperationalDesignation_InSideOfTheValue){
    OperationalDesignation tempOperationalDesignation = OperationalDesignationExampleFactory::invalidOperationalDesignation_InSideOfTheValue_Value();
    EXPECT_EQ(tempOperationalDesignation.getOperationalDesignation(),"MyCare Team");
}