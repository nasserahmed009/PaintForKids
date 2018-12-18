#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../CTriangle.h"
#include "../CRhombus.h"
#include "../CEllipse.h"
#include "../CLine.h"
class BringBackAction :
	public Action
{
public:
	BringBackAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~BringBackAction();
};

