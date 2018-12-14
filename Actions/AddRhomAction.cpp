#include "AddRhomAction.h"
#include "../CRhombus.h"

#include "../ApplicationManager.h"

AddRhomAction::AddRhomAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRhomAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound(TEXT("rhombus.wav"), NULL, SND_SYNC);

	pOut->PrintMessage("New Rhombus: Click at first corner");
	
	//Read Midpoint and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);



	RhomGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RhomGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhomGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhomAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rhombus with the parameters read from the user
	CRhombus *R=new CRhombus(P1, RhomGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(R);
}
