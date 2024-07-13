//
// Created by Jakob Glück on 08.07.24.
//

#include "gtest/gtest.h"
#include "include/ArztOrtExampleFactory.h"

TEST(CityTest,normalCityName){
    City tempCity = CityExampleFactory::normalCity();
    EXPECT_EQ(tempCity.getCityName(),CityExampleFactory::normalCityName());
}

TEST(CityTest,longCityName){
    City tempCity = CityExampleFactory::longCity();
    EXPECT_EQ(tempCity.getCityName(),CityExampleFactory::longCityName());
}

TEST(CityTest,invalidCityNameParis){
    City tempCity = CityExampleFactory::invalid1City();
    EXPECT_EQ(tempCity.getCityName(),"Paris");
}

TEST(CityTest,invalidCityNameWrongSpelling){
    City tempCity = CityExampleFactory::invalid2City();
    EXPECT_EQ(tempCity.getCityName(),"Müchen");
}

TEST(CityTest,invalidCityNameEmpty){
    City tempCity = CityExampleFactory::invalid3City();
    EXPECT_EQ(tempCity.getCityName(),"");
}
