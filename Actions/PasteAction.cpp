#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager * pApp):Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(pClicked.x, pClicked.y);
}

void PasteAction::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* ClipboardFig = pManager->GetClipboardFig();
	if (ClipboardFig == NULL) {
		pOut->PrintMessage("No figure is copied/cut");
		return;
	}

	pOut->PrintMessage("Click where you want to paste the figure");
	ReadActionParameters();

	Point P1 = { 0,0 }, P2 = { 0,0 }, P3 = { 0,0 };
	if (dynamic_cast<CRectangle*>(ClipboardFig)) {
		ClipboardFig->GetFigPoints(P1, P2);
		Point C = { (P1.x+P2.x)/2, (P1.y+P2.y)/2 };
		Point T = { pClicked.x - C.x , pClicked.y - C.y };
		Point PA = { P1.x + T.x, P1.y + T.y };
		Point PB = { P2.x + T.x, P2.y + T.y };
		CRectangle* TranslatedRectangle = new CRectangle(PA,PB, ClipboardFig->GetFigGfxInfo() );
		pManager->AddFigure(TranslatedRectangle);
	}
	else if (dynamic_cast<CTriangle*>(ClipboardFig)) {
		ClipboardFig->GetFigPoints(P1, P2, P3);
		Point C = { (P1.x + P2.x + P3.x) / 3, (P1.y + P2.y + P3.y) / 3 };
		Point T = { pClicked.x - C.x , pClicked.y - C.y };
		Point PA = { P1.x + T.x, P1.y + T.y };
		Point PB = { P2.x + T.x, P2.y + T.y };
		Point PC = { P3.x + T.x, P3.y + T.y };
		CTriangle* TranslatedTriangle = new CTriangle(PA, PB, PC, ClipboardFig->GetFigGfxInfo());
		pManager->AddFigure(TranslatedTriangle);
	}
	else if (dynamic_cast<CEllipse*>(ClipboardFig)) {
		CEllipse* TranslatedEllipse = new CEllipse(pClicked, ClipboardFig->GetFigGfxInfo());
		pManager->AddFigure(TranslatedEllipse);
	}
	else if (dynamic_cast<CRhombus*>(ClipboardFig)) {
		CRhombus* TranslatedRhombus = new CRhombus(pClicked, ClipboardFig->GetFigGfxInfo());
		pManager->AddFigure(TranslatedRhombus);
	}
	else if (dynamic_cast<CLine*>(ClipboardFig)) {
		ClipboardFig->GetFigPoints(P1, P2);
		Point C = { (P1.x + P2.x) / 2, (P1.y + P2.y) / 2 };
		Point T = { pClicked.x - C.x , pClicked.y - C.y };
		Point PA = { P1.x + T.x, P1.y + T.y };
		Point PB = { P2.x + T.x, P2.y + T.y };
		CLine* TranslatedLine = new CLine(PA,PB, ClipboardFig->GetFigGfxInfo());
		pManager->AddFigure(TranslatedLine);
	}

	if (pManager->GetCutFig() != NULL) {
		pManager->DeleteFigure(pManager->GetCutFig());
		pManager->SetCutFig(NULL);
		pManager->UpdateInterface();
	}
	pManager->SetSelectedFig(NULL);
	pOut->PrintMessage("Figure is pasted");

}

PasteAction::~PasteAction()
{

}
