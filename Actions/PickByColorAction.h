#pragma once
#include "Action.h"
class PickByColorAction :
	public Action
{
public:
	PickByColorAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~PickByColorAction();
};

