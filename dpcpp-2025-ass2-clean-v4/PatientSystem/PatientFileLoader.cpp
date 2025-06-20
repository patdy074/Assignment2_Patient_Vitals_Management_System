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
        std::cerr << "Could not open file: " << file << std::endl;
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
        std::getline(ss, vitalsStr); //May be empty

        //Parse name
        std::string lastName, firstName;
        std::stringstream nameSS(fullName);
        std::getline(nameSS, lastName, ',');
        std::getline(nameSS, firstName);

        //Parse DOB
        int day = 0, month = 0, year = 0;
        std::stringstream dobSS(dobStr);
        std::string token;
        if (std::getline(dobSS, token, '-')) day = std::stoi(token);
        if (std::getline(dobSS, token, '-')) month = std::stoi(token);
        if (std::getline(dobSS, token, '-')) year = std::stoi(token);

        std::tm birthDate = {};
        birthDate.tm_mday = day;
        birthDate.tm_mon = month - 1;
        birthDate.tm_year = year - 1900;

        //Create patient
        Patient* patient = new Patient(firstName, lastName, birthDate);
        patient->addDiagnosis(diagnosis);

        //Parse vitals
        if (!vitalsStr.empty()) {
            std::stringstream vitalsSS(vitalsStr);
            std::string vitalsEntry;
            while (std::getline(vitalsSS, vitalsEntry, ';')) {
                std::stringstream entrySS(vitalsEntry);
                std::string value;
                float temp = 0.0f;
                int bpm = 0, respiration = 0, spo2 = 0;

                if (std::getline(entrySS, value, ',')) temp = std::stof(value);
                if (std::getline(entrySS, value, ',')) bpm = std::stoi(value);
                if (std::getline(entrySS, value, ',')) respiration = std::stoi(value);
                if (std::getline(entrySS, value, ',')) spo2 = std::stoi(value);

                patient->addVitals(new Vitals(temp, bpm, respiration, spo2));
            }
        }

        patients.push_back(patient);
    }

    return patients;
}
