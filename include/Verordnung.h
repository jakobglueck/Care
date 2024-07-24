//
// Created by Jakob Glück on 02.07.24.
//

#pragma once

#include "include.h"
#include "Arztname.h"
#include "Arzneimittel.h"
#include "Adresse.h"
#include "Apothekenname.h"
#include "appl_Einheiten.h"
#include "Beleg_Void.h"
#include "Betriebsbezeichnung.h"
#include "BSNR.h"
#include "Datum.h"
#include "Fachgruppen_Bezeichnung.h"
#include "Inhaber.h"
#include "Krankenkasse.h"
#include "KV_Bezirk.h"
#include "LANR.h"
#include "Versichertenpsyeudonym.h"

namespace Status{
    enum PrescriptionStatus{
        Unapproved,
        Approved,
    };
}


class Prescription{
public:
    Prescription(DoctorName doctorName,Pharmaceutical pharmaceutical,Address address, PharmacyName pharmacyName,
                 ApplicationUnits applicationUnits, Beleg_Void belegVoid,
                 OperationalDesignation operationalDesignation, BSNR bsnr, Date date,
                 MedicalSpecialty medicalSpecialty,PharmacyOwner pharmacyOwner,Address pharmacyAddress,
                 HealthInsuranceCompany healthInsuranceCompany,KV_Districts kvDistricts,LANR lanr,
                 InsuredPseudonym insuredPseudonym);
    Prescription();

    void setDoctorName(DoctorName doctorName);
    void setPharmaceutical(Pharmaceutical pharmaceutical);
    void setAddress(Address address);
    void setPharmacyAddress(Address pharmacyAddress);
    void setPharmacyName(PharmacyName pharmacyName);
    void setApplicationUnits(ApplicationUnits applicationUnits);
    void setBelegVoid(Beleg_Void belegVoid);
    void setOperationalDesignation(OperationalDesignation operationalDesignation);
    void setBSNR(BSNR bsnr);
    void setDate(Date date);
    void setMedicalSpecialty(MedicalSpecialty medicalSpecialty);
    void setPharmacyOwner(PharmacyOwner pharmacyOwner);
    void setHealthInsuranceCompany(HealthInsuranceCompany healthInsuranceCompany);
    void setKVDistricts(KV_Districts kvDistricts);
    void setLANR(LANR lanr);
    void setInsuredPseudonym(InsuredPseudonym insuredPseudonym);
    void setPrescriptionStatus();

    DoctorName getDoctorName();
    Pharmaceutical getPharmaceutical();
    Address getAddress();
    Address getPharmacyAddress();
    PharmacyName getPharmacyName();
    ApplicationUnits getApplicationUnits();
    Beleg_Void getBelegVoid();
    OperationalDesignation getOperationalDesignation();
    BSNR getBSNR() ;
    Date getDate();
    MedicalSpecialty getMedicalSpecialty();
    PharmacyOwner getPharmacyOwner();
    HealthInsuranceCompany getHealthInsuranceCompany();
    KV_Districts getKVDistricts();
    LANR getLANR();
    InsuredPseudonym getInsuredPseudonym();
    Status::PrescriptionStatus getPrescriptionStatus();

    bool mainValueAreSet();

    bool isEqual(Prescription& prescription);

private:
    DoctorName doctorName;
    Pharmaceutical pharmaceutical;
    Address address;
    Address pharmacyAddress;
    PharmacyName pharmacyName;
    ApplicationUnits applicationUnits;
    Beleg_Void belegVoid;
    OperationalDesignation operationalDesignation;
    BSNR bsnr;
    Date date;
    MedicalSpecialty medicalSpecialty;
    PharmacyOwner pharmacyOwner;
    HealthInsuranceCompany healthInsuranceCompany;
    KV_Districts kvDistricts;
    LANR lanr;
    InsuredPseudonym insuredPseudonym;
    Status::PrescriptionStatus prescriptionStatus;
};