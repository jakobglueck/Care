//
// Created by Jakob Glück on 08.07.24.
//

#include "gtest/gtest.h"
#include "include/LANRExampleFactory.h"

TEST(LanrTest, allowedLanrLANR){
    LANR tempLANR = LANRExampleFactory::allowedLanr();
    EXPECT_EQ(tempLANR.getLANR(),LANRExampleFactory::allowedLanrValue());
}

TEST(LanrTest, allowedLanrTempLANR){
    LANR tempLANR = LANRExampleFactory::allowedLanr();
    EXPECT_EQ(tempLANR.getTempLANR(),LANRExampleFactory::allowedLanrValue());
}

TEST(LanrTest, invalidValue1LanrLANR){
    LANR tempLANR = LANRExampleFactory::invalidLanr1();
    EXPECT_EQ(tempLANR.getLANR(),"");
}

TEST(LanrTest, invalidValue1LanrTempLANR){
    LANR tempLANR = LANRExampleFactory::invalidLanr1();
    EXPECT_EQ(tempLANR.getTempLANR(),LANRExampleFactory::invalidLanrValue1());
}

TEST(LanrTest, invalidValue2LanrLANR){
    LANR tempLANR = LANRExampleFactory::invalidLanr2();
    EXPECT_EQ(tempLANR.getLANR(),"");
}

TEST(LanrTest, invalidValue2LanrTempLANR){
    LANR tempLANR = LANRExampleFactory::invalidLanr2();
    EXPECT_EQ(tempLANR.getTempLANR(),LANRExampleFactory::invalidLanrValue2());
}

TEST(LanrTest, invalidValue3LanrLANR){
    LANR tempLANR = LANRExampleFactory::invalidLanr3();
    EXPECT_EQ(tempLANR.getLANR(),"");
}

TEST(LanrTest, invalidValue3LanrTempLANR){
    LANR tempLANR = LANRExampleFactory::invalidLanr3();
    EXPECT_EQ(tempLANR.getTempLANR(),LANRExampleFactory::invalidLanrValue3());
}

TEST(LanrTest, invalidValue3BetweenLanrLANR){
    LANR tempLANR = LANRExampleFactory::invalidLanr3Between();
    EXPECT_EQ(tempLANR.getLANR(),"");
}

TEST(LanrTest, invalidValue3BetweenLanrTempLANR){
    LANR tempLANR = LANRExampleFactory::invalidLanr3Between();
    EXPECT_EQ(tempLANR.getTempLANR(),LANRExampleFactory::invalidLanrValue3Between());
}

TEST(LanrTest, invalidValueLetterLanrLANR){
    LANR tempLANR = LANRExampleFactory::letterLanr();
    EXPECT_EQ(tempLANR.getLANR(),"");
}

TEST(LanrTest, invalidValueLetterLanrTempLANR){
    LANR tempLANR = LANRExampleFactory::letterLanr();
    EXPECT_EQ(tempLANR.getTempLANR(),LANRExampleFactory::letterLanrValue());
}

TEST(LanrTest, longLanrLANR){
    LANR tempLANR = LANRExampleFactory::longLanr();
    EXPECT_EQ(tempLANR.getLANR(),"");
}

TEST(LanrTest, longTempLANR){
    LANR tempLANR = LANRExampleFactory::longLanr();
    EXPECT_EQ(tempLANR.getTempLANR(),LANRExampleFactory::longLanrValue());
}

TEST(LanrTest, shortLanrLANR){
    LANR tempLANR = LANRExampleFactory::shortLanr();
    EXPECT_EQ(tempLANR.getLANR(),"");
}

TEST(LanrTest, shortTempLANR){
    LANR tempLANR = LANRExampleFactory::shortLanr();
    EXPECT_EQ(tempLANR.getTempLANR(),LANRExampleFactory::shortLanrValue());
}