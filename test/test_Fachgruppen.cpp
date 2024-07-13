//
// Created by Jakob Glück on 10.07.24.
//

#include "gtest/gtest.h"
#include "include/Fachgruppen_BezeichnungExampleFactory.h"

TEST(MedicalSpecialtyTest, normalMedicalSpecialty){
    MedicalSpecialty tempMedicalSpecialty = MedicalSpecialtyExampleFactory::normalMedicalSpecialty();
    EXPECT_EQ(tempMedicalSpecialty.getMedicalSpecialty(),MedicalSpecialtyExampleFactory::normalMedicalSpecialtyValue());
}

TEST(MedicalSpecialtyTest, invalidMedicalSpecialty_Number){
    MedicalSpecialty tempMedicalSpecialty = MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_Number();
    EXPECT_EQ(tempMedicalSpecialty.getMedicalSpecialty(),"");
}

TEST(MedicalSpecialtyTest, invalidMedicalSpecialty_ZurFreienVerfügung){
    MedicalSpecialty tempMedicalSpecialty = MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_ZurFreienVerfügung();
    EXPECT_EQ(tempMedicalSpecialty.getMedicalSpecialty(),"");
}

TEST(MedicalSpecialtyTest, invalidMedicalSpecialty_HausArzt1){
    MedicalSpecialty tempMedicalSpecialty = MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_HausArzt1();
    EXPECT_EQ(tempMedicalSpecialty.getMedicalSpecialty(),"Innere Medizin");
}

TEST(MedicalSpecialtyTest, invalidMedicalSpecialty_HausArzt2){
    MedicalSpecialty tempMedicalSpecialty = MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_HausArzt2();
    EXPECT_EQ(tempMedicalSpecialty.getMedicalSpecialty(),"Innere Medizin");
}

TEST(MedicalSpecialtyTest, invalidMedicalSpecialty_InSideOfTheValue){
    MedicalSpecialty tempMedicalSpecialty = MedicalSpecialtyExampleFactory::invalidMedicalSpecialty_InSideOfTheValue();
    EXPECT_EQ(tempMedicalSpecialty.getMedicalSpecialty(),"Innere Medizin");
}