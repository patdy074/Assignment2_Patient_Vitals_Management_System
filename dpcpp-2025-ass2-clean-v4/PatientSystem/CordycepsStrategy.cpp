#include "CordycepsStrategy.h"

AlertLevel CordycepsStrategy::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const {
    int RR = vitals.respiratoryRate();
    if (RR > 40)
        return AlertLevel::RED;
    else if (RR > 30)
        return AlertLevel::ORANGE;
    else if (RR > 20)
        return AlertLevel::YELLOW;
    else
        return AlertLevel::GREEN;
}
