#include "DeleteAction.h"
#include "../ApplicationManager.h"



DeleteAction::DeleteAction(ApplicationManager *pApp) :Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(pClicked.x, pClicked.y);
}

void DeleteAction::Execute() {
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	CFigure* selectedFigure = pManager->GetFigure(pClicked.x, pClicked.y);
	pManager->DeleteFigure(selectedFigure);
}

DeleteAction::~DeleteAction()
{
	
}
