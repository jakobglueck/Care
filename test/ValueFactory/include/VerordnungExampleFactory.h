//
// Created by Jakob Glück on 12.07.24.
//

#pragma once

#include "Verordnung.h"

class PrescriptionExampleFactory{
public:
    static Prescription normalPrescription();
    static Prescription invalidPrescription();

};