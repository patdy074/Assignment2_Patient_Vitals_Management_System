#pragma once
#include "Person.h"

#include <memory>
#include <vector>

#include "PatientAlertLevels.h"
#include "AlertStrategy.h"

#include "ObserverAlertNotification.h"



//forward declare classes
class Vitals;

class Diagnosis {
public:
	static const std::string CORDYCEPS_BRAIN_INFECTION;
	static const std::string KEPRALS_SYNDROME;
	static const std::string ANDROMEDA_STRAIN;
};

class Patient : public Person {
public:

	Patient(const std::string& firstName, const std::string& lastName, std::tm birthday);

	//return a calculated age for the patient
	//this calculation is not accurate, but is suitable for assignment purposes
	int age() const;

	//return a "unique" ID generated for the patient
	//this id is generated purely from patient details, and as such may have collisions
	std::string uid() const;
	
	//returns a "nice" ID for humans to interpret: lastname, firstname (UID)
	std::string humanReadableID() const;

	//patients have diagnoses of a disease
	//Note: the initial design consider multiple diagnoses added using addDiagnosis.
	//This was refactored to only consider the primary (i.e. the first) diagnosis.
	void addDiagnosis(const std::string& diagnosis);
	const std::string& primaryDiagnosis() const;

	//add a vitals mesaurements record to the patient
	void addVitals(const Vitals* v);
	const std::vector<const Vitals*> vitals() const;

	//patients have an alert level (green, yellow, orange, red) calculated from their disease and and their last vitals
	void setAlertLevel(AlertLevel level);
	const AlertLevel alertLevel() const { return _alertLevel; }

	//for debug/test access only
	/// @brief Returns the patient's first name (for internal/debug use)
	std::string getFirstName() const { return _firstName; }

	/// @brief Returns the patient's last name (for internal/debug use)
	std::string getLastName() const { return _lastName; }

	/// @brief Returns the patient's primary diagnosis (for internal/debug use)
	std::string getDiagnosis() const { return primaryDiagnosis(); }

	/// @brief Returns all vitals recorded for the patient (for internal/debug use)
	std::vector<const Vitals*> getAllVitals() const { return _vitals; }

    void configureAlertStrategy();

	//registers an observer for this patient and observer Pointer to an ObserverAlertNotification implementation.
	void attachObserver(ObserverAlertNotification* observer); 



protected:
	std::vector<std::string> _diagnosis;
	std::vector<const Vitals*> _vitals;
	AlertLevel _alertLevel;

	friend std::ostream& operator<<(std::ostream& os, const Patient& p);
	std::unique_ptr<AlertStrategy> _alertStrategy;

	void notifyObservers();//all attached observers when alert level becomes RED.
	std::vector<ObserverAlertNotification*> _observers;

};

