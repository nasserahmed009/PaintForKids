#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../CTriangle.h"
#include "../CRhombus.h"
#include "../CEllipse.h"
#include "../CLine.h"

class CopyAction : public Action
{
private:
	Point pClicked;
public:
	CopyAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~CopyAction();

};

