//
// Created by Jakob Glück on 03.06.24.
//

#pragma once
#include <iostream>
#include <regex>

class LANR {
public:
    LANR(std::string& lanr);
    LANR();

    void setLANR(const std::string& lanr);
    void setTempLANR(const std::string& lanr);

    std::string getLANR() const;
    std::string getTempLANR() const;

private:
    bool detectInvalidLANR(const std::string& lanr) const;
    std::string removeLANR(const std::string& lanr) const;

    std::string lanr;
    std::string templanr;
};