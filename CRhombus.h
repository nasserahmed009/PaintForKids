#ifndef CRHOM_H
#define CRHOM_H

#include "Figures\CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Corner1;	
	
public:
	CRhombus(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool PointInFigure(Point P1);
	void Hide(bool);
	GfxInfo GetFigGfxInfo();
	bool checkHidden();
};

#endif