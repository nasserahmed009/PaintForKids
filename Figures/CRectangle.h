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
	void ChngFigSize(double figSize);
	bool PointInFigure(Point P1);
	virtual void Draw(Output* pOut) const;
	void GetFigPoints(Point &P1, Point &P2);
};

#endif