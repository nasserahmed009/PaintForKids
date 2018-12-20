#include "ChngFillColor.h"



ChngFillColor::ChngFillColor(ApplicationManager * pApp, Output* pOut, Input* pIn) :Action(pApp)
{
	this->pOut = pOut;
	this->pIn = pIn;
	if (!pManager->getSound())
		PlaySound("Sounds\\fillClr.wav", NULL, SND_ASYNC);
}

void ChngFillColor::ReadActionParameters() {
}

void ChngFillColor::Execute()
{
	pOut->PrintMessage("Choose a color for object to be filled with");
	pOut->DrawColorPallete(1);
	ChooseClr = pIn->GetClr();
	switch (ChooseClr) {
	case PICK_BLACK: UI.FillColor = BLACK;
		break;
	case PICK_WHITE: UI.FillColor = WHITE;
		break;
	case PICK_RED:   UI.FillColor = RED;
		break;
	case PICK_GREEN: UI.FillColor = GREEN;
		break;
	case PICK_BLUE:  UI.FillColor = BLUE;
		break;
	}
	if (pManager->GetSelectedFig() != NULL) {
		pManager->DeselectAll();
		(pManager->GetSelectedFig())->ChngFillClr(UI.FillColor);
		pManager->SetSelectedFig(NULL);
	}
	pOut->ClearColorPallete();
}

ChngFillColor::~ChngFillColor()
{
}
