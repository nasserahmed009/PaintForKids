#include "AddSelectAction.h"
#include "../ApplicationManager.h"



AddSelectAction::AddSelectAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddSelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(pClicked.x, pClicked.y);

}

void AddSelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->DeselectAll();
	CFigure* selectedFigure = pManager->GetFigure(pClicked.x, pClicked.y);
	if (selectedFigure){
		selectedFigure->SetSelected(true);
		selectedFigure->ChngDrawClr(MAGENTA);
		pOut->PrintMessage("a figure is selected");
	}
	else {
		pOut->PrintMessage("no figure is selected");
	}
}


AddSelectAction::~AddSelectAction()
{
}
