#include "GPObserver.h"
#include "GPNotificationSystemFacade.h"

GPObserver::GPObserver(GPNotificationSystemFacade* gpFacade)
    : _gpFacade(gpFacade)
{
}

void GPObserver::update(Patient* patient)
{
    if (_gpFacade != nullptr) {
        _gpFacade->sendGPNotificationForPatient(patient);
    }
}
