#ifndef HOSPITAL_OBSERVER_H
#define HOSPITAL_OBSERVER_H

#include "ObserverAlertNotification.h"

class HospitalAlertSystemFacade;


 //observer for hospital alert notifications.
 //notifies the hospital system when a patient's alert level becomes RED.
class HospitalObserver : public ObserverAlertNotification {
public:
    
    //constructor that accepts a pointer to the HospitalAlertSystemFacade.
    //hospitalFacade Pointer to the hospital alert system.
     explicit HospitalObserver(HospitalAlertSystemFacade* hospitalFacade);

    
    //iplementation of update() called by the subject (Patient).
    //patient Pointer to the Patient whose alert level changed.
    void update(Patient* patient) override;

private:
    HospitalAlertSystemFacade* _hospitalFacade;
};

#endif 
