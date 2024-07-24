//
// Created by Jakob Glück on 03.07.24.
//

#include "FAM_SHEET.h"

FAM::FAM(std::vector<Prescription> database) {
    this->setDatabase(database);

    for (size_t i = 0; i < database.size(); i++) {
        bool isDuplicate = false;
        for (size_t j = 0; j < i; j++) {
            if (database[i].isEqual(database[j])) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate) {
            this->unapprovedData.push_back(database[i]);
        } else {
            if (database[i].getPrescriptionStatus() == Status::PrescriptionStatus::Unapproved) {
                this->unapprovedData.push_back(database[i]);
            } else {
                this->approvedData.push_back(database[i]);
            }
        }
    }
}

FAM::FAM() {}

void FAM::setDatabase(std::vector<Prescription> &database) {
     this->database = database;
}

void FAM::setApprovedData(std::vector<Prescription> &approvedData) {
    this->approvedData = approvedData;
}

void FAM::setUnapprovedData(std::vector<Prescription> &unapprovedData) {
    this->unapprovedData = unapprovedData;
}

std::vector<Prescription> FAM::getDatabase() {
    return this->database;
}

std::vector<Prescription> FAM::getApprovedData() {
    return this->approvedData;
}

std::vector<Prescription> FAM::getUnapprovedData() {
    return this->unapprovedData;
}