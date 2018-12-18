#pragma once
#include "Action.h"
#include"../ApplicationManager.h"

class SaveByTypeAction :
	public Action
{
private:
	string name;
	Figure_Type type;
public:
	SaveByTypeAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~SaveByTypeAction();
};

