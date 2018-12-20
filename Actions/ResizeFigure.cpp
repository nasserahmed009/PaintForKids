#include "ResizeFigure.h"



ResizeFigure::ResizeFigure(ApplicationManager * pApp, Output* pOut, Input* pIn) :Action(pApp)
{
	this->pOut = pOut;
	this->pIn = pIn;
	if (!pManager->getSound())
		PlaySound("Sounds\\Resize.wav", NULL, SND_ASYNC);
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
			(pManager->GetSelectedFig())->ChngFigSize(0.25); // Changes the figure size by 1/4 of it's current size
			pOut->PrintMessage("Figure resized to quarter it's size");
			break;
		case PICK_HALF: 
			(pManager->GetSelectedFig())->ChngFigSize(0.5); // Changes the figure size by 1/2 of it's current size
			pOut->PrintMessage("Figure resized to half it's size");
			break;
		case PICK_DOUBLE:   
			(pManager->GetSelectedFig())->ChngFigSize(2); // Changes the figure size by 2 of it's current size
			pOut->PrintMessage("Figure resized to double it's size");
			break;
		case PICK_QUAD:
			(pManager->GetSelectedFig())->ChngFigSize(4); // Changes the figure size by 4 of it's current size
			pOut->PrintMessage("Figure resized to four times it's size");
			break;
	}
	pOut->ClearDrawArea();
}

ResizeFigure::~ResizeFigure()
{
}
