//
// Created by Jakob Glück on 13.05.24.
//
#include "gtest/gtest.h"
#include "include/ArztnameExampleFactory.h"


TEST(NameTest, TestFirstNormalName) {
    DoctorName docName = ArztnameExampleFactory::normalDoctorName();
    EXPECT_EQ(docName.getVorname(), ArztnameExampleFactory::normalFirstName());
}

TEST(NameTest, TestLastNormalName) {
    DoctorName docName = ArztnameExampleFactory::normalDoctorName();
    EXPECT_EQ(docName.getNachname(), ArztnameExampleFactory::normalLastName());
}

TEST(NameTest, TestDoctorTitleNormalName) {
    DoctorName docName = ArztnameExampleFactory::normalDoctorName();
    EXPECT_EQ(docName.getDoctorTitle().getDoctorTitle(), ArztnameExampleFactory::doktorTitle().getDoctorTitle());
}

TEST(NameTest, TestFirstLongName) {
    DoctorName docName = ArztnameExampleFactory::longDoctorName();
    EXPECT_EQ(docName.getVorname(), ArztnameExampleFactory::longFirstName());
}

TEST(NameTest, TestLastLongName) {
    DoctorName docName = ArztnameExampleFactory::longDoctorName();
    EXPECT_EQ(docName.getNachname(), ArztnameExampleFactory::longLastName());
}

TEST(NameTest, TestDoctorTitleLongName) {
    DoctorName docName = ArztnameExampleFactory::longDoctorName();
    EXPECT_EQ(docName.getDoctorTitle().getDoctorTitle(), ArztnameExampleFactory::dr_dr_Title().getDoctorTitle());
}

TEST(NameTest, TestFirstInvalidName) {
    DoctorName docName = ArztnameExampleFactory::invalidDoctorName();
    EXPECT_EQ(docName.getVorname(), "");
}

TEST(NameTest, TestLastInvalidName) {
    DoctorName docName = ArztnameExampleFactory::invalidDoctorName();
    EXPECT_EQ(docName.getNachname(), "");
}

TEST(NameTest, TestDoctorTitleEmptyName) {
    DoctorName docName = ArztnameExampleFactory::invalidDoctorName();
    EXPECT_EQ(docName.getDoctorTitle().getDoctorTitle(), ArztnameExampleFactory::emptyTitle().getDoctorTitle());
}

TEST(NameTest, TestFullLastNameWithNoFirstName) {
    DoctorName docName = ArztnameExampleFactory::FullLastNameDoctorName();
    EXPECT_EQ(docName.getVorname(), "Mark");
}

TEST(NameTest, TestFullLastName) {
    DoctorName docName = ArztnameExampleFactory::FullLastNameDoctorName();
    EXPECT_EQ(docName.getNachname(), "Schiller");
}

TEST(NameTest, TestDoctorTitleWithFullLastName) {
    DoctorName docName = ArztnameExampleFactory::FullLastNameDoctorName();
    EXPECT_EQ(docName.getDoctorTitle().getDoctorTitle(), "Dr.");
}

TEST(NameTest, TestFullFirstNameWithNoFirstName) {
    DoctorName docName = ArztnameExampleFactory::FullFirstNameDoctorName();
    EXPECT_EQ(docName.getVorname(), "Mark");
}

TEST(NameTest, TestFullFirstName) {
    DoctorName docName = ArztnameExampleFactory::FullFirstNameDoctorName();
    EXPECT_EQ(docName.getNachname(), "Schiller");
}

TEST(NameTest, TestDoctorTitleWithFirstLastName) {
    DoctorName docName = ArztnameExampleFactory::FullFirstNameDoctorName();
    EXPECT_EQ(docName.getDoctorTitle().getDoctorTitle(), "Dr.");
}