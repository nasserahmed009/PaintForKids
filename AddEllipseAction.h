#ifndef ADD_ELLI_ACTION_H
#define ADD_ELLI_ACTION_H

#include "Actions\Action.h"

//Add Ellipse Action class
class AddEllipseAction: public Action
{
private:
	Point P1; //Ellipse Midpoint
	GfxInfo ElliGfxInfo;
public:
	AddEllipseAction(ApplicationManager *pApp);

	//Reads Ellipse parameters
	virtual void ReadActionParameters();
	
	//Add Ellipse to the ApplicationManager
	virtual void Execute() ;
	
};

#endif