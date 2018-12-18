#include "SaveByTypeAction.h"
#include<fstream>


SaveByTypeAction::SaveByTypeAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SaveByTypeAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("select the type from tool bar");
	ActionType action = pIn->GetUserAction();
	switch (action) {
	case DRAW_RECT:
		type = RECTANGLE;
		break;
	case DRAW_ELLIPSE:
		type = ELLIPSE;
		break;
	case DRAW_LINE:
		type = LINE;
		break;
	case DRAW_RHOMBUS:
		type = RHUMBOS;
		break;
	case DRAW_TRI:
		type = TRIANGLE;
		break;
	default:
		EMPTY;
		break;
	}
	pOut->PrintMessage("Enter name to save your file : ");
	name = pIn->GetSrting(pOut);

}


void SaveByTypeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open("Savefile/" + name + ".txt");
	pManager->SaveByType(OutFile,type);
	OutFile.close();
	pManager->SaveByType(OutFile,type);
	pOut->PrintMessage("Saved");

}

SaveByTypeAction::~SaveByTypeAction()
{
}
