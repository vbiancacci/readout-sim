#ifndef ReadoutSimDetectorConstruction_h
#define ReadoutSimDetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4LogicalVolume.hh"

class ReadoutSimDetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        ReadoutSimDetectorConstruction();
        ~ReadoutSimDetectorConstruction();

        virtual G4VPhysicalVolume *Construct(); 
        // virtual void ConstructSDandField();
    
    private:
        void DefineMaterials();
        void SetOpticalProperties();

        G4VPhysicalVolume* SetupPanelOnly();
        G4VPhysicalVolume* SetupPanelWithCladding();
        G4VPhysicalVolume* SetupBaselineDesign();
        G4VPhysicalVolume* SetupBaselineCladding();

        G4LogicalVolume *fRightPENLayerLogical, *fLeftPENLayerLogical;
        G4LogicalVolume *fTopPENLayerLogical, *fBotPENLayerLogical;
        G4Material *worldMaterial;
        G4Material *PMMA, *PEN;
        G4Material *innerCladdingMaterial, *outerCladdingMaterial;

        G4MaterialPropertiesTable *pmmaMPT, *penMPT, *larMPT, *innerCladdingMPT, *outerCladdingMPT;
};

#endif