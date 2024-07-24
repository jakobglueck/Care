//
// Created by Jakob Glück on 02.07.24.
//

#include "Verordnung.h"

Prescription::Prescription(DoctorName doctorName,Pharmaceutical pharmaceutical,Address address, PharmacyName pharmacyName,
                           ApplicationUnits applicationUnits, Beleg_Void belegVoid,
                           OperationalDesignation operationalDesignation, BSNR bsnr, Date date,
                           MedicalSpecialty medicalSpecialty,PharmacyOwner pharmacyOwner,Address pharmacyAddress,
                           HealthInsuranceCompany healthInsuranceCompany,KV_Districts kvDistricts,LANR lanr,
                           InsuredPseudonym insuredPseudonym){
    this->setDoctorName(doctorName);
    this->setPharmaceutical(pharmaceutical);
    this->setAddress(address);
    this->setPharmacyAddress(pharmacyAddress);
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
    this->setPrescriptionStatus();

}

Prescription::Prescription() {}

void Prescription::setDoctorName(DoctorName doctorName) {
    this->doctorName = doctorName;
}

void Prescription::setPharmaceutical(Pharmaceutical pharmaceutical) {
    this->pharmaceutical = pharmaceutical;
}


void Prescription::setAddress(Address address) {
    this->address = address;
}

void Prescription::setPharmacyAddress(Address pharmacyAddress) {
    this->pharmacyAddress = pharmacyAddress;
}

void Prescription::setPharmacyName(PharmacyName pharmacyName) {
    this->pharmacyName = pharmacyName;
}

void Prescription::setApplicationUnits(ApplicationUnits applicationUnits) {
    this->applicationUnits = applicationUnits;
}

void Prescription::setBelegVoid(Beleg_Void belegVoid) {
    this->belegVoid = belegVoid;
}

void Prescription::setOperationalDesignation(OperationalDesignation operationalDesignation) {
    this->operationalDesignation = operationalDesignation;
}

void Prescription::setBSNR(BSNR bsnr) {
    this->bsnr = bsnr;
}

void Prescription::setDate(Date date) {
    this->date = date;
}

void Prescription::setMedicalSpecialty(MedicalSpecialty medicalSpecialty) {
    this->medicalSpecialty = medicalSpecialty;
}

void Prescription::setPharmacyOwner(PharmacyOwner pharmacyOwner) {
    this->pharmacyOwner = pharmacyOwner;
}

void Prescription::setHealthInsuranceCompany(HealthInsuranceCompany healthInsuranceCompany) {
    this->healthInsuranceCompany = healthInsuranceCompany;
}

void Prescription::setKVDistricts(KV_Districts kvDistricts) {
    this->kvDistricts = kvDistricts;
}

void Prescription::setLANR(LANR lanr) {
    this->lanr = lanr;
}

void Prescription::setInsuredPseudonym(InsuredPseudonym insuredPseudonym) {
    this->insuredPseudonym = insuredPseudonym;
}

void Prescription::setPrescriptionStatus() {
    if(this->mainValueAreSet()){
        this->prescriptionStatus =  Status::PrescriptionStatus::Approved;
    }
    else{
        this->prescriptionStatus =Status::PrescriptionStatus::Unapproved;
    }
}

DoctorName Prescription::getDoctorName() {
    return this->doctorName;
}

Pharmaceutical Prescription::getPharmaceutical() {
    return this->pharmaceutical;
}

Address Prescription::getAddress() {
    return this->address;
}

Address Prescription::getPharmacyAddress(){
    return this->pharmacyAddress;
}

PharmacyName Prescription::getPharmacyName() {
    return this->pharmacyName;
}

ApplicationUnits Prescription::getApplicationUnits() {
    return this->applicationUnits;
}

Beleg_Void Prescription::getBelegVoid() {
    return this->belegVoid;
}

OperationalDesignation Prescription::getOperationalDesignation() {
    return this->operationalDesignation;
}

BSNR Prescription::getBSNR() {
    return this->bsnr;
}

Date Prescription::getDate() {
    return this->date;
}

MedicalSpecialty Prescription::getMedicalSpecialty() {
    return this->medicalSpecialty;
}

PharmacyOwner Prescription::getPharmacyOwner() {
    return this->pharmacyOwner;
}

HealthInsuranceCompany Prescription::getHealthInsuranceCompany() {
    return this->healthInsuranceCompany;
}

KV_Districts Prescription::getKVDistricts() {
    return this->kvDistricts;
}

LANR Prescription::getLANR() {
    return this->lanr;
}

InsuredPseudonym Prescription::getInsuredPseudonym() {
    return this->insuredPseudonym;
}

Status::PrescriptionStatus Prescription::getPrescriptionStatus() {
    return this->prescriptionStatus;
}

bool Prescription::mainValueAreSet() {
    if(this->healthInsuranceCompany.isSet() && this->insuredPseudonym.isSet() && this->pharmaceutical.isSet() &&
    this->date.isSet()&& this->belegVoid.isSet() ){
        return true;
    }
    else{
        return false;
    }
}

bool Prescription::isEqual(Prescription& prescription) {
    return this->pharmaceutical.isEqual(prescription.pharmaceutical) &&
           this->belegVoid.isEqual(prescription.belegVoid) &&
           this->date.isEqual(prescription.date) &&
           this->healthInsuranceCompany.isEqual(prescription.healthInsuranceCompany) &&
           this->insuredPseudonym.isEqual(prescription.insuredPseudonym) &&
           this->prescriptionStatus == prescription.prescriptionStatus;
}