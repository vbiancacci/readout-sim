#ifndef ReadoutSimActionInitialization_h
#define ReadoutSimActionInitialization_h

#include "G4VUserActionInitialization.hh"

class ReadoutSimActionInitialization : public G4VUserActionInitialization
{
    public:
        ReadoutSimActionInitialization();
        ~ReadoutSimActionInitialization();

        virtual void BuildForMaster() const;
        virtual void Build() const;
};

#endif