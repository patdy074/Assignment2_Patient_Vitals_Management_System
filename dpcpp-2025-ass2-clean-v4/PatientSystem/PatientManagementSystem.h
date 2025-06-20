#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>


//forward declare several classes
class AbstractPatientDatabaseLoader;
class HospitalAlertSystemFacade;
class GPNotificationSystemFacade;
class Patient;


class PatientManagementSystem
{
public:

	PatientManagementSystem();
	~PatientManagementSystem();

	//initialise the patient records
	void init();
	void run();

	//ask the user for a patient and vitals and add those vitals to the patient
	void addVitalsRecord();

	void printWelcomeMessage() const;
	void printMainMenu() const;
	void printPatients() const;
    //setter method for the loader
	void setLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader);



protected:
	std::vector<Patient*> _patients;
	std::map<std::string, Patient*> _patientLookup;

	std::unique_ptr<HospitalAlertSystemFacade> _hospitalAlertSystem;
	std::unique_ptr<GPNotificationSystemFacade> _gpNotificationSystem;
	std::shared_ptr<AbstractPatientDatabaseLoader> _patientDatabaseLoader;

};

