//
// Created by Jakob Glück on 13.05.24.
//
#include "Arztname.h"
#include "ValueFactory/include/ArztnameExampleFactory.h"
#include "gtest/gtest.h"

class VornameTest : public ::testing::Test {
protected:
    Arztname normalName =
            ArztnameExampleFactory::normalName();
    Arztname shortName =
            ArztnameExampleFactory::shortName();
    Arztname longName =
            ArztnameExampleFactory::longName();
    Arztname doubleName =
            ArztnameExampleFactory::doubleName();
    Arztname tripleName =
            ArztnameExampleFactory::tripleName();
    Arztname emptyName =
            ArztnameExampleFactory::emtpyName();
    Arztname validNumberName =
            ArztnameExampleFactory::validNumberName();
    Arztname invalidNumberName1 =
            ArztnameExampleFactory::invalidNumberName1();
    Arztname invalidNumberName2 =
            ArztnameExampleFactory::invalidNumberName2();
    Arztname invalidNumberName3 =
            ArztnameExampleFactory::invalidNumberName3();
    Arztname invalidNumberName4 =
            ArztnameExampleFactory::invalidNumberName4();
};

TEST_F(VornameTest, TestNormalName){
    EXPECT_EQ(this->normalName.getVorname(), ArztnameExampleFactory::normalVorname());
    EXPECT_EQ(this->normalName.getNachname(), ArztnameExampleFactory::normalNachname());
}
