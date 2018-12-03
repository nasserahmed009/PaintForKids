#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		            //Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig;           //Pointer to the selected figure
	CFigure* Clipboard;             //Pointer to the copied/cut figure

	CFigure* CutFig;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	
	ActionType ChooseClr;            //Choose color action
	GfxInfo gfxInfo;                 //to be used with draw function of the class Ouput

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions

	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ;          //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);            //Adds a new figure to the FigList
	CFigure *GetCutFig();
	void SetCutFig(CFigure * pFig);
	CFigure *GetFigure(int x, int y) const;
	void DeleteFigure(CFigure * pFig);
	//Search for a figure given a point inside the figure
	void DeselectAll();
		
	// -- Interface Management Functions
	Input *GetInput() const;                  //Return pointer to the input
	Output *GetOutput() const;                //Return pointer to the output
	void UpdateInterface() const;	          //Redraws all the drawing window

	// -- ClipboardFig & SelectedFig Management Functions
	void SetClipboard(CFigure* pFig);
	void SetSelectedFig(CFigure* pFig);
	void ClearClipboard();
	CFigure* GetSelectedFig();
	CFigure* GetClipboardFig();
};

#endif