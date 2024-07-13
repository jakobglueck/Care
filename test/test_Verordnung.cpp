//
// Created by Jakob Glück on 12.07.24.
//

#include "gtest/gtest.h"
#include "include/VerordnungExampleFactory.h"

TEST(PrescriptionTest, normalPrescriptionIsEqualTrue){
    Prescription prescription = PrescriptionExampleFactory::normalPrescription();
    Prescription compPrescription = PrescriptionExampleFactory::normalPrescription();
    EXPECT_EQ(prescription.getPrescriptionStatus(), Status::Approved);
    EXPECT_TRUE(prescription.mainValueAreSet());
    EXPECT_TRUE(prescription.isEqual(compPrescription));
}

TEST(PrescriptionTest, normalPrescriptionIsEqualFalse){
    Prescription prescription = PrescriptionExampleFactory::normalPrescription();
    Prescription compPrescription = PrescriptionExampleFactory::invalidPrescription();
    EXPECT_EQ(prescription.getPrescriptionStatus(), Status::Approved);
    EXPECT_TRUE(prescription.mainValueAreSet());
    EXPECT_FALSE(prescription.isEqual(compPrescription));
}

TEST(PrescriptionTest, invalidPrescriptionIsEqualTrue){
    Prescription prescription = PrescriptionExampleFactory::invalidPrescription();
    Prescription compPrescription = PrescriptionExampleFactory::invalidPrescription();
    EXPECT_EQ(prescription.getPrescriptionStatus(), Status::Unapproved);
    EXPECT_FALSE(prescription.mainValueAreSet());
    EXPECT_TRUE(prescription.isEqual(compPrescription));
}