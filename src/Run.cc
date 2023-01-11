#include "Run.hh"

Run::Run() : G4Run()
{
  fTotal = 0;
  fDetection = 0;
  fPanelAbsorption = 0;
  fLightGuideAbsorption = 0;
  fPenAbsorption = 0;
  fLArAbsorption = 0;
  fOuterCladdingAbsorption = 0;
  fInnerCladdingAbsorption = 0;

  fPanelTowardLAr = 0;
  fPENTowardLAr = 0;
  fLightGuideTowardLAr = 0;
}
Run::~Run()
{}

void Run::Merge(const G4Run* run)
{
  const Run* localRun = static_cast<const Run*>(run);

  // pass information about primary particle
  fTotal = localRun->fTotal;
  fDetection = localRun->fDetection;
  fPenAbsorption = localRun->fPenAbsorption;
  fLightGuideAbsorption = localRun->fLightGuideAbsorption;
  fPanelAbsorption = localRun->fPanelAbsorption;
  fLArAbsorption = localRun->fLArAbsorption;
  fOuterCladdingAbsorption = localRun->fOuterCladdingAbsorption;
  fInnerCladdingAbsorption = localRun->fInnerCladdingAbsorption;

  fPanelTowardLAr = localRun->fPanelTowardLAr;
  fPENTowardLAr = localRun->fPENTowardLAr;
  fLightGuideTowardLAr = localRun->fLightGuideTowardLAr;
  
  G4Run::Merge(run);
}

void Run::EndOfRun()
{
  G4cout << "\n   Summary\n";
  G4cout <<   "---------------------------------\n";
  G4cout << "  # of generated photons:          " << std::setw(8) << fTotal << G4endl;
  G4cout << "  Photons Detected:                 " << std::setw(8) << double(fDetection)/double(fTotal)*100 << " %" << G4endl;
  G4cout << "  Photons Absorbed in PEN:          " << std::setw(8) << double(fPenAbsorption)/double(fTotal)*100 << " %" << G4endl;
  G4cout << "  Photons Absorbed in PMMA guide:   " << std::setw(8) << double(fLightGuideAbsorption)/double(fTotal)*100 << " %" << G4endl;
  G4cout << "  Photons Absorbed in PMMA panel:   " << std::setw(8) << double(fPanelAbsorption)/double(fTotal)*100 << " %" << G4endl;
  G4cout << "  Photons Absorbed in LAr:          " << std::setw(8) << double(fLArAbsorption)/double(fTotal)*100 << " %" << G4endl;
  G4cout << "  Photons Absorbed in Outer Cladding: " << std::setw(8) << double(fOuterCladdingAbsorption)/double(fTotal)*100 << " %" << G4endl;
  G4cout << "  Photons Absorbed in Inner Cladding: " << std::setw(8) << double(fInnerCladdingAbsorption)/double(fTotal)*100 << " %" << G4endl; 
  G4cout << "  TOTAL:          " << std::setw(8) << double(fDetection+fPenAbsorption+fLightGuideAbsorption+fPanelAbsorption+fLArAbsorption+fOuterCladdingAbsorption+fInnerCladdingAbsorption)/double(fTotal)*100 << " %" << G4endl;
  G4cout <<   "---------------------------------\n";

  G4cout << "\n   Where are photon before going into LAr?\n";
  G4cout <<   "---------------------------------\n";
  G4cout << "  Photons coming from Panel        " << std::setw(8) << double(fPanelTowardLAr)/double(fLArAbsorption) * 100 << " %" << G4endl;
  G4cout << "  Photons coming from PEN          " << std::setw(8) << double(fPENTowardLAr)/double(fLArAbsorption) * 100 << " %" << G4endl;
  G4cout << "  Photons coming from PMMA guide   " << std::setw(8) << double(fLightGuideTowardLAr)/double(fLArAbsorption) * 100 << " %" << G4endl;
  G4cout << "  TOTAL:          " << std::setw(8) << double(fPanelTowardLAr+fPENTowardLAr+fLightGuideTowardLAr)/double(fLArAbsorption)*100 << " %" << G4endl;
  G4cout << "\n";
}
