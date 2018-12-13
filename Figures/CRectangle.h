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
	int getID() {
		return ID;
	};
	void PrintInfo(Output* pOut);
	int getWidth();
	int getHeight();
	void Save(ofstream &OutFile);

	void Hide(bool);
	bool checkHidden();
	GfxInfo GetFigGfxInfo();
	void GetFigPoints(Point &P1, Point &P2);
};

#endif