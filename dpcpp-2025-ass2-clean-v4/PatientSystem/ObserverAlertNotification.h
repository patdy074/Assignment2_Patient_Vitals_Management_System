#ifndef OBSERVER_ALERT_NOTIFICATION_H
#define OBSERVER_ALERT_NOTIFICATION_H


class Patient;


//abstract Observer interface for receiving patient alert notifications.
//classes such as HospitalObserver and GPObserver will implement this interface.

class ObserverAlertNotification {
public:
    //virtual destructor for safe polymorphic deletion.
     
    virtual ~ObserverAlertNotification() = default;

    
     //called when a Patient’s alert level changes to RED.
     //patient Pointer to the Patient object whose alert level changed.
    virtual void update(Patient* patient) = 0;
};

#endif 
