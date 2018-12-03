#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CLine::PointInFigure(Point P1)
{
	float slope = (Corner1.y - Corner2.y)*1.0 / (Corner2.x - Corner1.x);
	float lineConstant = -(Corner1.y) - (slope*Corner1.x);
	if (abs(-(P1.y) - (slope*P1.x + lineConstant)) <= 2) {
		return true;
	}
	return false;
}

void CLine::Hide(bool h)
{
	isHidden = h;
}

bool CLine::checkHidden()
{
	return isHidden;
}
