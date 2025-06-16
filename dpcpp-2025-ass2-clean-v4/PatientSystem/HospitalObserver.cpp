#include "HospitalObserver.h"
#include "HospitalAlertSystemFacade.h"

HospitalObserver::HospitalObserver(HospitalAlertSystemFacade* hospitalFacade)
    : _hospitalFacade(hospitalFacade)
{
}

void HospitalObserver::update(Patient* patient)
{
    if (_hospitalFacade != nullptr) {
        _hospitalFacade->sendAlertForPatient(patient);
    }
}
