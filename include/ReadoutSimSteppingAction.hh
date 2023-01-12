#ifndef ReadoutSimSteppingAction_h
#define ReadoutSimSteppingAction_h 

#include "G4UserSteppingAction.hh"
#include "G4Types.hh"
#include "G4SystemOfUnits.hh"


class ReadoutSimSteppingAction : public G4UserSteppingAction
{
  public:
    ReadoutSimSteppingAction();
    virtual ~ReadoutSimSteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
    G4double stepLength = 0.*m;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif