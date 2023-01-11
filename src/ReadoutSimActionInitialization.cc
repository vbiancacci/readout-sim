#include "ReadoutSimActionInitialization.hh"
#include "ReadoutSimRunAction.hh"
#include "ReadoutSimPrimaryGenerator.hh"
#include "ReadoutSimSteppingAction.hh"

ReadoutSimActionInitialization::ReadoutSimActionInitialization()
{}

ReadoutSimActionInitialization::~ReadoutSimActionInitialization()
{}

void ReadoutSimActionInitialization::BuildForMaster() const
{
  SetUserAction(new ReadoutSimRunAction());
}

void ReadoutSimActionInitialization::Build() const
{
  SetUserAction(new ReadoutSimPrimaryGenerator());
  SetUserAction(new ReadoutSimRunAction());
  SetUserAction(new ReadoutSimSteppingAction());
//   SetUserAction(new OpNoviceStackingAction());
}