#ifndef DetectorMessenger_h
#define DetectorMessenger_h

#include "G4UImessenger.hh"

class DetectorConstruction;
class G4UIcommand;

class DetectorMessenger: public G4UImessenger
{
    public:

    DetectorMessenger(DetectorConstruction* );
    ~DetectorMessenger();

    virtual void SetNewValue(G4UIcommand*, G4String);
};

#endif