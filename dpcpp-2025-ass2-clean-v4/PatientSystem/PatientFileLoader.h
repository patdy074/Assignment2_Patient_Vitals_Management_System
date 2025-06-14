#pragma once

#include <string>
#include <vector>
#include "AbstractPatientDatabaseLoader.h"

// forward declare the patient class
class Patient;

class PatientFileLoader : public AbstractPatientDatabaseLoader
{
public:
	//adapter that will load patients from a text file.
	void loadPatients(std::vector<Patient*>& patients) override;

	// loads a list of patients from a file and returns a vector of those patients
	std::vector<Patient*> loadPatientFile(const std::string& file);

};

