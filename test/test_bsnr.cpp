//
// Created by Jakob Glück on 09.07.24.
//

#include "gtest/gtest.h"
#include "include/BsnrExampleFactory.h"

TEST(BsnrTest, normalBsnr){
    BSNR tempBsnr = BsNrExampleFactory::normalBsNr();
    EXPECT_EQ(tempBsnr.getBSNR(),BsNrExampleFactory::normalBsNrValue());
}

TEST(BsnrTest, shortBsnr){
    BSNR tempBsnr = BsNrExampleFactory::invalidShortBsNr();
    EXPECT_EQ(tempBsnr.getBSNR(),"");
}

TEST(BsnrTest, longBsnr){
    BSNR tempBsnr = BsNrExampleFactory::longBsNr();
    EXPECT_EQ(tempBsnr.getBSNR(),"");
}

TEST(BsnrTest, Invalid3Bsnr){
    BSNR tempBsnr = BsNrExampleFactory::invalid3BsNr();
    EXPECT_EQ(tempBsnr.getBSNR(),"");
}

TEST(BsnrTest, letterBsnr){
    BSNR tempBsnr = BsNrExampleFactory::letterBsNr();
    EXPECT_EQ(tempBsnr.getBSNR(),"");
}

TEST(BsnrTest, StartingNullBsnr){
    BSNR tempBsnr = BsNrExampleFactory::invalidStartingNullBsNr();
    EXPECT_EQ(tempBsnr.getBSNR(),"");
}