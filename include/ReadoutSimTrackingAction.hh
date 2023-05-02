#ifndef ReadoutSimTrackingAction_h
#define ReadoutSimTrackingAction_h 

#include "G4UserTrackingAction.hh"

class ReadoutSimTrackingAction : public G4UserTrackingAction 
{
public:
  ReadoutSimTrackingAction();
  virtual ~ReadoutSimTrackingAction(){};
   
  virtual void PreUserTrackingAction(const G4Track*);
  virtual void PostUserTrackingAction(const G4Track*);

private:
    double track_length_g4;
  
};

#endif