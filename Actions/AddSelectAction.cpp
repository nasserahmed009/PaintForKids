#include "AddSelectAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CLine.h"
#include "../Figures/CRhombus.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CEllipse.h"



AddSelectAction::AddSelectAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddSelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(pClicked.x, pClicked.y);

}

void AddSelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	ReadActionParameters();

	CFigure* clickedFigure = pManager->GetFigure(pClicked.x, pClicked.y);
	//color selectedPrevColor = clickedFigure->getDrawColor();


	CRectangle* ptrRectangle = dynamic_cast <CRectangle*>(clickedFigure);
	CLine* ptrLine = dynamic_cast <CLine*>(clickedFigure);
	CRhombus* ptrRhombus = dynamic_cast <CRhombus*>(clickedFigure);
	CTriangle* ptrTriangle = dynamic_cast <CTriangle*>(clickedFigure);
	CEllipse* ptrEllipse = dynamic_cast <CEllipse*>(clickedFigure);

	if (clickedFigure){ // if user selects a figure

		if (clickedFigure->IsSelected() == true) {		// if the figure is already selected
			pManager->DeselectAll();
		}
		else {											// the figure isn't already selected
			pManager->DeselectAll();					// deselects the selected figure
			clickedFigure->SetSelected(true);
			pManager->SetSelectedFig(clickedFigure);
			clickedFigure->setPrevDrawColor(clickedFigure->getDrawColor());
			clickedFigure->ChngDrawClr(MAGENTA);
			//Checking the type of the figure and print specific message for every type;
			if (ptrRectangle != NULL) {
				
				pOut->PrintMessage("Rectangle ID: " + to_string(ptrRectangle->getID()) + " Width: " + to_string(ptrRectangle->getWidth()) + " Height: " + to_string(ptrRectangle->getHeight()));
			}
			if (ptrLine != NULL) {
				pOut->PrintMessage("Line ID: " + to_string(ptrLine->getID()));
			}
			if (ptrRhombus != NULL) {
				pOut->PrintMessage("Rhombus ID: " + to_string(ptrRhombus->getID()));
			}
			if (ptrTriangle != NULL) {
				pOut->PrintMessage("Triangle ID: " + to_string(ptrTriangle->getID()));
			}
			if (ptrEllipse != NULL) {
				pOut->PrintMessage("Ellipse ID: " + to_string(ptrEllipse->getID()));
			}
		}
	}
	else {
		pManager->DeselectAll();
		pOut->PrintMessage("no figure is selected");
	}
}


AddSelectAction::~AddSelectAction()
{
}
