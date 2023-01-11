#ifndef Run_h
#define Run_h

// #include "G4OpBoundaryProcess.hh"
#include "G4Run.hh"

class Run : public G4Run
{
    public:
        Run();
        ~Run();

        void AddToTotal(void) {fTotal += 1;}
        void AddDetection(void) {fDetection += 1;}
        void AddPanelAbsorption(void) {fPanelAbsorption += 1;}
        void AddLightGuideAbsorption(void) {fLightGuideAbsorption += 1;}
        void AddPenAbsorption(void) {fPenAbsorption += 1;}
        void AddLArAbsorption(void) {fLArAbsorption += 1;}
        void AddOuterCladdingAbsorption(void) {fOuterCladdingAbsorption += 1;}
        void AddInnerCladdingAbsorption(void) {fInnerCladdingAbsorption += 1;}

        void AddPanelTowardLAr(void) {fPanelTowardLAr += 1;}
        void AddPENTowardLAr(void) {fPENTowardLAr += 1;}
        void AddLightGuideTowardLAr(void) {fLightGuideTowardLAr += 1;}

        virtual void Merge(const G4Run*);

        void EndOfRun();

    private:
        G4int fTotal;
        G4int fDetection;
        G4int fPanelAbsorption;
        G4int fLightGuideAbsorption;
        G4int fPenAbsorption;
        G4int fLArAbsorption;
        G4int fOuterCladdingAbsorption;
        G4int fInnerCladdingAbsorption;

        G4int fPanelTowardLAr;
        G4int fPENTowardLAr;
        G4int fLightGuideTowardLAr;
};

#endif 