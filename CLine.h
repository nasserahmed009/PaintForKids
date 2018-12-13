#pragma once
#include "figures\cfigure.h"

class CLine :
	public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	void ChngFigSize(double figSize);
	virtual void Draw(Output* pOut) const;
	bool PointInFigure(Point P1);
	void PrintInfo(Output* pOut);
	void Save(ofstream &);
	void Hide(bool);
	GfxInfo GetFigGfxInfo();
	bool checkHidden();
	void GetFigPoints(Point &P1, Point &P2);
};

