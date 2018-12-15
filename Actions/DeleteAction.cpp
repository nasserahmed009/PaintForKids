#include "DeleteAction.h"
#include "../ApplicationManager.h"



DeleteAction::DeleteAction(ApplicationManager *pApp) :Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
}

void DeleteAction::Execute() {
	pManager->DeleteSelectedFigure();
}

DeleteAction::~DeleteAction()
{
	
}
