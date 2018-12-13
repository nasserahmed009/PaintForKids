#ifndef CELLI_H
#define CELLI_H

#include "Figures\CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1, P2, P3;
	int dx, dy;
public:
	CEllipse(Point , GfxInfo FigureGfxInfo );
	void ChngFigSize(double figSize);
	virtual void Draw(Output* pOut) const;
	bool PointInFigure(Point P1);
	void PrintInfo(Output* pOut);
	void Save(ofstream &OutFile);

	void Hide(bool);
	GfxInfo GetFigGfxInfo();
	bool checkHidden();
	void GetFigPoints(Point &P1);
};

#endif