//
// Created by Jakob Glück on 08.07.24.
//

#include "gtest/gtest.h"
#include "include/ArztAdresseExampleFactory.h"

TEST(AddressTest, normalAddressCity){
    Address tempAddress = AddressExampleFactory::NormalAddress();
    EXPECT_EQ(tempAddress.getCity().getCityName(),AddressExampleFactory::normalCity().getCityName());
}

TEST(AddressTest, normalAddressPostalCode){
    Address tempAddress = AddressExampleFactory::NormalAddress();
    EXPECT_EQ(tempAddress.getPostalCode().getPostalCode(),AddressExampleFactory::normalPostalCode().getPostalCode());
}

TEST(AddressTest, normalAddressStreetName){
    Address tempAddress = AddressExampleFactory::NormalAddress();
    EXPECT_EQ(tempAddress.getStreetName().getStreetName(),AddressExampleFactory::normalStreetName().getStreetName());
}
