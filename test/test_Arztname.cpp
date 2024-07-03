//
// Created by Jakob Glück on 13.05.24.
//
#include "Arztname.h"
#include "ValueFactory/include/ArztnameExampleFactory.h"
#include "gtest/gtest.h"

class VornameTest : public ::testing::Test {
protected:
    DoctorName normalName =
            ArztnameExampleFactory::normalName();
    DoctorName shortName =
            ArztnameExampleFactory::shortName();
    DoctorName longName =
            ArztnameExampleFactory::longName();
    DoctorName doubleName =
            ArztnameExampleFactory::doubleName();
    DoctorName tripleName =
            ArztnameExampleFactory::tripleName();
    DoctorName emptyName =
            ArztnameExampleFactory::emtpyName();
    DoctorName validNumberName =
            ArztnameExampleFactory::validNumberName();
    DoctorName invalidNumberName1 =
            ArztnameExampleFactory::invalidNumberName1();
    DoctorName invalidNumberName2 =
            ArztnameExampleFactory::invalidNumberName2();
    DoctorName invalidNumberName3 =
            ArztnameExampleFactory::invalidNumberName3();
    DoctorName invalidNumberName4 =
            ArztnameExampleFactory::invalidNumberName4();
};

TEST_F(VornameTest, TestNormalName){
    EXPECT_EQ(true,true);
}
