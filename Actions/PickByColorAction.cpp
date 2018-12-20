#include "PickByColorAction.h"
#include "../ApplicationManager.h"
#include "../includeFiles/AllFigures.h"
#include<iostream>


PickByColorAction::PickByColorAction(ApplicationManager * pApp) :Action(pApp)
{
	if (!pManager->getSound())
		PlaySound("Sounds\\pickbycolor.wav", NULL, SND_ASYNC);
}

void PickByColorAction::ReadActionParameters()
{
}

void PickByColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int CorrectPicks = 0;
	int WrongPicks = 0;
	int numOfSelected = 0;
	int num;
	string msg;
	bool ended = true;
	ActionType act = EMPTY;
	if (pManager->CheckDrawings()) {
		do {
			int range = 5;
			num = std::rand() % range + 1;

			switch (num) {
			case 1: {
				msg = "Black Figures";
				numOfSelected = pManager->NumOfBlack();

			}
					break;
			case 2: {
				msg = "White Figures";
				numOfSelected = pManager->NumOfWhite();
			}
					break;
			case 3: {
				msg = "Red Figures";
				numOfSelected = pManager->NumOfRed();
			}
					break;
			case 4: {
				msg = "Green Figures";
				numOfSelected = pManager->NumOfGreen();
			}
					break;
			case 5: {
				msg = "Blue Figures";
				numOfSelected = pManager->NumOfBlue();
			}
					break;
			}
		} while (numOfSelected == 0);
		pOut->PrintMessage("Select All " + msg);
		while (numOfSelected > 0) {
			pIn->GetPointClicked(pClicked.x, pClicked.y);
			CFigure* selected = pManager->GetFigure(pClicked.x, pClicked.y);
			if (pClicked.y >= 0 && pClicked.y < UI.ToolBarHeight) {
				//pOut->PrintMessage("Game Restarted");
				int ClickedItemOrder = (pClicked.x / UI.MenuItemWidth);
				switch (ClickedItemOrder)
				{
				case ITM_PickByFigure:
					act = PICK_BY_FIGURE;
					break;
				case ITM_PickByColor:
					act = PICK_BY_COLOR;
					break;
				case ITM_TO_DRAW:
					act = TO_DRAW;
					break;
				case ITM_ExitProg:
					act = EXIT;
					break;
				default: act = EMPTY;	//A click on empty place in desgin toolbar
				}
				if (act != EMPTY) {
					ended = false;
					break;
				}
			}
			if (selected == NULL) {
				continue;
			}
			if (selected->checkHidden()) {
				continue;
			}
			CLine* rPtr = dynamic_cast<CLine*>(selected);
			GfxInfo g1;
			g1 = selected->GetFigGfxInfo();
			switch (num) {
			case 1: {
				GfxInfo g1;
				g1=selected->GetFigGfxInfo();
				if (rPtr != NULL) {
					if (g1.DrawClr == BLACK) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				else {
					if (g1.FillClr == BLACK) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				selected->Hide(true);
			}
					break;
			case 2: {
				GfxInfo g1;
				g1 = selected->GetFigGfxInfo();
				if (rPtr != NULL) {
					if (g1.DrawClr == WHITE) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				else {
					if (g1.FillClr == WHITE) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				selected->Hide(true);
			}
					break;
			case 3: {
				if (rPtr != NULL) {
					if (g1.DrawClr == RED) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				else {
					if (g1.FillClr == RED) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				selected->Hide(true);
			}
					break;
			case 4: {
				if (rPtr != NULL) {
					if (g1.DrawClr == GREEN) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				else {
					if (g1.FillClr == GREEN) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				selected->Hide(true);
			}
					break;

			case 5: {
				if (rPtr != NULL) {
					if (g1.DrawClr == BLUE) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				else {
					if (g1.FillClr == BLUE) {
						CorrectPicks++;
						numOfSelected--;
					}
					else {
						WrongPicks++;
					}
				}
				selected->Hide(true);
			}
					break;
			}
			pOut->ClearDrawArea();
			pManager->UpdateInterface();
		}
		if (ended) {
			pOut->PrintMessage("Game Ended, Final score is : Correct picks= " + std::to_string(CorrectPicks) + " , Wrong picks= " + std::to_string(WrongPicks));
		}
		pManager->Hide_UnhideAll(false);
		pManager->UpdateInterface();
		if (!ended) {
			pManager->ExecuteAction(act);
		}
	}
	else {
		pOut->PrintMessage("You need to draw some shapes before you play");
	}
	
}

PickByColorAction::~PickByColorAction()
{
}
