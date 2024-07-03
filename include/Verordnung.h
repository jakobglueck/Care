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
    Prescription(DoctorName& doctorName,Pharmaceutical& arzneimittel,Address& address, PharmacyName& pharmacyName,
                 ApplicationUnits& applicationUnits, Beleg_Void& belegVoid,
                 OperationalDesignation operationalDesignation, BSNR& bsnr, Date& date,
                 MedicalSpecialty& medicalSpecialty,PharmacyOwner& pharmacyOwner,
                 HealthInsuranceCompany& healthInsuranceCompany,KV_Districts& kvDistricts,LANR& lanr,
                 InsuredPseudonym& insuredPseudonym);
    Prescription();

    void setDoctorName(DoctorName& doctorName);
    void setPharmaceutical(Pharmaceutical& pharmaceutical);
    void setAddress(Address& address);
    void setPharmacyName(PharmacyName& pharmacyName);
    void setApplicationUnits(ApplicationUnits& applicationUnits);
    void setBelegVoid(Beleg_Void& belegVoid);
    void setOperationalDesignation(OperationalDesignation& operationalDesignation);
    void setBSNR(BSNR& bsnr);
    void setDate(Date& date);
    void setMedicalSpecialty(MedicalSpecialty& medicalSpecialty);
    void setPharmacyOwner(PharmacyOwner& pharmacyOwner);
    void setHealthInsuranceCompany(HealthInsuranceCompany& healthInsuranceCompany);
    void setKVDistricts(KV_Districts& kvDistricts);
    void setLANR(LANR& lanr);
    void setInsuredPseudonym(InsuredPseudonym& insuredPseudonym);
    void setPrescriptionStatus(Status::PrescriptionStatus prescriptionStatus);

    DoctorName getDoctorName() const;
    Pharmaceutical getPharmaceutical() const;
    Address getAddress() const;
    PharmacyName getPharmacyName() const;
    ApplicationUnits getApplicationUnits() const;
    Beleg_Void getBelegVoid() const;
    OperationalDesignation getOperationalDesignation() const;
    BSNR getBSNR() const;
    Date getDate() const;
    MedicalSpecialty getMedicalSpecialty() const;
    PharmacyOwner getPharmacyOwner() const;
    HealthInsuranceCompany getHealthInsuranceCompany() const;
    KV_Districts getKVDistricts() const;
    LANR getLANR() const;
    InsuredPseudonym getInsuredPseudonym() const;
    Status::PrescriptionStatus getPrescriptionStatus();

    bool mainValueAreSet();

    bool isEqual(Prescription& prescription);

private:
    DoctorName doctorName;
    Pharmaceutical pharmaceutical;
    Address address;
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