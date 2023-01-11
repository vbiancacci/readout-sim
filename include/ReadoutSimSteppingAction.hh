#ifndef ReadoutSimSteppingAction_h
#define ReadoutSimSteppingAction_h 

#include "G4UserSteppingAction.hh"

class ReadoutSimSteppingAction : public G4UserSteppingAction
{
  public:
    ReadoutSimSteppingAction();
    virtual ~ReadoutSimSteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif