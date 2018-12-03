#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../CTriangle.h"
#include "../CRhombus.h"
#include "../CEllipse.h"
#include "../CLine.h"
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

