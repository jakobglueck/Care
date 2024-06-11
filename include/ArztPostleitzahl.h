//
// Created by Jakob Glück on 29.05.24.
//
#include <iostream>
#include <regex>
#pragma once

class PostalCode{

public:
    PostalCode(std::string& postalCode);
    PostalCode();

    void setPostalCode(std::string& postalCode);

    std::string getPostalCode();

    bool checkPostalCode(std::string& postalCode);

    std::string& correctPostalCode(std::string& postalCode);

private:
    std::string postalCode;
};