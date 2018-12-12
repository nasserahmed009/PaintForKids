#include "CRhombus.h"

CRhombus::CRhombus(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	this->Corner1 = P;
	d = 150;
	P1.x = Corner1.x + d; P1.y = Corner1.y;
	P2.x = Corner1.x; P2.y = Corner1.y + d;
	P3.x = Corner1.x - d; P3.y = Corner1.y;
	P4.x = Corner1.x; P4.y = Corner1.y - d;

}

void CRhombus::ChngFigSize(double figSize)
{
	P1.x -= Corner1.x; P1.y -= Corner1.y;
	P2.x -= Corner1.x; P2.y -= Corner1.y;
	P3.x -= Corner1.x; P3.y -= Corner1.y;
	P4.x -= Corner1.x; P4.y -= Corner1.y;
	P1.x *= figSize; P1.y *= figSize;
	P2.x *= figSize; P2.y *= figSize;
	P3.x *= figSize; P3.y *= figSize;
	P4.x *= figSize; P4.y *= figSize;
	P1.x += Corner1.x; P1.y += Corner1.y;
	P2.x += Corner1.x; P2.y += Corner1.y;
	P3.x += Corner1.x; P3.y += Corner1.y;
	P4.x += Corner1.x; P4.y += Corner1.y;
}

void CRhombus::Draw(Output* pOut) const
{	

	pOut->DrawRhombus(P1,P2,P3,P4, FigGfxInfo, Selected);
}

bool CRhombus::PointInFigure(Point P1)
{
	// Check if the point lies inside the rhombus or no
	bool condition = ( (abs((P1.x - Corner1.x)*1.0 / d) + abs((P1.y - Corner1.y)*1.0 / d)) <= 1 );
	if (condition) {
		return true;
	}
	return false;
}

void CRhombus::GetFigPoints(Point & P)
{
	P = Corner1;
}
