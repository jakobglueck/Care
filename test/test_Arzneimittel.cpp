#include "gtest/gtest.h"
#include "include/ArzneimittelExampleFactory.h"

TEST(PharmaceuticalTest, NormalPharmaceuticalName){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceutical();
    EXPECT_EQ(tempPharmaceutical.getPharmaceuticalName(), PharmaceuticalExampleFactory::normalPharmaceuticalName());
}

TEST(PharmaceuticalTest, NormalPharmaceuticalPZN){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceutical();
    EXPECT_EQ(tempPharmaceutical.getPZN(), PharmaceuticalExampleFactory::normalPharmaceuticalPZN());
}

TEST(PharmaceuticalTest, NormalPharmaceuticalPrice){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceutical();
    EXPECT_FLOAT_EQ(tempPharmaceutical.getPrice().getPrice(), PharmaceuticalExampleFactory::normalPharmaceuticalPrice().getPrice());
}

TEST(PharmaceuticalTest, NormalPharmaceuticalAmount){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceutical();
    EXPECT_EQ(tempPharmaceutical.getPrice().getAmount(), PharmaceuticalExampleFactory::normalPharmaceuticalPrice().getAmount());
}

TEST(PharmaceuticalTest, NormalPharmaceuticalNameWITHCaps){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalWithCAPS();
    EXPECT_EQ(tempPharmaceutical.getPharmaceuticalName(), PharmaceuticalExampleFactory::normalPharmaceuticalName());
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalPZN){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE();
    EXPECT_EQ(tempPharmaceutical.getPZN(), PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_PZN());
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalName){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE();
    EXPECT_EQ(tempPharmaceutical.getPharmaceuticalName(), std::string("Par.Ernährung (reg.)"));
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalPrice){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE();
    EXPECT_FLOAT_EQ(tempPharmaceutical.getPrice().getPrice(), PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPrice().getPrice());
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalAmount){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE();
    EXPECT_EQ(tempPharmaceutical.getPrice().getAmount(), PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPrice().getAmount());
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalPriceWithWrongAmount){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_WithWrongAmount();
    EXPECT_FLOAT_EQ(tempPharmaceutical.getPrice().getPrice(), PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPriceWithWrongAmount().getPrice());
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalPriceWithWrongAmountCheck){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_WithWrongAmount();
    EXPECT_EQ(tempPharmaceutical.checkPriceForIHPE(), true);
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalAmountWithWrongAmount){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_WithWrongAmount();
    EXPECT_EQ(tempPharmaceutical.getPrice().getAmount(), PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPriceWithWrongAmount().getAmount());
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalWithWrongAmountCheck){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_WithWrongAmount();
    EXPECT_EQ(tempPharmaceutical.checkAmountForIHPE(), false);
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalAmountWithWrongPrice){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_WithWrongPrice();
    EXPECT_FLOAT_EQ(tempPharmaceutical.getPrice().getPrice(), PharmaceuticalExampleFactory::normalPharmaceuticalIHPEPriceWithWrongPrice().getPrice());
}

TEST(PharmaceuticalTest, IHPEPharmaceuticalWithWrongPriceCheck){
    Pharmaceutical tempPharmaceutical = PharmaceuticalExampleFactory::normalPharmaceuticalIHPE_WithWrongPrice();
    EXPECT_EQ(tempPharmaceutical.checkAmountForIHPE(), false);
}