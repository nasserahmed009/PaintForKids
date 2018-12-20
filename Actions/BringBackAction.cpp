#include "BringBackAction.h"



BringBackAction::BringBackAction(ApplicationManager * pApp) :Action(pApp)
{
	if (!pManager->getSound())
		PlaySound("Sounds\\sendToBack.wav", NULL, SND_ASYNC);
}

void BringBackAction::ReadActionParameters() {
}

void BringBackAction::Execute() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() == NULL) {
		pOut->PrintMessage("No figure is selected");
	}
	else {
		CFigure* selectedFigure = pManager->GetSelectedFig();
		CFigure* tempFig;
		Point P1 = { 0,0 }, P2 = { 0,0 }, P3 = { 0,0 }; GfxInfo TempGfx;
		TempGfx = selectedFigure->GetFigGfxInfo();
		TempGfx.DrawClr = selectedFigure->getPrevDrawColor();
		if (dynamic_cast<CRectangle*>(selectedFigure)) {
			selectedFigure->GetFigPoints(P1, P2);
			tempFig = new CRectangle(P1, P2, TempGfx);
		}
		else if (dynamic_cast<CLine*>(selectedFigure)) {
			selectedFigure->GetFigPoints(P1, P2);
			tempFig = new CLine(P1, P2, TempGfx);
		}
		else if (dynamic_cast<CEllipse*>(selectedFigure)) {
			selectedFigure->GetFigPoints(P1);

			tempFig = new CEllipse(P1, TempGfx);
		}
		else if (dynamic_cast<CTriangle*>(selectedFigure)) {
			selectedFigure->GetFigPoints(P1, P2, P3);

			tempFig = new CTriangle(P1, P2, P3, TempGfx);
		}
		else if (dynamic_cast<CRhombus*>(selectedFigure)) {
			selectedFigure->GetFigPoints(P1);

			tempFig = new CRhombus(P1, TempGfx);
		}

		pManager->AddFigureOnTop(tempFig);
		pManager->DeleteFigure(selectedFigure);

		pManager->SetSelectedFig(NULL);
		pManager->DeselectAll();
		pOut->PrintMessage("Figure brought to back");
	}
}

BringBackAction::~BringBackAction()
{
}
