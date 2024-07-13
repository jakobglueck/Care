//
// Created by Jakob Glück on 12.07.24.
//

#include "Compiler_Excel.h"

#define nullptr NULL

Compiler::Compiler(std::string pfad) {
    this->readFAMData(pfad);
}

void Compiler::readFAMData(std::string pfad) {
    std::vector<Prescription> fam;

    xls::xlsWorkBook* workbook =  xls::xls_open(pfad.c_str(), "UTF-8");
    if (!workbook) {
        std::cerr << "Konnte die Excel-Datei nicht öffnen: " << pfad << std::endl;
        return;
    }

    xls::xlsWorkSheet* sheet = nullptr;
    for (int i = 0; i < workbook->sheets.count; ++i) {
        xls::xlsWorkSheet* tempSheet = xls_getWorkSheet(workbook, i);
        xls_parseWorkSheet(tempSheet);
        if (strcmp((char*)tempSheet, "FAM ihpE aufbereitet") == 0) {
            sheet = tempSheet;
            break;
        }
    }

    if (!sheet) {
        std::cerr << "Konnte das gewünschte Sheet nicht finden." << std::endl;
        xls_close_WB(workbook);
        return;
    }

    for (uint32_t row = 1; row <= sheet->rows.lastrow; ++row) {
        Prescription prescription;
        float avk;
        int amount;
        std::string insuredPseudonym, pharmaceuticalName, pzn, tempDate, templanr, drtitel, firstName, lastName,
        cityName, cityStreetName, cityPostalCode, pharmacyName, pharmacyPostalCode, pharmacyStreetName,pharmacyCityName,
        bsnr, operationalDesignation, kv_district, medicalSpecialty, belegnr, pharmacyOwner, applicationUnits, vo_id;

        for (uint32_t col = 0; col <= 30; ++col) {
            xls::xlsCell* cell = xls_cell(sheet, row, col);
            if (cell) {
                if (col == 1) {
                    insuredPseudonym = (char*)cell->str;
                }
                if (col == 2) {
                    pzn = (char*)cell->str;
                }
                if (col == 3) {
                    pharmaceuticalName = (char*)cell->str;
                }
                if (col == 4) {
                    avk = cell->d;
                }
                if (col == 5) {
                    tempDate = (char*)cell->str;
                }
                if (col == 6) {
                    amount = cell->d;
                }
                if (col == 7) {
                    templanr = (char*)cell->str;
                }
                if (col == 8) {
                    drtitel = (char*)cell->str;
                }
                if (col == 9) {
                    firstName = (char*)cell->str;
                }
                if (col == 10) {
                    lastName = (char*)cell->str;
                }
                if (col == 11) {
                    cityStreetName = (char*)cell->str;
                }
                if (col == 12) {
                    cityPostalCode = (char*)cell->str;
                }
                if (col == 13) {
                    cityName = (char*)cell->str;
                }
                if (col == 14) {
                    pharmacyName = (char*)cell->str;
                }
                if (col == 15) {
                    pharmacyPostalCode = (char*)cell->str;
                }
                if (col == 16) {
                    pharmacyCityName = (char*)cell->str;
                }
                if (col == 17) {
                    bsnr = (char*)cell->str;
                }
                if (col == 18) {
                    operationalDesignation = (char*)cell->str;
                }
                if (col == 19) {
                    pharmacyStreetName = (char*)cell->str;
                }
                if (col == 21) {
                    kv_district = (char*)cell->str;
                }
                if (col == 22) {
                    medicalSpecialty = (char*)cell->str;
                }
                if (col == 26) {
                    belegnr = (char*)cell->str;
                }
                if (col == 28) {
                    pharmacyOwner = (char*)cell->str;
                }
                if (col == 29) {
                    applicationUnits = (char*)cell->str;
                }
                if (col == 30) {
                    vo_id= (char*)cell->str;
                }
            }
        }
        prescription.setHealthInsuranceCompany(HealthInsuranceCompany(pfad));

        prescription.setInsuredPseudonym(InsuredPseudonym(insuredPseudonym));

        prescription.setPharmaceutical(Pharmaceutical(pharmaceuticalName, pzn, Price(avk,amount)));

        prescription.setDate(Date(tempDate,pfad));

        prescription.setLANR(LANR(templanr));

        prescription.setDoctorName(DoctorName(DoctorTitle(drtitel), firstName, lastName));

        PostalCode tempPostalCode = PostalCode(cityPostalCode);
        prescription.setAddress(Address(City(cityName),tempPostalCode,
                                        StreetName(cityStreetName)));

        prescription.setPharmacyName(PharmacyName(pharmacyOwner));

        prescription.setPharmacyAddress(Address(City(pharmacyCityName),
                                                PostalCode(pharmacyPostalCode),StreetName(pharmacyStreetName)));

        prescription.setBSNR(BSNR(bsnr));

        prescription.setOperationalDesignation(OperationalDesignation(operationalDesignation));

        prescription.setKVDistricts(KV_Districts(kv_district,tempPostalCode.getPostalCode()));

        prescription.setMedicalSpecialty(MedicalSpecialty(medicalSpecialty));

        prescription.setBelegVoid(Beleg_Void(BelegNr(belegnr),VOID(vo_id)));

        prescription.setPharmacyOwner(PharmacyOwner(pharmacyOwner));

        prescription.setApplicationUnits(ApplicationUnits(applicationUnits));

        fam.push_back(prescription);
    }
    this->fam = FAM(fam);

    xls_close_WS(sheet);
    xls_close_WB(workbook);
}

