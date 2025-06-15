#include "CompositePatientLoader.h"

void CompositePatientLoader::addLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader) {
    loaders.push_back(loader);
}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientList) {
    for (const auto& loader : loaders) {
        loader->initialiseConnection();
        loader->loadPatients(patientList);  //merge directly into the reference list
        loader->closeConnection();
    }
}
