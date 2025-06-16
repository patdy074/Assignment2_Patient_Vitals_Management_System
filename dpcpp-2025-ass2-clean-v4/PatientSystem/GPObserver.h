#ifndef GP_OBSERVER_H
#define GP_OBSERVER_H

#include "ObserverAlertNotification.h"

class GPNotificationSystemFacade;

//observer for GP alert notifications.
//notifies the GP system when a patient's alert level becomes RED.

class GPObserver : public ObserverAlertNotification {
public:
    
    //Constructor that accepts a pointer to the GP notification system.
    //gpFacade Pointer to the GP notification system.
    explicit GPObserver(GPNotificationSystemFacade* gpFacade);

    
    //Implementation of update() called by the subject (Patient).
    //patient Pointer to the Patient whose alert level changed.
    void update(Patient* patient) override;

private:
    GPNotificationSystemFacade* _gpFacade;
};

#endif 
