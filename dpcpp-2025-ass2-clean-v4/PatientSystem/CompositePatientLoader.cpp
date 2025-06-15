#include "CompositePatientLoader.h"

void CompositePatientLoader::addLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader) {
    loaders.push_back(loader);
}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientList) {
    //empty for now will fill in later
}
