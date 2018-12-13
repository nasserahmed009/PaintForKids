#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../CTriangle.h"
#include "../CRhombus.h"
#include "../CEllipse.h"
#include "../CLine.h"
class ResizeFigure :public Action
{
private:
	ActionType Size;            //Choose color action
	Output * pOut; Input* pIn;
public:
	ResizeFigure(ApplicationManager * pApp, Output* pOut, Input* pIn);
	void ReadActionParameters();
	void Execute();
	~ResizeFigure();
};

