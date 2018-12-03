#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddEllipseAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddRhomAction.h"
#include "Actions\AddSelectAction.h"
#include"Actions\PickByColorAction.h"
#include"Actions\PickByFigureAction.h"
#include"Figures/CRectangle.h"
#include"CTriangle.h"
#include"CEllipse.h"
#include"CRhombus.h"
#include"CLine.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhomAction(this);
			break;
		case TO_DRAW:
			pOut->CreateDrawToolBar();
			break;
		case TO_PLAY:
			pOut->CreatePlayToolBar();
			break;

		case SELECT:
			pAct = new AddSelectAction(this);
			break;
		
		case CHNG_DRAW_CLR:
				pOut->PrintMessage("Action: Change Figure's drawing color , Click anywhere");
				pOut->DrawColorPallete(2);
				ChooseClr = pIn->GetClr();
				switch(ChooseClr){
				case PICK_BLACK: UI.DrawColor = BLACK;
								 break;
				case PICK_WHITE: UI.DrawColor = WHITE;
								 break;
				case PICK_RED:   UI.DrawColor = RED;
								 break;
				case PICK_GREEN: UI.DrawColor = GREEN;
								 break;
				case PICK_BLUE:  UI.DrawColor = BLUE;
								 break;
				}
				pOut->ClearColorPallete();
				break;

		case CHNG_FILL_CLR:
				pOut->PrintMessage("Action: Change Figure's Fill color , Click anywhere");
				pOut->DrawColorPallete(1);
				ChooseClr = pIn->GetClr();
				switch(ChooseClr){
				case PICK_BLACK: UI.FillColor = BLACK;
								 break;
				case PICK_WHITE: UI.FillColor = WHITE;
								 break;
				case PICK_RED:   UI.FillColor = RED;
								 break;
				case PICK_GREEN: UI.FillColor = GREEN;
								 break;
				case PICK_BLUE:  UI.FillColor = BLUE;
								 break;
				}
				pOut->ClearColorPallete();
				break;
		case DEL:
				pOut->PrintMessage("Action: a click on the Delete button");
				break;
		case SAVE:
				pOut->PrintMessage("Action: a click on the Save button, Click anywhere");
				break;
		case SAVE_BY_TYPE:
				pOut->PrintMessage("Action: a click on the Save By Type button, Click anywhere");
				break;
		case LOAD:
				pOut->PrintMessage("Action: a click on the Load button, Click anywhere");
				
				break;
		case PICK_BY_FIGURE:
				pOut->PrintMessage("Action: a click on the Pick by figure button, Click anywhere");
				pAct = new PickByFigureAction(this);
				break;
		case PICK_BY_COLOR:
			pOut->PrintMessage("Action: a click on the Pick by color button, Click anywhere");
			pAct = new PickByColorAction(this);
				break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return ;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
bool ApplicationManager::CheckDrawings()
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != NULL) {
			return true;
		}
	}
	return false;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	Point P1;
	P1.x = x;
	P1.y = y;
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->PointInFigure(P1)) {
			return FigList[i];
		}
	}
	return NULL;
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
}
void ApplicationManager::DeselectAll()
{
	//Loop over the figList, finds the selected item and deselect it
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->IsSelected()) {
			FigList[i]->SetSelected(false);
			FigList[i]->ChngDrawClr(BLACK);
			break;
		}
	}
}
void ApplicationManager::Hide_UnhideAll(bool h)
{
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Hide(h);
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for (int i = 0; i < FigCount; i++) {
		if ((FigList[i]->checkHidden())==false) {
			FigList[i]->Draw(pOut);	//Call Draw function (virtual member fn)
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::NumOfrect() {
	CRectangle* rect;
	int number = 0;
	for (int i = 0; i < FigCount; i++) {
		rect = dynamic_cast<CRectangle*>(FigList[i]);
		if (rect != NULL)
			number++;
	}
	return number;
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::NumOfTris() {
	CTriangle* tri;
	int number = 0;
	for (int i = 0; i < FigCount; i++) {
		tri = dynamic_cast<CTriangle*>(FigList[i]);
		if (tri != NULL)
			number++;
	}
	return number;
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::NumOfEli() {
	CEllipse* eli;
	int number = 0;
	for (int i = 0; i < FigCount; i++) {
		eli = dynamic_cast<CEllipse*>(FigList[i]);
		if (eli != NULL)
			number++;
	}
	return number;
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::NumOfRhom() {
	CRhombus* rhom;
	int number = 0;
	for (int i = 0; i < FigCount; i++) {
		rhom = dynamic_cast<CRhombus*>(FigList[i]);
		if (rhom != NULL)
			number++;
	}
	return number;
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::NumOfLines() {
	CLine* line;
	int number = 0;
	for (int i = 0; i < FigCount; i++) {
		line = dynamic_cast<CLine*>(FigList[i]);
		if (line != NULL)
			number++;
	}
	return number;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
