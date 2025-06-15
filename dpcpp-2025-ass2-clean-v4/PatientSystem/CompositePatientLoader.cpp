#include "CompositePatientLoader.h"

void CompositePatientLoader::addLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader)
{
    loaders.push_back(loader);
}

void CompositePatientLoader::initialiseConnection()
{
    //optional: could call sub-loader initialisation here if needed
    for (auto& loader : loaders) {
        loader->initialiseConnection();
    }
}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientList)
{
    for (auto& loader : loaders) {
        loader->loadPatients(patientList);
    }
}

void CompositePatientLoader::closeConnection()
{
    for (auto& loader : loaders) {
        loader->closeConnection();
    }
}
