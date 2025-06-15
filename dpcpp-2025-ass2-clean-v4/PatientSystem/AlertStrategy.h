#ifndef ALERTSTRATEGY_H
#define ALERTSTRATEGY_H

#include "Vitals.h"
#include "PatientAlertLevels.h"

#include <memory>

class Patient;

class AlertStrategy {
public:
    virtual ~AlertStrategy() = default;

    
     //Calculates the AlertLevel for a patient based on the latest Vitals.
     //The strategy should return GREEN if the patient does not meet disease-specific criteria.
     
    virtual AlertLevel calculateAlertLevel(const Patient& patient, const Vitals& vitals) const = 0;
};

#endif
