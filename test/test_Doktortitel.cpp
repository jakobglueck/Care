#include <gtest/gtest.h>
#include "include/DoktortitelExampleFactory.h"

TEST(DoktorTitleTest, TestWithAllowedDrDr) {
    DoctorTitle doctor = DoctorTitleExampleFactory::DR_DR_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(),"Dr.Dr.");
}

TEST(DoktorTitleTest, TestWithAllowedDr) {
    DoctorTitle doctor = DoctorTitleExampleFactory::DR_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(), "Dr.");
}

TEST(DoktorTitleTest, TestWithAllowedDr_Med) {
    DoctorTitle doctor = DoctorTitleExampleFactory::DR_MED_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(), "Dr.");
}

TEST(DoktorTitleTest, TestWithAllowedDr_MedWithSpace) {
    DoctorTitle doctor = DoctorTitleExampleFactory::DR_MED_WithSpace_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(), "Dr.");
}

TEST(DoktorTitleTest, TestWithAllowedPD) {
    DoctorTitle doctor = DoctorTitleExampleFactory::PD_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(), "PD Dr.");
}

TEST(DoktorTitleTest, TestWithAllowedProf_Dr) {
    DoctorTitle doctor = DoctorTitleExampleFactory::PROF_DR_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(), "Prof.Dr.");
}

TEST(DoktorTitleTest, TestWithAllowedProf_Dr_Dr) {
    DoctorTitle doctor = DoctorTitleExampleFactory::PROF_DR_DR_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(), "Prof.Dr.Dr.");
}

TEST(DoktorTitleTest, TestWithAllowedNotTitle) {
    DoctorTitle doctor = DoctorTitleExampleFactory::NO_TITLE_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(), "");
}

TEST(DoktorTitleTest, TestWithAllowedWrittenDR) {
    DoctorTitle doctor = DoctorTitleExampleFactory::DR_WRITTEN_Constructor();
    EXPECT_EQ(doctor.getDoctorTitle(), "Dr.");
}
