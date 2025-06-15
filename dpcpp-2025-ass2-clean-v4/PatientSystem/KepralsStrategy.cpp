#include "KepralsStrategy.h"
#include "Patient.h"

AlertLevel KepralsStrategy::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const {
    int heartRate = vitals.HR();
    int age = patient.age();  

    if (age < 12) {
        if (heartRate > 120) return AlertLevel::RED;
    }
    else {
        if (heartRate > 100) return AlertLevel::RED;
    }

    return AlertLevel::GREEN;
}
