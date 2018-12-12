#include "CRhombus.h"

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}
	

void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRhombus(Corner1, FigGfxInfo, Selected);
}

bool CRhombus::PointInFigure(Point P1)
{
	// Check if the point lies inside the rhombus or no
	bool condition = ( (abs((P1.x - Corner1.x)*1.0 / 200) + abs((P1.y - Corner1.y)*1.0 / 200)) <= 1 );
	if (condition) {
		return true;
	}
	return false;
}

Point CRhombus::getCenter()
{
	return Corner1;
}

void CRhombus::PrintInfo(Output * pOut)
{
}

void CRhombus::Save(ofstream &OutFile) {
	OutFile << "Rhombus " << ID << "  " << Corner1.x << "  " << Corner1.y << "  ";

}
