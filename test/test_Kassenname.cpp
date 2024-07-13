//
// Created by Jakob Glück on 10.07.24.
//

#include "gtest/gtest.h"
#include "include/KrankenkassenExampleFactory.h"

TEST(HealthInsuranceCompanyTest, normalHealthInsurance){
    HealthInsuranceCompany tempHealthInsuranceCompany = HealthInsuranceCompanyExampleFactory::normalHealthInsurance();
    EXPECT_EQ(tempHealthInsuranceCompany.getHealthInsuranceCompany(), "AOK Bayern");
}

TEST(HealthInsuranceCompanyTest, normalHealthInsuranceLowerCase){
    HealthInsuranceCompany tempHealthInsuranceCompany = HealthInsuranceCompanyExampleFactory::normalHealthInsuranceLowerCase();
    EXPECT_EQ(tempHealthInsuranceCompany.getHealthInsuranceCompany(),"AOK Bayern");
}

TEST(HealthInsuranceCompanyTest, emptyHealthInsurance){
    HealthInsuranceCompany tempHealthInsuranceCompany = HealthInsuranceCompanyExampleFactory::emptyHealthInsurance();
    EXPECT_EQ(tempHealthInsuranceCompany.getHealthInsuranceCompany(), "Unknown");
}

TEST(HealthInsuranceCompanyTest, existingHealthInsurance){
    HealthInsuranceCompany tempHealthInsuranceCompany = HealthInsuranceCompanyExampleFactory::existingHealthInsurance();
    EXPECT_EQ(tempHealthInsuranceCompany.getHealthInsuranceCompany(),"BKK VBU");
}

TEST(HealthInsuranceCompanyTest, invalidHealthInsurance){
    HealthInsuranceCompany tempHealthInsuranceCompany = HealthInsuranceCompanyExampleFactory::invalidHealthInsurance();
    EXPECT_EQ(tempHealthInsuranceCompany.getHealthInsuranceCompany(),"Unknown");
}