// PatientSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <string>

#include "PatientManagementSystem.h"

int main()
{
	auto pms = std::make_unique<PatientManagementSystem>();

	pms->init(); 

	//TEST BLOCK START (TEMPORARY)
	const auto& patients = pms->getAllPatients();
	std::cout << "\n=== DEBUG: Loaded Patients ===\n";
	for (const auto& patient : patients)
	{
		std::cout << "- " << patient->getLastName() << ", " << patient->getFirstName() << "\n";
		std::cout << "  Diagnosis: " << patient->getDiagnosis() << "\n";
		std::cout << "  Vitals Count: " << patient->getAllVitals().size() << "\n";
	}
	std::cout << "=============================\n";
	//TEST BLOCK END

	pms->run();   // Keep the original app flow

	return 0;
}

