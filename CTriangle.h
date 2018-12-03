#ifndef CTRI_H
#define CTRI_H

#include "Figures\CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point, Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool PointInFigure(Point P1);
	void Hide(bool);
	GfxInfo GetFigGfxInfo();
	bool checkHidden();
};

#endif