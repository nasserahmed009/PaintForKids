#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CLine::ChngFigSize(double figSize)
{
	Point C = { (Corner1.x + Corner2.x) / 2 , (Corner1.y + Corner2.y) / 2 };
	Corner1.x -= C.x; Corner1.y -= C.y;
	Corner2.x -= C.x; Corner2.y -= C.y;
	Corner1.x *= figSize; Corner1.y *= figSize;
	Corner2.x *= figSize; Corner2.y *= figSize;
	Corner1.x += C.x; Corner1.y += C.y;
	Corner2.x += C.x; Corner2.y += C.y;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}




void CLine::PrintInfo(Output * pOut)
{
}

void CLine::Save(ofstream &OutFile) {
	OutFile << "Line " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  ";
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

void CLine::Hide(bool h){
	isHidden = h;
}

GfxInfo CLine::GetFigGfxInfo()
{
	return FigGfxInfo;
}

bool CLine::checkHidden()
{
	return isHidden;
}

void CLine::GetFigPoints(Point & P1, Point & P2)
{
	P1 = Corner1;
	P2 = Corner2;
}
