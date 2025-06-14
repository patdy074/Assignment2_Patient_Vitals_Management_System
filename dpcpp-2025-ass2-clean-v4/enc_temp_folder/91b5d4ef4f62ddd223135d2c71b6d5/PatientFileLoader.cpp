#define _CRT_SECURE_NO_WARNINGS

#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;

void PatientFileLoader::initialiseConnection() 
{
    std::cout << "Initialising file connection (stub)\n";
}

void PatientFileLoader::loadPatients(std::vector<Patient*>& patients)
{
    std::vector<Patient*> loaded = loadPatientFile("patients.txt");
    patients.insert(patients.end(), loaded.begin(), loaded.end());
}

void PatientFileLoader::closeConnection() 
{
    std::cout << "Closing file connection (stub)\n";
}

std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file) const
{
    std::vector<Patient*> patients;
    std::ifstream inFile(file);
    if (!inFile.is_open()) {
        std::cerr << "Could not open file: " << file << std::endl; //if not able to open the file 
        return patients;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string id, fullName, dobStr, diagnosis, vitalsStr;

        std::getline(ss, id, '|');
        std::getline(ss, fullName, '|');
        std::getline(ss, dobStr, '|');
        std::getline(ss, diagnosis, '|');
        std::getline(ss, vitalsStr); // may be empty

        // Parse name
        std::string lastName, firstName;
        std::stringstream nameSS(fullName);
        std::getline(nameSS, lastName, ',');
        std::getline(nameSS, firstName);

        // Parse DOB (DD-MM-YYYY)
        int day, month, year;
        std::tm birthDate = {};
        if (sscanf(dobStr.c_str(), "%d-%d-%d", &day, &month, &year) == 3) {
            birthDate.tm_mday = day;
            birthDate.tm_mon = month - 1;
            birthDate.tm_year = year - 1900;
        }

        // Create Patient
        Patient* patient = new Patient(firstName, lastName, birthDate);
        patient->addDiagnosis(diagnosis);

        // Parse vitals (if any)
        if (!vitalsStr.empty()) {
            std::stringstream vitalsSS(vitalsStr);
            std::string vitalsEntry;
            while (std::getline(vitalsSS, vitalsEntry, ';')) {
                float temp;
                int bpm, respiration, spo2;
                if (sscanf(vitalsEntry.c_str(), "%f,%d,%d,%d", &temp, &bpm, &respiration, &spo2) == 4) {
                    Vitals* v = new Vitals(temp, bpm, respiration, spo2);
                    patient->addVitals(v);
                }
            }
        }

        patients.push_back(patient);
    }

    return patients;
}
