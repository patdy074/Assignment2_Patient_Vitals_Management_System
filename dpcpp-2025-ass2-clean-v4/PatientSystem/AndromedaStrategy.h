#ifndef ANDROMEDASTRATEGY_H
#define ANDROMEDASTRATEGY_H

#include "AlertStrategy.h"

class AndromedaStrategy : public AlertStrategy {
public:
    AlertLevel calculateAlertLevel(const Patient& patient, const Vitals& vitals) const override;
};

#endif
