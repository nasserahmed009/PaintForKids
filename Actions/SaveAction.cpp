#include "SaveAction.h"
#include<fstream>


SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter name to save your file : ");
	name=pIn->GetSrting(pOut);
	
}


void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open("Savefile/" + name + ".txt");
	pManager->SaveAll(OutFile);
	OutFile.close();
	pManager->SaveAll(OutFile);
	pOut->PrintMessage("Saved");
	
}

SaveAction::~SaveAction()
{
}
