#include "ReadoutSimPrimaryGenerator.hh"

#include "g4root.hh"

#include "G4ParticleTable.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4RunManager.hh"

#include "Run.hh"

ReadoutSimPrimaryGenerator::ReadoutSimPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);
}

ReadoutSimPrimaryGenerator::~ReadoutSimPrimaryGenerator()
{
    delete fParticleGun;
}

void ReadoutSimPrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
    Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());

    G4AnalysisManager *man = G4AnalysisManager::Instance();

    run->AddToTotal();

    // set opticalphoton as primary particle
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = particleTable->FindParticle("opticalphoton"); 
    fParticleGun->SetParticleDefinition(particle);

    // return integers uniformly distributed in [0, n]
    // G4int surface = surfaceGenerator->Integer(2); // alternative (panel)
    // G4double surface = surfaceGenerator->Uniform(0., 1.); // baseline
    G4double pi = 3.14159265359;
    G4double u = 0.;
    G4double v = 0.;

    // Panel Design
    // position coordinates
    // G4double xPos = -0.05;
    // G4double yPos = yPosGenerator->Uniform(-0.5, 0.5);
    // G4double zPos = zPosGenerator->Uniform(-1.5, 1.5);

    G4double xPos = 0., yPos = 0., zPos = 0.;
    G4double xMom = 0., yMom = 0., zMom = 0.;

    // // Baseline Design
    // if (surface < 0.143)
    // {
    //     //position coordinates
    //     // xPos = 0.05 + 0.0001 + xPosGenerator->Uniform(0., 0.02); // no cladding
    //     xPos = 0.05 + 0.0001 + 0.00002 + xPosGenerator->Uniform(0., 0.02); // cladding
    //     yPos = yPosGenerator->Uniform(-0.5, 0.5);
    //     zPos = 0.05;
    //     // momentum coordinates
    //     u = thetaGenerator->Uniform(-1,0);
    //     v = phiGenerator->Uniform(-pi, pi);

    //     man->FillNtupleIColumn(6, 1);
    // }
    // else if (surface > 0.857)
    // {
    //     // position coordinates
    //     // xPos = 0.05 + 0.0001 + xPosGenerator->Uniform(0., 0.02); // no cladding
    //     xPos = 0.05 + 0.0001 + 0.00002 + xPosGenerator->Uniform(0., 0.02); // cladding
    //     yPos = yPosGenerator->Uniform(-0.5, 0.5);
    //     zPos = -0.05;
    //     // // momentum coordinates
    //     u = thetaGenerator->Uniform(0,1);
    //     v = phiGenerator->Uniform(-pi, pi);
    //     man->FillNtupleIColumn(6, 2);

    // }
    // else
    // {
    //     // position coordinates
    //     // xPos = 0.05 + 0.02 + 0.0001; // no cladding
    //     xPos = 0.05 + 0.02 + 0.0001 + 0.00002; // cladding
    //     yPos = yPosGenerator->Uniform(-0.5, 0.5);
    //     zPos = zPosGenerator->Uniform(-0.05, 0.05);

    //     // momentum coordinates

    //     // xMom = sqrt(1-u*u) * cos(v);
    //     // yMom = sqrt(1-u*u) * sin(v);
    //     // zMom = u;
    //     u = thetaGenerator->Uniform(-1,1);
    //     v = phiGenerator->Uniform(-pi/2, pi/2);
    //     // xPosGenerator->Sphere(xMom, yMom, zMom, 1.);

    //     man->FillNtupleIColumn(6, 0);
    // }   

    // Panel only design 
    // u = thetaGenerator->Uniform(-1,1);
    // v = phiGenerator->Uniform(-pi/2, pi/2);

    // Common
    // xMom = sqrt(1-u*u) * cos(v);
    // yMom = sqrt(1-u*u) * sin(v);
    // zMom = u;

    // Baseline Design
    // xMom = -xMom;

    // Panel Only Design
    // if(surface == 1)
    // {
    //     xPos = -xPos;
    //     xMom = -xMom;
    // } 


    xPos = 0.05 + 0.0001 + 0.00002 + 0.01; // cladding
    yPos = 0.;
    zPos = 0.;

    xMom = 0.;
    yMom = -1.;
    zMom = 0.;


    G4ThreeVector position(xPos*m, yPos*m, zPos*m);
    G4ThreeVector momentum(xMom, yMom, zMom);
    
    G4double energy = 2.88 * eV; // optical photon @ 430nm

    fParticleGun->SetParticlePosition(position);
    fParticleGun->SetParticleMomentumDirection(momentum);
    fParticleGun->SetParticleEnergy(energy);
    
    // set optical photons random polarization
    SetOptPhotonPolar();
    
    fParticleGun->GeneratePrimaryVertex(anEvent);

    man->FillNtupleDColumn(0, position[0] / m);
    man->FillNtupleDColumn(1, position[1] / m);
    man->FillNtupleDColumn(2, position[2] / m);
    man->FillNtupleDColumn(3, momentum[0]);
    man->FillNtupleDColumn(4, momentum[1]);
    man->FillNtupleDColumn(5, momentum[2]);
    man->AddNtupleRow(0);
}

void ReadoutSimPrimaryGenerator::SetOptPhotonPolar()
{
    G4double angle = G4UniformRand() * 360.0*deg;
    SetOptPhotonPolar(angle);
}

void ReadoutSimPrimaryGenerator::SetOptPhotonPolar(G4double angle)
{
 if (fParticleGun->GetParticleDefinition()->GetParticleName()!="opticalphoton")
    {
    G4cout << "--> warning from PrimaryGeneratorAction::SetOptPhotonPolar() :"
                "the particleGun is not an opticalphoton" << G4endl;
    return;
    }

    G4ThreeVector normal (1., 0., 0.);
    G4ThreeVector kphoton = fParticleGun->GetParticleMomentumDirection();
    G4ThreeVector product = normal.cross(kphoton);
    G4double modul2       = product*product;
    
    G4ThreeVector e_perpend (0., 0., 1.);
    if (modul2 > 0.) e_perpend = (1./std::sqrt(modul2))*product;
    G4ThreeVector e_paralle    = e_perpend.cross(kphoton);
    
    G4ThreeVector polar = std::cos(angle)*e_paralle + std::sin(angle)*e_perpend;
    fParticleGun->SetParticlePolarization(polar);
}