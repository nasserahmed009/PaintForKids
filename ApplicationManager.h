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
	GfxInfo gfxInfo;                 //to be used with draw function of the class Ouput

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions

	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ;          //Creates an action and executes it
	bool CheckDrawings();					  //Checks if there is Figures Drawn	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);            //Adds a new figure to the FigList
	CFigure *GetCutFig();
	void SetCutFig(CFigure * pFig);
	CFigure *GetFigure(int x, int y) const;
	//Search for a figure given a point inside the figure
	void DeselectAll();
	void DeleteSelectedFigure();
		
	void Hide_UnhideAll(bool);
	// -- Interface Management Functions
	Input *GetInput() const;                  //Return pointer to the input
	Output *GetOutput() const;                //Return pointer to the output
	int NumOfrect();
	int NumOfTris();
	int NumOfEli();
	int NumOfRhom();
	int NumOfLines();
	int NumOfBlack();
	int NumOfWhite();
	int NumOfRed();
	int NumOfGreen();
	int NumOfBlue();
	void UpdateInterface() const;	          //Redraws all the drawing window	

	void SaveAll(ofstream &);
	void SaveAllAction();
	string getcolorname(color);
	// -- ClipboardFig & SelectedFig Management Functions
	void SetClipboard(CFigure* pFig);
	void SetSelectedFig(CFigure* pFig);
	void ClearClipboard();
	CFigure* GetSelectedFig();
	CFigure* GetClipboardFig();
};

#endif