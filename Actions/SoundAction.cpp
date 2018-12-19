#include "SoundAction.h"



SoundAction::SoundAction(ApplicationManager* pApp):Action(pApp)
{
}

void SoundAction::Execute() {
	Output* pOut=pManager->GetOutput();
	bool muted=pManager->getSound();
	/*if (muted) {
		pOut->PrintMessage("Sound is Activated");
	}
	else {
		pOut->PrintMessage("Sound is deactivated");
	}*/
	pManager->setSound(!muted);
	if (!(pManager->getSound())) {
		pOut->PrintMessage("Sound is activated");
	}
	else {
		pOut->PrintMessage("Sound is deactivated");
	}
}

void SoundAction::ReadActionParameters()
{
}

SoundAction::~SoundAction()
{
}
