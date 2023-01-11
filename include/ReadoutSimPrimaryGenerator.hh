#ifndef ReadoutSimPrimaryGenerator_h
#define ReadoutSimPrimaryGenerator_h

// #include "g4root.hh"

#include "G4VUserPrimaryGeneratorAction.hh"

#include "TRandom3.h"
#include "G4ParticleGun.hh"

class ReadoutSimPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
    public:
        ReadoutSimPrimaryGenerator();
        virtual ~ReadoutSimPrimaryGenerator();

        virtual void GeneratePrimaries(G4Event*);

        void SetOptPhotonPolar();
        void SetOptPhotonPolar(G4double);

    private:
        G4ParticleGun *fParticleGun; 

        TRandom3* surfaceGenerator = new TRandom3(0);
        TRandom3* xPosGenerator = new TRandom3(0);
        TRandom3* yPosGenerator = new TRandom3(0);
        TRandom3* zPosGenerator = new TRandom3(0);
        TRandom3* thetaGenerator = new TRandom3(0); // cos(theta) 
        TRandom3* phiGenerator   = new TRandom3(0); // phi angle 

        G4bool fPolarized;

        G4double fPolarization;
};

#endif