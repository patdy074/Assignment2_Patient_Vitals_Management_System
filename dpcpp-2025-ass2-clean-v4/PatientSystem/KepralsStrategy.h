#ifndef KEPRALSSTRATEGY_H
#define KEPRALSSTRATEGY_H

#include "AlertStrategy.h"

class KepralsStrategy : public AlertStrategy {
public:
    AlertLevel calculateAlertLevel(const Patient& patient, const Vitals& vitals) const override;
};

#endif 
