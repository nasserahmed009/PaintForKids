#ifndef CELLI_H
#define CELLI_H

#include "Figures\CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1;	
public:
	CEllipse(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool PointInFigure(Point P1);
	void Hide(bool);
	GfxInfo GetFigGfxInfo();
	bool checkHidden();
};

#endif