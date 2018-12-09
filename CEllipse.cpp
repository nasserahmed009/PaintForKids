#include "CEllipse.h"

CEllipse::CEllipse(Point P1,  GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	this->P1 = P1;
	dx = 93.75, dy = 150;
	P2 = { P1.x + dx, P1.y + dy}; //Upper right corner
	P3 = { P1.x - dx, P1.y - dy}; //Lower left corner
}
	
void CEllipse::ChngFigSize(double figSize) 
{
	Point C = { (P2.x + P3.x) / 2 , (P2.y + P3.y) / 2 };
	P2.x -= C.x; P2.y -= C.y;
	P3.x -= C.x; P3.y -= C.y;
	P2.x *= figSize; P2.y *= figSize;
	P3.x *= figSize; P3.y *= figSize;
	P2.x += C.x; P2.y += C.y;
	P3.x += C.x; P3.y += C.y;
}
 
void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawEllipse(P2, P3,  FigGfxInfo, Selected);
}

bool CEllipse::PointInFigure(Point P1)
{
	bool condition = (pow( (P1.x - this->P1.x)*1.0 / dx , 2)+pow((P1.y - this->P1.y)*1.0 / dy, 2) <= 1);
	if (condition) {
		return true;
	}
	return false;
}

void CEllipse::GetFigPoints(Point & P1)
{
	P1 = this->P1;
}
