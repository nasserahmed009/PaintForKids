#include "CutAction.h"


CutAction::CutAction(ApplicationManager * pApp):Action(pApp)
{
}

void CutAction::ReadActionParameters()
{
}


void CutAction::Execute() {
	Output* pOut = pManager->GetOutput();

	CFigure* selectedFigure = pManager->GetSelectedFig();

	Point P1 = { 0,0 }, P2 = { 0,0 }, P3 = { 0,0 }; GfxInfo TempGfx;
	CFigure* copiedFigure;
	TempGfx = selectedFigure->GetFigGfxInfo();
	TempGfx.DrawClr = selectedFigure->getPrevDrawColor();
	if (selectedFigure == NULL) {
		pOut->PrintMessage("No figure is selected");
		return;
	}
	else if (dynamic_cast<CRectangle*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1, P2);
		copiedFigure = new CRectangle(P1, P2, TempGfx);
	}
	else if (dynamic_cast<CLine*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1, P2);
		copiedFigure = new CLine(P1, P2, TempGfx);
	}
	else if (dynamic_cast<CEllipse*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1);

		copiedFigure = new CEllipse(P1, TempGfx);
	}
	else if (dynamic_cast<CTriangle*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1, P2, P3);

		copiedFigure = new CTriangle(P1, P2, P3, TempGfx);
	}
	else if (dynamic_cast<CRhombus*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1);

		copiedFigure = new CRhombus(P1, TempGfx);
	}

	if (pManager->GetCutFig() != NULL) {
		(pManager->GetCutFig())->ChngFillClr((pManager->GetClipboardFig())->GetFigGfxInfo().FillClr);
		pManager->SetCutFig(NULL);
	}

	pManager->ClearClipboard();
	pManager->SetClipboard(copiedFigure);

	pManager->SetCutFig(selectedFigure);

	pManager->DeselectAll();
	selectedFigure = NULL;
	pOut->PrintMessage("Cut the figure to the clipboard");
}

CutAction::~CutAction()
{
}
