#include "CopyAction.h"



CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
}

void CopyAction::ReadActionParameters() {
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
		selectedFigure->GetFigPoints(P1,P2);
		copiedFigure = new CRectangle(P1,P2, selectedFigure->GetFigGfxInfo());
	}else if (dynamic_cast<CLine*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1, P2);
		copiedFigure = new CLine(P1,P2, selectedFigure->GetFigGfxInfo());
	}else if (dynamic_cast<CEllipse*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1);

		copiedFigure = new CEllipse(P1, selectedFigure->GetFigGfxInfo());
	}else if (dynamic_cast<CTriangle*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1, P2, P3);

		copiedFigure = new CTriangle(P1,P2,P3, selectedFigure->GetFigGfxInfo());
	}else if (dynamic_cast<CRhombus*>(selectedFigure)) {
		selectedFigure->GetFigPoints(P1);

		copiedFigure = new CRhombus(P1, selectedFigure->GetFigGfxInfo());
	}

	if (pManager->GetCutFig() != NULL) {
		(pManager->GetCutFig())->ChngFillClr((pManager->GetClipboardFig())->GetFigGfxInfo().FillClr);
		pManager->SetCutFig(NULL);
	}
	pManager->ClearClipboard();

	copiedFigure->ChngDrawClr(BLACK);
	pManager->SetClipboard(copiedFigure);
	pManager->DeselectAll();
	selectedFigure = NULL;
	pOut->PrintMessage("Copied the figure to the clipboard");
}

CopyAction::~CopyAction()
{

}
