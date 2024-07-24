#include "Compiler_Excel.h"

#define nullptr NULL

Compiler::Compiler(std::string pfad) {
    this->readFAMData(pfad);
    this->writeFAMData("/Users/jakobgluck/Desktop/workspace/test.xlsx");
}

std::string excelDateToString(double excelDate) {
    std::tm t = {};
    t.tm_year = 1900 - 1900;
    t.tm_mon = 0;
    t.tm_mday = 1;

    t.tm_mday += static_cast<int>(excelDate) - 1;

    std::mktime(&t);

    std::ostringstream oss;
    oss << std::put_time(&t, "%d.%m.%Y");
    return oss.str();
}

void Compiler::readFAMData(std::string pfad) {
    std::locale::global(std::locale("en_US.UTF-8"));

    std::vector<Prescription> fam;

    xlnt::workbook workbook;
    try {
        workbook.load(pfad);
    } catch (const std::exception& e) {
        std::cerr << "Konnte die Excel-Datei nicht öffnen: " << pfad << std::endl;
        return;
    }

    xlnt::worksheet sheet;
    bool sheet_found = false;
    for (auto ws : workbook) {
        if (ws.title() == "FAM ihpE aufbereitet") {
            sheet = ws;
            sheet_found = true;
            break;
        }
    }

    if (!sheet_found) {
        std::cerr << "Konnte das gewünschte Sheet nicht finden." << std::endl;
        return;
    }

    int row_index = 0;
    for (auto row : sheet.rows(false)) {
        if (row_index == 0) {
            row_index++;
            continue;
        }

        Prescription prescription;
        float avk = 0.0;
        int amount = 0;
        std::string insuredPseudonym, pharmaceuticalName, pzn, tempDate, templanr, drtitel, firstName, lastName,
                cityName, cityStreetName, cityPostalCode, pharmacyName, pharmacyPostalCode, pharmacyStreetName,
                pharmacyCityName, bsnr, operationalDesignation, kv_district, medicalSpecialty, belegnr, pharmacyOwner,
                applicationUnits, vo_id;

        int col_index = 0;
        for (auto cell : row) {
            std::string cell_value = cell.to_string();
            switch (col_index) {
                case 1: insuredPseudonym = cell_value; break;
                case 2: pzn = cell_value; break;
                case 3: pharmaceuticalName = cell_value; break;
                case 4: avk = std::stof(cell_value); break;
                case 5:
                    if (cell.has_value() && cell.data_type() == xlnt::cell_type::number) {
                        tempDate = excelDateToString(cell.value<double>());
                    } else {
                        tempDate = cell_value;
                    }
                    break;
                case 6: amount = std::stoi(cell_value); break;
                case 7: templanr = cell_value; break;
                case 8: drtitel = cell_value; break;
                case 9: firstName = cell_value; break;
                case 10: lastName = cell_value; break;
                case 11: cityStreetName = cell_value; break;
                case 12: cityPostalCode = cell_value; break;
                case 13: cityName = cell_value; break;
                case 14: pharmacyName = cell_value; break;
                case 15: pharmacyPostalCode = cell_value; break;
                case 16: pharmacyCityName = cell_value; break;
                case 17: bsnr = cell_value; break;
                case 18: operationalDesignation = cell_value; break;
                case 19: pharmacyStreetName = cell_value; break;
                case 21: kv_district = cell_value; break;
                case 22: medicalSpecialty = cell_value; break;
                case 26: belegnr = cell_value; break;
                case 28: pharmacyOwner = cell_value; break;
                case 29: applicationUnits = cell_value; break;
                case 30: vo_id = cell_value; break;
            }
            col_index++;
        }

        prescription.setHealthInsuranceCompany(HealthInsuranceCompany(pfad));
        prescription.setInsuredPseudonym(InsuredPseudonym(insuredPseudonym));
        prescription.setPharmaceutical(Pharmaceutical(pharmaceuticalName, pzn, Price(avk, amount)));
        prescription.setDate(Date(tempDate, pfad));
        prescription.setLANR(LANR(templanr));
        prescription.setDoctorName(DoctorName(DoctorTitle(drtitel), firstName, lastName));
        PostalCode tempPostalCode = PostalCode(cityPostalCode);
        prescription.setAddress(Address(City(cityName), tempPostalCode, StreetName(cityStreetName)));
        prescription.setPharmacyName(PharmacyName(pharmacyOwner));
        prescription.setPharmacyAddress(Address(City(pharmacyCityName), PostalCode(pharmacyPostalCode), StreetName(pharmacyStreetName)));
        prescription.setBSNR(BSNR(bsnr));
        prescription.setOperationalDesignation(OperationalDesignation(operationalDesignation));
        prescription.setKVDistricts(KV_Districts(kv_district, tempPostalCode.getPostalCode()));
        prescription.setMedicalSpecialty(MedicalSpecialty(medicalSpecialty));
        prescription.setBelegVoid(Beleg_Void(BelegNr(belegnr), VOID(vo_id)));
        prescription.setPharmacyOwner(PharmacyOwner(pharmacyOwner));
        prescription.setApplicationUnits(ApplicationUnits(applicationUnits));
        prescription.setPrescriptionStatus();

        fam.push_back(prescription);
        row_index++;
    }

    this->fam = FAM(fam);
}

