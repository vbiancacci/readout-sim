#ifndef DetectorMessenger_h
#define DetectorMessenger_h

#include "globals.hh"
#include "G4UImessenger.hh"

class ReadoutSimDetectorConstruction;
class G4UIcommand;
class G4UIdirectory;
class G4UIcmdWithAString;

class DetectorMessenger: public G4UImessenger
{
    public:

        DetectorMessenger(ReadoutSimDetectorConstruction* );
        ~DetectorMessenger();

        virtual void SetNewValue(G4UIcommand*, G4String);

    private:

        ReadoutSimDetectorConstruction* fDetector;

        G4UIdirectory*  fReadoutSimDir;

        G4UIcmdWithAString* fGeometryTypeCmd;
};

#endif