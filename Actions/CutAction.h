#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../CTriangle.h"
#include "../CRhombus.h"
#include "../CEllipse.h"
#include "../CLine.h"
class CutAction :
	public Action
{
private:
	Point pClicked;
public:
	CutAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~CutAction();
};
