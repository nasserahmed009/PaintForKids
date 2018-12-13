#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class loadAction :
	public Action
{
public:
	loadAction();
	loadAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~loadAction();
};

