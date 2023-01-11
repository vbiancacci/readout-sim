#ifndef ReadoutSimRunAction_h
#define ReadoutSimRunAction_h

#include "G4UserRunAction.hh"

#include "Run.hh"

class ReadoutSimRunAction : public G4UserRunAction
{
    public:
        ReadoutSimRunAction();
        virtual ~ReadoutSimRunAction();

        virtual void BeginOfRunAction(const G4Run *aRun);
        virtual void EndOfRunAction(const G4Run *aRun);
        G4Run* GenerateRun();

    private:
        Run* fRun;
};

#endif