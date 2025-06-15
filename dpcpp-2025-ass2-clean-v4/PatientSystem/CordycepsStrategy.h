#ifndef CORDYCEPSSTRATEGY_H
#define CORDYCEPSSTRATEGY_H

#include "AlertStrategy.h"

class CordycepsStrategy : public AlertStrategy {
public:
    AlertLevel calculateAlertLevel(const Patient& patient, const Vitals& vitals) const override;
};

#endif
