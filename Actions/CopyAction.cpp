#include "CopyAction.h"



CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
}

void CopyAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(pClicked.x, pClicked.y);
}

void CopyAction::Execute() {
	Output* pOut = pManager->GetOutput();

	CFigure* selectedFigure = pManager->GetSelectedFig();

	Point P1 = { 0,0 }, P2 = { 0,0 }, P3 = { 0,0 }; GfxInfo TempGfx;
	CFigure* copiedFigure;
	if (selectedFigure == NULL) {
		pOut->PrintMessage("No figure is selected");
		return;
	}else if (dynamic_cast<CRectangle*>(selectedFigure)) {
		copiedFigure = new CRectangle(P1,P2,TempGfx);
		*copiedFigure = *(dynamic_cast<CRectangle*>(selectedFigure));
	}else if (dynamic_cast<CLine*>(selectedFigure)) {
		copiedFigure = new CLine(P1,P2,TempGfx);
		*copiedFigure = *(dynamic_cast<CLine*>(selectedFigure));
	}else if (dynamic_cast<CEllipse*>(selectedFigure)) {
		copiedFigure = new CEllipse(P1,TempGfx);
		*copiedFigure = *(dynamic_cast<CEllipse*>(selectedFigure));
	}else if (dynamic_cast<CTriangle*>(selectedFigure)) {
		copiedFigure = new CTriangle(P1,P2,P3,TempGfx);
		*copiedFigure = *(dynamic_cast<CTriangle*>(selectedFigure));
	}else if (dynamic_cast<CRhombus*>(selectedFigure)) {
		copiedFigure = new CRhombus(P1,TempGfx);
		*copiedFigure = *(dynamic_cast<CRhombus*>(selectedFigure));
	}

	pManager->SetClipboard(copiedFigure);
	pManager->DeselectAll();
	selectedFigure = NULL;
	pOut->PrintMessage("Copied the figure to the clipboard");
}

CopyAction::~CopyAction()
{

}
