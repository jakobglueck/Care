//
// Created by Jakob Glück on 03.06.24.
//

#include <vector>
#include <iostream>

class PharmacyName {
public:
    PharmacyName(std::string &pharmacyName);
    PharmacyName();

    void setPharmacyName(const std::string &pharmacyName);
    std::string getPharmacyName() const;

private:
    bool detectNameAttachment(const std::string &pharmacyName) const;
    void removeNameAttachments(std::string &pharmacyName) const;

    std::string pharmacyName;
};