void Compiler::writeFAMData(std::string pfad) {
    lxw_workbook  *workbook  = workbook_new(pfad.c_str());
    if (!workbook) {
        std::cerr << "Konnte die Excel-Datei nicht erstellen: " << pfad << std::endl;
        return;
    }

    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, "FAM ihpE aufbereitet");

    lxw_format *format = workbook_add_format(workbook);
    format_set_num_format(format, "0.00");

    const char* headers[] = {
            "kasse", "patnr", "pzn", "am-name", "avk", "vodatum", "anzahl",
            "lanr", "arzt-titel", "arzt-vorname", "arzt-nachname", "arzt-str",
            "arzt-plz", "arzt-ort", "apo-name", "apo-plz", "apo-ort", "bsnr",
            "betriebsbez", "apo-str", "arzt-tel", "kv-Bezirk", "FA-Bezeichnung",
            "rolle", "abrdatum", "lanrmp", "belegnr", "arzt-id", "apo-inhaber",
            "applikationsfertige Einheiten", "vo-id"
    };

    for (int col = 0; col < 31; ++col) {
        worksheet_write_string(worksheet, 0, col, headers[col], nullptr);
    }

    std::vector<Prescription> tempFam = this->fam.getApprovedData();

    for (size_t row = 0; row < tempFam.size(); ++row) {
        Prescription prescription = tempFam[row];

        worksheet_write_string(worksheet, row + 1, 0, prescription.getHealthInsuranceCompany().getHealthInsuranceCompany().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 1, prescription.getInsuredPseudonym().getInsuredPseudonym().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 2, prescription.getPharmaceutical().getPZN().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 3, prescription.getPharmaceutical().getPharmaceuticalName().c_str(), nullptr);
        worksheet_write_number(worksheet, row + 1, 4, prescription.getPharmaceutical().getPrice().getPrice(), format);
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
        worksheet_write_string(worksheet, row + 1, 20, "", nullptr);
        worksheet_write_string(worksheet, row + 1, 21, prescription.getKVDistricts().getValue().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 22, prescription.getMedicalSpecialty().getMedicalSpecialty().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 23, "", nullptr);
        worksheet_write_string(worksheet, row + 1, 24, "", nullptr);
        worksheet_write_string(worksheet, row + 1, 25, prescription.getLANR().getTempLANR().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 26, prescription.getBelegVoid().getBelegNr().getBelegNr().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 27, "", nullptr);
        worksheet_write_string(worksheet, row + 1, 28, prescription.getPharmacyOwner().getPharmacyOwner().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 29, prescription.getApplicationUnits().getApplicationUnits().c_str(), nullptr);
        worksheet_write_string(worksheet, row + 1, 30, prescription.getBelegVoid().getVOID().getVOID().c_str(), nullptr);
    }

    workbook_close(workbook);
}
