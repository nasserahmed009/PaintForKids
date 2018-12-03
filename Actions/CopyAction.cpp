#include "CopyAction.h"



CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
}

void CopyAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(pClicked.x, pClicked.y);
}

void CopyAction::Execute() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select a figure to be copied");
	ReadActionParameters();
	pManager->DeselectAll();
	CFigure* selectedFigure = pManager->GetFigure(pClicked.x, pClicked.y);
	pManager->SetClipboard(selectedFigure);
	selectedFigure->ChngDrawClr(MAGENTA);
	pOut->PrintMessage("Copied the figure to the clipboard");
}

CopyAction::~CopyAction()
{

}
