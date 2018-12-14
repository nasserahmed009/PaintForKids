#include "AddEllipseAction.h"
#include "../CEllipse.h"

#include "../ApplicationManager.h"

#include "../GUI/input.h"
#include "../GUI/Output.h"
#include <Windows.h>
#include <MMSystem.h>



AddEllipseAction::AddEllipseAction(ApplicationManager * pApp):Action(pApp)
{}

void AddEllipseAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound(TEXT("elipse.wav"), SND_SYNC, SND_ASYNC);

	pOut->PrintMessage("New Ellipse: Click at midpoint");

	//Read midpoint and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	ElliGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	ElliGfxInfo.DrawClr = pOut->getCrntDrawColor();
	ElliGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a ellipse with the parameters read from the user
	CEllipse *E=new CEllipse(P1, ElliGfxInfo);

	//Add the ellipse to the list of figures
	pManager->AddFigure(E);
}
