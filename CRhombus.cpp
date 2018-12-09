#include "CRhombus.h"

CRhombus::CRhombus(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	this->C = P;
	d = 150;
	P1.x = C.x + d; P1.y = C.y;
	P2.x = C.x; P2.y = C.y + d;
	P3.x = C.x - d; P3.y = C.y;
	P4.x = C.x; P4.y = C.y - d;

}

void CRhombus::ChngFigSize(double figSize)
{
	P1.x -= C.x; P1.y -= C.y;
	P2.x -= C.x; P2.y -= C.y;
	P3.x -= C.x; P3.y -= C.y;
	P4.x -= C.x; P4.y -= C.y;
	P1.x *= figSize; P1.y *= figSize;
	P2.x *= figSize; P2.y *= figSize;
	P3.x *= figSize; P3.y *= figSize;
	P4.x *= figSize; P4.y *= figSize;
	P1.x += C.x; P1.y += C.y;
	P2.x += C.x; P2.y += C.y;
	P3.x += C.x; P3.y += C.y;
	P4.x += C.x; P4.y += C.y;
}

void CRhombus::Draw(Output* pOut) const
{	

	pOut->DrawRhombus(P1,P2,P3,P4, FigGfxInfo, Selected);
}

bool CRhombus::PointInFigure(Point P1)
{
	// Check if the point lies inside the rhombus or no
	bool condition = ( (abs((P1.x - C.x)*1.0 / d) + abs((P1.y - C.y)*1.0 / d)) <= 1 );
	if (condition) {
		return true;
	}
	return false;
}

void CRhombus::GetFigPoints(Point & P)
{
	P = C;
}
