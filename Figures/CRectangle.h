#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	bool PointInFigure(Point P1);
	virtual void Draw(Output* pOut) const;
	void Hide(bool);
	bool checkHidden();
	GfxInfo GetFigGfxInfo();
};

#endif