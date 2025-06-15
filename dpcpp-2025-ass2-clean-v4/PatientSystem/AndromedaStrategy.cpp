#include "AndromedaStrategy.h"

AlertLevel AndromedaStrategy::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const {
    int bp = vitals.BP();

    if (bp > 140)
        return AlertLevel::RED;
    else if (bp > 130)
        return AlertLevel::ORANGE;
    else if (bp > 110)
        return AlertLevel::YELLOW;
    else
        return AlertLevel::GREEN;
}
