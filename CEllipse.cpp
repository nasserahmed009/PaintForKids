#include "CEllipse.h"

CEllipse::CEllipse(Point P1,  GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}
	

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawEllipse(Corner1,  FigGfxInfo, Selected);
}

bool CEllipse::PointInFigure(Point P1)
{
	bool condition = (pow( (P1.x - Corner1.x)*1.0 / 125 , 2)+pow((P1.y - Corner1.y)*1.0 / 200, 2) <= 1);
	if (condition) {
		return true;
	}
	return false;
}

void CEllipse::PrintInfo(Output * pOut)
{
}

void CEllipse::Save(ofstream &OutFile) {
	OutFile << "Ellipse" << ID << "  " << Corner1.x << "  " << Corner1.y << "  ";
}

void CEllipse::Hide(bool h)
{
	isHidden = h;
}

GfxInfo CEllipse::GetFigGfxInfo()
{
	return FigGfxInfo;
}

bool CEllipse::checkHidden()
{
	return isHidden;
}
