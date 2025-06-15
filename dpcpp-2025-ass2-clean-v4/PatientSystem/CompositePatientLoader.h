#ifndef COMPOSITE_PATIENT_LOADER_H
#define COMPOSITE_PATIENT_LOADER_H

#include "AbstractPatientDatabaseLoader.h"
#include <vector>
#include <memory>


//Composite loader that can run multiple loaders (e.g. file + database).
class CompositePatientLoader : public AbstractPatientDatabaseLoader {
public:
    
     //Adds a loader (e.g. file or database) to the composite list.
     
    void addLoader(std::shared_ptr<AbstractPatientDatabaseLoader> loader);

    
     //Loads patients from all added loaders.
     //patientList Reference to vector to populate with Patient pointers.
     
    void loadPatients(std::vector<Patient*>& patientList) override;

private:
    std::vector<std::shared_ptr<AbstractPatientDatabaseLoader>> loaders;
};

#endif // COMPOSITE_PATIENT_LOADER_H
