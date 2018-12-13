#include "ResizeFigure.h"



ResizeFigure::ResizeFigure(ApplicationManager * pApp, Output* pOut, Input* pIn) :Action(pApp)
{
	this->pOut = pOut;
	this->pIn = pIn;
}

void ResizeFigure::ReadActionParameters() {
}


void ResizeFigure::Execute() {
	if (pManager->GetSelectedFig() == NULL) {
		pOut->PrintMessage("No figure is selected");
		return;
	}
	pOut->PrintMessage("A click on Resize button");
	pOut->DrawResizePallete();
	Size = pIn->GetSize();
	switch (Size) {
		case PICK_QUARTER:
			(pManager->GetSelectedFig())->ChngFigSize(0.25);
			pOut->PrintMessage("Figure resized to quarter it's size");
			break;
		case PICK_HALF: 
			(pManager->GetSelectedFig())->ChngFigSize(0.5);
			pOut->PrintMessage("Figure resized to half it's size");
			break;
		case PICK_DOUBLE:   
			(pManager->GetSelectedFig())->ChngFigSize(2);
			pOut->PrintMessage("Figure resized to double it's size");
			break;
		case PICK_QUAD:
			(pManager->GetSelectedFig())->ChngFigSize(4);
			pOut->PrintMessage("Figure resized to four times it's size");
			break;
	}
	pOut->ClearDrawArea();
}

ResizeFigure::~ResizeFigure()
{
}
