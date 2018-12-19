#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CRhombus.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CLine.h"
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

