#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CRhombus.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CLine.h"
class PasteAction : public Action
{
private:
	Point pClicked;
public:
	PasteAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~PasteAction();
};

