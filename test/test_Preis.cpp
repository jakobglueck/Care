//
// Created by Jakob Glück on 05.07.24.
//

#include "gtest/gtest.h"
#include "include/PreisExampleFactory.h"

TEST(PriceTest, EmptyPrice){
    Price tempPrice = PriceExampleFactory::emptyPrice();
    std::optional<float> emptyFloat;
    EXPECT_EQ(tempPrice.getPrice(), emptyFloat.has_value());
}

TEST(PriceTest, EmptyPriceAmount){
    Price tempPrice = PriceExampleFactory::emptyPrice();
    EXPECT_EQ(tempPrice.getAmount(), 0);
}

TEST(PriceTest, NormalPrice){
    Price tempPrice = PriceExampleFactory::normalPrice();
    EXPECT_EQ(tempPrice.getPrice(),PriceExampleFactory::normalPriceValue());
}

TEST(PriceTest, NormalPriceAmount){
    Price tempPrice = PriceExampleFactory::normalPrice();
    EXPECT_EQ(tempPrice.getAmount(),2);
}

TEST(PriceTest, HighPrice){
    Price tempPrice = PriceExampleFactory::highPrice();
    EXPECT_EQ(tempPrice.getPrice(),PriceExampleFactory::highPriceValue());
}

TEST(PriceTest, HighPriceAmount){
    Price tempPrice = PriceExampleFactory::highPrice();
    EXPECT_EQ(tempPrice.getAmount(),20);
}

TEST(PriceTest, NULLPrice){
    Price tempPrice = PriceExampleFactory::NULLPrice();
    EXPECT_EQ(tempPrice.getPrice(),0.00);
}

TEST(PriceTest, NULLPriceAmount){
    Price tempPrice = PriceExampleFactory::NULLPrice();
    EXPECT_EQ(tempPrice.getAmount(),0);
}
