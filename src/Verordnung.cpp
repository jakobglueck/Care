//
// Created by Jakob Glück on 02.07.24.
//

#include "Verordnung.h"

Prescription::Prescription(DoctorName &doctorName, Pharmaceutical &arzneimittel, Address &address,
                           PharmacyName &pharmacyName, ApplicationUnits &applicationUnits, Beleg_Void &belegVoid,
                           OperationalDesignation operationalDesignation, BSNR &bsnr, Date &date,
                           MedicalSpecialty &medicalSpecialty, PharmacyOwner &pharmacyOwner,
                           HealthInsuranceCompany &healthInsuranceCompany, KV_Districts &kvDistricts, LANR &lanr,
                           InsuredPseudonym &insuredPseudonym) {
    this->setDoctorName(doctorName);
    this->setPharmaceutical(arzneimittel);
    this->setAddress(address);
    this->setPharmacyName(pharmacyName);
    this->setApplicationUnits(applicationUnits);
    this->setBelegVoid(belegVoid);
    this->setOperationalDesignation(operationalDesignation);
    this->setBSNR(bsnr);
    this->setDate(date);
    this->setMedicalSpecialty(medicalSpecialty);
    this->setPharmacyOwner(pharmacyOwner);
    this->setHealthInsuranceCompany(healthInsuranceCompany);
    this->setKVDistricts(kvDistricts);
    this->setLANR(lanr);
    this->setInsuredPseudonym(insuredPseudonym);
    if(this->mainValueAreSet()){
        this->setPrescriptionStatus(Status::PrescriptionStatus::Approved);
    }
    else{
        this->setPrescriptionStatus(Status::PrescriptionStatus::Unapproved);
    }
}

Prescription::Prescription() {}

void Prescription::setDoctorName(DoctorName &doctorName) {
    this->doctorName = doctorName;
}

void Prescription::setPharmaceutical(Pharmaceutical &pharmaceutical) {
    this->pharmaceutical = pharmaceutical;
}

void Prescription::setAddress(Address &address) {
    this->address = address;
}

void Prescription::setPharmacyName(PharmacyName &pharmacyName) {
    this->pharmacyName = pharmacyName;
}

void Prescription::setApplicationUnits(ApplicationUnits &applicationUnits) {
    this->applicationUnits = applicationUnits;
}

void Prescription::setBelegVoid(Beleg_Void &belegVoid) {
    this->belegVoid = belegVoid;
}

void Prescription::setOperationalDesignation(OperationalDesignation &operationalDesignation) {
    this->operationalDesignation = operationalDesignation;
}

void Prescription::setBSNR(BSNR &bsnr) {
    this->bsnr = bsnr;
}

void Prescription::setDate(Date &date) {
    this->date = date;
}

void Prescription::setMedicalSpecialty(MedicalSpecialty &medicalSpecialty) {
    this->medicalSpecialty = medicalSpecialty;
}

void Prescription::setPharmacyOwner(PharmacyOwner &pharmacyOwner) {
    this->pharmacyOwner = pharmacyOwner;
}

void Prescription::setHealthInsuranceCompany(HealthInsuranceCompany &healthInsuranceCompany) {
    this->healthInsuranceCompany = healthInsuranceCompany;
}

void Prescription::setKVDistricts(KV_Districts &kvDistricts) {
    this->kvDistricts = kvDistricts;
}

void Prescription::setLANR(LANR &lanr) {
    this->lanr = lanr;
}

void Prescription::setInsuredPseudonym(InsuredPseudonym &insuredPseudonym) {
    this->insuredPseudonym = insuredPseudonym;
}

void Prescription::setPrescriptionStatus(Status::PrescriptionStatus prescriptionStatus) {
    this->prescriptionStatus = prescriptionStatus;
}

DoctorName Prescription::getDoctorName() const {
    return this->doctorName;
}

Pharmaceutical Prescription::getPharmaceutical() const {
    return this->pharmaceutical;
}

Address Prescription::getAddress() const {
    return this->address;
}

PharmacyName Prescription::getPharmacyName() const {
    return this->pharmacyName;
}

ApplicationUnits Prescription::getApplicationUnits() const {
    return this->applicationUnits;
}

Beleg_Void Prescription::getBelegVoid() const {
    return this->belegVoid;
}

OperationalDesignation Prescription::getOperationalDesignation() const {
    return this->operationalDesignation;
}

BSNR Prescription::getBSNR() const {
    return this->bsnr;
}

Date Prescription::getDate() const {
    return this->date;
}

MedicalSpecialty Prescription::getMedicalSpecialty() const {
    return this->medicalSpecialty;
}

PharmacyOwner Prescription::getPharmacyOwner() const {
    return this->pharmacyOwner;
}

HealthInsuranceCompany Prescription::getHealthInsuranceCompany() const {
    return this->healthInsuranceCompany;
}

KV_Districts Prescription::getKVDistricts() const {
    return this->kvDistricts;
}

LANR Prescription::getLANR() const {
    return this->lanr;
}

InsuredPseudonym Prescription::getInsuredPseudonym() const {
    return this->insuredPseudonym;
}

Status::PrescriptionStatus Prescription::getPrescriptionStatus() {
    return this->prescriptionStatus;
}

bool Prescription::mainValueAreSet() {
    if(this->healthInsuranceCompany.isSet() && this->insuredPseudonym.isSet() && this->pharmaceutical.isSet() &&
    this->date.isSet()&& this->belegVoid.isSet()){
        return true;
    }
    else{
        return false;
    }
}

bool Prescription::isEqual(Prescription &prescription) {
    return this->pharmaceutical.isEqual(prescription.pharmaceutical) &&
           this->belegVoid.isEqual(prescription.belegVoid) &&
           this->date.isEqual(prescription.date) &&
           this->healthInsuranceCompany.isEqual(prescription.healthInsuranceCompany) &&
           this->insuredPseudonym.isEqual(prescription.insuredPseudonym) &&
           this->prescriptionStatus == prescription.prescriptionStatus;
}
