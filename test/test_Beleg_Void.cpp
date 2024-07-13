//
// Created by Jakob Glück on 08.07.24.
//
#include "gtest/gtest.h"
#include "include/Beleg_VoidExampleFactory.h"

TEST(Belev_VoidTest,normalBelegAndVoid_CheckBeleg){
    Beleg_Void tempeBeleg_Void = Beleg_VoidExampleFactory::normalBeleg_Void();
    EXPECT_EQ(tempeBeleg_Void.getBelegNr().getBelegNr(),Beleg_VoidExampleFactory::normalBeleg().getBelegNr());
}

TEST(Belev_VoidTest,normalBelegAndVoid_CheckVoid){
    Beleg_Void tempeBeleg_Void = Beleg_VoidExampleFactory::normalBeleg_Void();
    EXPECT_EQ(tempeBeleg_Void.getVOID().getVOID(),Beleg_VoidExampleFactory::normalVoid().getVOID());
}

TEST(Belev_VoidTest,onlyBelegAndVoid_CheckBeleg){
    Beleg_Void tempeBeleg_Void = Beleg_VoidExampleFactory::onlyBeleg_Void();
    EXPECT_EQ(tempeBeleg_Void.getBelegNr().getBelegNr(),Beleg_VoidExampleFactory::onlyBeleg().getBelegNr());
}

TEST(Belev_VoidTest,onlyBelegAndVoid_CheckVoid){
    Beleg_Void tempeBeleg_Void = Beleg_VoidExampleFactory::normalBeleg_Void();
    EXPECT_EQ(tempeBeleg_Void.getVOID().getVOID(),Beleg_VoidExampleFactory::onlyBeleg().getBelegNr());
}

TEST(Belev_VoidTest,BelegAndonlyVoid_CheckBeleg){
    Beleg_Void tempeBeleg_Void = Beleg_VoidExampleFactory::Beleg_onlyVoid();
    EXPECT_EQ(tempeBeleg_Void.getBelegNr().getBelegNr(),Beleg_VoidExampleFactory::onlyVoid().getVOID());
}

TEST(Belev_VoidTest,BelegAndonlyVoid_CheckVoid){
    Beleg_Void tempeBeleg_Void = Beleg_VoidExampleFactory::Beleg_onlyVoid();
    EXPECT_EQ(tempeBeleg_Void.getVOID().getVOID(),Beleg_VoidExampleFactory::onlyVoid().getVOID());
}
