#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager * pApp):Action(pApp)
{
	if (!pManager->getSound())
		PlaySound("Sounds\\paste.wav", NULL, SND_ASYNC);
}

void PasteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(pClicked.x, pClicked.y);
}

void PasteAction::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* ClipboardFig = pManager->GetClipboardFig(); // Gets the clipboard figure

	if (ClipboardFig == NULL) { // If nothing is copied/cut, informs the user and exits from the function
		pOut->PrintMessage("No figure is copied/cut");
		return;
	}

	pOut->PrintMessage("Click where you want to paste the figure");
	ReadActionParameters(); // Gets point from user to paste the figure at

	Point P1 = { 0,0 }, P2 = { 0,0 }, P3 = { 0,0 }; // Makes temporary points

	if (dynamic_cast<CRectangle*>(ClipboardFig)) {	// If the clipboard figure is a rectangle
		ClipboardFig->GetFigPoints(P1, P2);	// Gets the points of the clipboard figure
		Point C = { (P1.x+P2.x)/2, (P1.y+P2.y)/2 }; // Gets the centroid of the figure
		Point T = { pClicked.x - C.x , pClicked.y - C.y }; // Magnitude of translation = Point clicked - Centroid of figure
		Point PA = { P1.x + T.x, P1.y + T.y }; // Adds the magnitude of translation to the points
		Point PB = { P2.x + T.x, P2.y + T.y }; // ^^
		CRectangle* TranslatedRectangle = new CRectangle(PA,PB, ClipboardFig->GetFigGfxInfo() ); // Creates a new figure with the data of the copied figure
		pManager->AddFigure(TranslatedRectangle); // Adds the translated figure to the figure list
	}
	else if (dynamic_cast<CTriangle*>(ClipboardFig)) { // If the clipboard figure is a triangle
		ClipboardFig->GetFigPoints(P1, P2, P3); 
		Point C = { (P1.x + P2.x + P3.x) / 3, (P1.y + P2.y + P3.y) / 3 }; 
		Point T = { pClicked.x - C.x , pClicked.y - C.y }; 
		Point PA = { P1.x + T.x, P1.y + T.y }; 
		Point PB = { P2.x + T.x, P2.y + T.y }; 
		Point PC = { P3.x + T.x, P3.y + T.y }; 
		CTriangle* TranslatedTriangle = new CTriangle(PA, PB, PC, ClipboardFig->GetFigGfxInfo()); 
		pManager->AddFigure(TranslatedTriangle); 
	}
	else if (dynamic_cast<CEllipse*>(ClipboardFig)) { // If the clipboard figure is an ellipse
		CEllipse* TranslatedEllipse = new CEllipse(pClicked, ClipboardFig->GetFigGfxInfo());
		TranslatedEllipse->ChngFigSize( ClipboardFig->GetFigSize()); // Resizes the new copy to ellipse size
		pManager->AddFigure(TranslatedEllipse);
	}
	else if (dynamic_cast<CRhombus*>(ClipboardFig)) {
		CRhombus* TranslatedRhombus = new CRhombus(pClicked, ClipboardFig->GetFigGfxInfo()); // If the clipboard figure is a rhombus
		TranslatedRhombus->ChngFigSize(ClipboardFig->GetFigSize()); // Resizes the new copy to rhombus size
		pManager->AddFigure(TranslatedRhombus);
	}
	else if (dynamic_cast<CLine*>(ClipboardFig)) { // If the clipboard figure is a line
		ClipboardFig->GetFigPoints(P1, P2);
		Point C = { (P1.x + P2.x) / 2, (P1.y + P2.y) / 2 };
		Point T = { pClicked.x - C.x , pClicked.y - C.y };
		Point PA = { P1.x + T.x, P1.y + T.y };
		Point PB = { P2.x + T.x, P2.y + T.y };
		CLine* TranslatedLine = new CLine(PA,PB, ClipboardFig->GetFigGfxInfo());
		pManager->AddFigure(TranslatedLine);
	}

	if (pManager->GetCutFig() != NULL) { // If the figure is cut and not copied
		pManager->DeleteFigure(pManager->GetCutFig()); // Delete the figure and reset the CutFig to NULL
		pManager->SetCutFig(NULL);
		pManager->UpdateInterface();
	}

	pManager->SetSelectedFig(NULL); // Reset the selectedFig to NULL
	pOut->PrintMessage("Figure is pasted");

}

PasteAction::~PasteAction()
{

}
