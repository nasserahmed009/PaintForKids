#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../CTriangle.h"
#include "../CRhombus.h"
#include "../CEllipse.h"
#include "../CLine.h"
class BringFrontAction : public Action
{
private:
public:
	BringFrontAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~BringFrontAction();
};

