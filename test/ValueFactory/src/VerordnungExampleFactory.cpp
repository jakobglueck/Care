//
// Created by Jakob Glück on 12.07.24.
//

#include "include/VerordnungExampleFactory.h"

Prescription PrescriptionExampleFactory::normalPrescription() {
    DoctorTitle doc = DoctorTitle("Dr. med.");
    DoctorName doctorName = DoctorName(doc, "Markus", "Miller");

    Price price = Price(122.22, 2);
    Pharmaceutical pharmaceutical = Pharmaceutical("Erstes Medikemant", "9999100", price);

    City city = City("Naumburg");
    PostalCode postalCode = PostalCode("06618");
    StreetName streetName = StreetName("Richardwagnerstraße 34");
    Address address = Address(city, postalCode, streetName);

    PharmacyName pharmacyName = PharmacyName("Markus Schiller e.V.");

    ApplicationUnits applicationUnits = ApplicationUnits("2");

    VOID aVoid = VOID("23452435");
    BelegNr belegNr = BelegNr("");
    Beleg_Void belegVoid = Beleg_Void(belegNr, aVoid);

    OperationalDesignation operationalDesignation = OperationalDesignation("Uniklinikum Berlin GmbH");

    BSNR bsnr = BSNR("1234563");

    Date date = Date("12.04.2023", "AOK Bayern_01012024_01.23-12.23");

    MedicalSpecialty medicalSpecialty = MedicalSpecialty("Onkologie");

    PharmacyOwner pharmacyOwner = PharmacyOwner("Markus Schiller");

    HealthInsuranceCompany healthInsuranceCompany = HealthInsuranceCompany("AOK Bayern_01012024_01.23-12.23");

    KV_Districts kvDistricts = KV_Districts("Naumburg", "06618");

    LANR lanr = LANR("23456234");

    InsuredPseudonym insuredPseudonym = InsuredPseudonym("faf2435413");

    Address pharmacyAddress = Address(city, postalCode, streetName);

    return Prescription(
            doctorName,
            pharmaceutical,
            address,
            pharmacyName,
            applicationUnits,
            belegVoid,
            operationalDesignation,
            bsnr,
            date,
            medicalSpecialty,
            pharmacyOwner,
            pharmacyAddress,
            healthInsuranceCompany,
            kvDistricts,
            lanr,
            insuredPseudonym
    );
}

Prescription PrescriptionExampleFactory::invalidPrescription() {
    DoctorTitle doc = DoctorTitle("Dr. med.");
    DoctorName doctorName = DoctorName(doc, "Markus", "Miller");

    Price price = Price(0.00, 2);
    Pharmaceutical pharmaceutical = Pharmaceutical("Erstes Medikemant", "9999100", price);

    City city = City("Naumburg");
    PostalCode postalCode = PostalCode("06618");
    StreetName streetName = StreetName("Richardwagnerstraße 34");
    Address address = Address(city, postalCode, streetName);

    PharmacyName pharmacyName = PharmacyName("Markus Schiller e.V.");

    ApplicationUnits applicationUnits = ApplicationUnits("2");

    VOID aVoid = VOID("23452435");
    BelegNr belegNr = BelegNr("");
    Beleg_Void belegVoid = Beleg_Void(belegNr, aVoid);

    OperationalDesignation operationalDesignation = OperationalDesignation("Uniklinikum Berlin GmbH");

    BSNR bsnr = BSNR("1234563");

    Date date = Date("12.04.2023", "AOK Bayern_01012024_01.23-12.23");

    MedicalSpecialty medicalSpecialty = MedicalSpecialty("Onkologie");

    PharmacyOwner pharmacyOwner = PharmacyOwner("Markus Schiller");

    HealthInsuranceCompany healthInsuranceCompany = HealthInsuranceCompany("AOK Bayern_01012024_01.23-12.23");

    KV_Districts kvDistricts = KV_Districts("Naumburg", "06618");

    LANR lanr = LANR("23456234");

    InsuredPseudonym insuredPseudonym = InsuredPseudonym("faf2435413");

    Address pharmacyAddress = Address(city, postalCode, streetName);

    return Prescription(
            doctorName,
            pharmaceutical,
            address,
            pharmacyName,
            applicationUnits,
            belegVoid,
            operationalDesignation,
            bsnr,
            date,
            medicalSpecialty,
            pharmacyOwner,
            pharmacyAddress,
            healthInsuranceCompany,
            kvDistricts,
            lanr,
            insuredPseudonym
    );
}