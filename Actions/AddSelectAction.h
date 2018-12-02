#pragma once
#include "Action.h"
class AddSelectAction :
	public Action
{
protected:
	Point pClicked;
public:
	AddSelectAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	~AddSelectAction();
};

