//
// Created by Jakob Glück on 10.07.24.
//

#include "gtest/gtest.h"
#include "include/InhaberExampleFactory.h"

TEST(PharmacyOwnerTest, normalPharmacyOwner){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::normalPharmacyOwner();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),PharmacyOwnerExampleFactory::normalPharmacyOwnerValue());
}

TEST(PharmacyOwnerTest, longPharmacyOwner){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::longPharmacyOwner();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),PharmacyOwnerExampleFactory::longPharmacyOwnerValue());
}

TEST(PharmacyOwnerTest, shortPharmacyOwner){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::shortPharmacyOwner();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),PharmacyOwnerExampleFactory::shortPharmacyOwnerValue());
}

TEST(PharmacyOwnerTest, invalidNumberPharmacyOwner){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::invalidPharmacyOwnerNumber();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),"");
}

TEST(PharmacyOwnerTest, invalidPharmacyOwner_GmbH){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::invalidPharmacyOwner_GmbH();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),"Markus Schiller");
}

TEST(PharmacyOwnerTest, invalidPharmacyOwner_eV1){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::invalidPharmacyOwner_eV1();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),"Markus Schiller");
}

TEST(PharmacyOwnerTest, invalidPharmacyOwner_eV2){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::invalidPharmacyOwner_eV2();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),"Markus Schiller");
}

TEST(PharmacyOwnerTest, invalidPharmacyOwner_OHG){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::invalidPharmacyOwner_OHG();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),"Markus Schiller");
}

TEST(PharmacyOwnerTest, invalidPharmacyOwner_Inhaber){
    PharmacyOwner tempPharmacyOwner = PharmacyOwnerExampleFactory::invalidPharmacyOwner_Inhaber();
    EXPECT_EQ(tempPharmacyOwner.getPharmacyOwner(),"Markus Schiller");
}