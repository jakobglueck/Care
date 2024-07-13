//
// Created by Jakob Glück on 10.07.24.
//

#include "gtest/gtest.h"
#include "include/KV_BezirkExampleFactory.h"

TEST(KV_DistrictsTest, normalKV_DistrictValueString){
    KV_Districts tempKV_Districts = KV_DistrictsExampleFactory::normalKV_District();
    EXPECT_EQ(tempKV_Districts.getValue(), "6");
}

TEST(KV_DistrictsTest, normalKV_DistrictValueEnum){
    KV_Districts tempKV_Districts = KV_DistrictsExampleFactory::normalKV_District();
    EXPECT_EQ(tempKV_Districts.getNumberValue(), Districts::Bayern);
}

TEST(KV_DistrictsTest, unknownKV_DistrictValueString){
    KV_Districts tempKV_Districts = KV_DistrictsExampleFactory::unknownKV_District();
    EXPECT_EQ(tempKV_Districts.getValue(),"0");
}

TEST(KV_DistrictsTest,  unknownKV_DistrictValueEnum){
    KV_Districts tempKV_Districts = KV_DistrictsExampleFactory::unknownKV_District();
    EXPECT_EQ(tempKV_Districts.getNumberValue(), Districts::Unknown);
}

TEST(KV_DistrictsTest, KV_DistrictWithPostalCodeString){

    KV_Districts tempKV_Districts = KV_DistrictsExampleFactory::KV_DistrictWithPostalCode();
    EXPECT_EQ(tempKV_Districts.getValue(), "11");
}

TEST(KV_DistrictsTest, KV_DistrictWithPostalCodeEnum){
    KV_Districts tempKV_Districts = KV_DistrictsExampleFactory::KV_DistrictWithPostalCode();
    EXPECT_EQ(tempKV_Districts.getNumberValue(), Districts::Brandenburg);
}