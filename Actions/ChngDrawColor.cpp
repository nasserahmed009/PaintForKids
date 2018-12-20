#include "ChngDrawColor.h"



ChngDrawColor::ChngDrawColor(ApplicationManager * pApp,Output* pOut, Input* pIn) :Action(pApp)
{
	this->pOut = pOut;
	this->pIn = pIn;
	if (!pManager->getSound())
		PlaySound("Sounds\\drawClr.wav", NULL, SND_ASYNC);
}

void ChngDrawColor::ReadActionParameters() {
}

void ChngDrawColor::Execute()
{
	pOut->DrawColorPallete(2); // Draws the pallete
	ChooseClr = pIn->GetClr(); // Gets the input from the user 
	switch (ChooseClr) {
		case PICK_BLACK: UI.DrawColor = BLACK; 
			break;
		case PICK_WHITE: UI.DrawColor = WHITE;
			break;
		case PICK_RED:   UI.DrawColor = RED;
			break;
		case PICK_GREEN: UI.DrawColor = GREEN;
			break;
		case PICK_BLUE:  UI.DrawColor = BLUE;
			break;
	}
	if (pManager->GetSelectedFig() != NULL) {
		pManager->DeselectAll();
		(pManager->GetSelectedFig())->ChngDrawClr(UI.DrawColor); // Changes the draw color to the color selected from UI
		pManager->SetSelectedFig(NULL);
	}
	pOut->ClearColorPallete();
}




ChngDrawColor::~ChngDrawColor()
{
}
