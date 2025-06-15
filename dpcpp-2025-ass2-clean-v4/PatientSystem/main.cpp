// PatientSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <memory>
#include <string>

#include "PatientManagementSystem.h"
#include "CompositePatientLoader.h"
#include "PatientDatabaseLoader.h"
#include "PatientFileLoader.h"

int main()
{
    //create the composite loader
    std::shared_ptr<CompositePatientLoader> compositeLoader = std::make_shared<CompositePatientLoader>();

    //add loaders in correct order: database first, then file
    compositeLoader->addLoader(std::make_shared<PatientDatabaseLoader>());
    compositeLoader->addLoader(std::make_shared<PatientFileLoader>());

    //create the patient management system and inject the loader
    auto pms = std::make_unique<PatientManagementSystem>();
    
    
    pms->setLoader(compositeLoader);    //One-line swap point 
    
    //pms->setLoader(std::make_shared<PatientFileLoader>()); //this for file only
    //pms->setLoader(std::make_shared<PatientDatabaseLoader>()); //this for database only
    

    //run the system
    pms->init();
    pms->run();

    return 0;
}