void Compiler::writeFAMData(std::string pfad) {
    lxw_workbook  *workbook  = workbook_new(pfad.c_str());
    if (!workbook) {
        std::cerr << "Konnte die Excel-Datei nicht erstellen: " << pfad << std::endl;
        return;
    }

    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, "FAM ihpE aufbereitet");

    const char* headers[] = {
            "kasse", "patnr", "pzn", "am-name", "avk", "vodatum", "anzahl",
            "lanr", "arzt-titel", "arzt-vorname", "arzt-nachname", "arzt-str",
            "arzt-plz", "arzt-ort", "apo-name", "apo-plz", "apo-ort", "bsnr",
            "betriebsbez", "apo-str", "arzt-tel", "kv-Bezirk", "FA-Bezeichnung",
            "rolle", "abrdatum", "lanrmp", "belegnr", "arzt-id", "apo-inhaber",
            "applikationsfertige Einheiten", "vo-id"
    };

    for (int col = 0; col < 32; ++col) {
        worksheet_write_string(worksheet, 0, col, headers[col], nullptr);
    }

    std::vector<Prescription> tempFam = this->fam.getApprovedData();

    for (size_t row = 0; row < tempFam.size(); ++row) {
        Prescription prescription = tempFam[row];

        worksheet_write_string(worksheet, row + 1, 0, prescription.getHealthInsuranceCompany().getHealthInsuranceCompany().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 1, prescription.getInsuredPseudonym().getInsuredPseudonym().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 2, prescription.getPharmaceutical().getPZN().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 3, prescription.getPharmaceutical().getPharmaceuticalName().c_str(), nullptr);
        worksheet_write_number(worksheet, row + 1, 4, prescription.getPharmaceutical().getPrice().getPrice(), nullptr);
        worksheet_write_string(worksheet, row + 1, 5, prescription.getDate().getDate().c_str(), nullptr);
        worksheet_write_number(worksheet, row + 1, 6, prescription.getPharmaceutical().getPrice().getAmount(), nullptr);
        worksheet_write_string(worksheet, row + 1, 7, prescription.getLANR().getLANR().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 8, prescription.getDoctorName().getDoctorTitle().getDoctorTitle().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 9, prescription.getDoctorName().getVorname().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 10, prescription.getDoctorName().getNachname().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 11, prescription.getAddress().getStreetName().getStreetName().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 12, prescription.getAddress().getPostalCode().getPostalCode().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 13, prescription.getAddress().getCity().getCityName().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 14, prescription.getPharmacyName().getPharmacyName().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 15, prescription.getPharmacyAddress().getPostalCode().getPostalCode().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 16, prescription.getPharmacyAddress().getCity().getCityName().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 17, prescription.getBSNR().getBSNR().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 18, prescription.getOperationalDesignation().getOperationalDesignation().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 19, prescription.getPharmacyAddress().getStreetName().getStreetName().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 20, "", nullptr);  // arzt-tel is empty
        worksheet_write_string(worksheet, row + 1, 21, prescription.getKVDistricts().getValue().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 22, prescription.getMedicalSpecialty().getMedicalSpecialty().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 23, "", nullptr);  // rolle is empty
        worksheet_write_string(worksheet, row + 1, 24, "", nullptr);  // abrdaten is empty
        worksheet_write_string(worksheet, row + 1, 25, prescription.getLANR().getTempLANR().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 26, prescription.getBelegVoid().getBelegNr().getBelegNr().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 27, "", nullptr);  // arzt-id is empty
        worksheet_write_string(worksheet, row + 1, 28, prescription.getPharmacyOwner().getPharmacyOwner().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 29, prescription.getApplicationUnits().getApplicationUnits().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 30, prescription.getBelegVoid().getVOID().getVOID().c_str(), nullptr);
    }

    workbook_close(workbook);
}