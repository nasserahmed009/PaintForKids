#ifndef CRHOM_H
#define CRHOM_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	int d;
	Point Corner1,P1,P2,P3,P4;
public:
	CRhombus();
	CRhombus(Point , GfxInfo FigureGfxInfo );
	void ChngFigSize(double figSize);
	virtual void Draw(Output* pOut) const;
	bool PointInFigure(Point P1);
	void GetFigPoints(Point & P1);
	Point getCenter();
	void PrintInfo(Output* pOut);
	void Save(ofstream &);
	void Hide(bool);
	void Load(string);

	GfxInfo GetFigGfxInfo();
	bool checkHidden();
};

#endif