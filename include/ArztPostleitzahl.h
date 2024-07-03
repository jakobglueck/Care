//
// Created by Jakob Glück on 29.05.24.
//

#pragma once

#include "include.h"

class PostalCode{

public:
    PostalCode(std::string& postalCode);
    PostalCode();

    void setPostalCode(std::string& postalCode);

    std::string getPostalCode();

    bool isEqual(PostalCode& postalCode);

private:
    bool checkPostalCode(std::string& postalCode);

    std::string& correctPostalCode(std::string& postalCode);

    std::string postalCode;
};