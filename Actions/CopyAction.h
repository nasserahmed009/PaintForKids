#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CRhombus.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CLine.h"

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

