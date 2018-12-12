#include "CTriangle.h"
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
	

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

bool CTriangle::PointInFigure(Point P1)
{
	//Check the area of the whole triangle
	float area = abs( Corner1.x*(Corner2.y - Corner3.y) + Corner2.x*(Corner3.y - Corner1.y) + Corner3.x*(Corner1.y - Corner2.y) );
	
	//Check the area of the three small triangles inside tha main triangle
	float area1 = abs(Corner1.x*(P1.y - Corner3.y) + P1.x*(Corner3.y - Corner1.y) + Corner3.x*(Corner1.y - P1.y));
	float area2 = abs(Corner1.x*(Corner2.y - P1.y) + Corner2.x*(P1.y - Corner1.y) + P1.x*(Corner1.y - Corner2.y));
	float area3 = abs(P1.x*(Corner2.y - Corner3.y) + Corner2.x*(Corner3.y - P1.y) + Corner3.x*(P1.y - Corner2.y));

	if (area == area1 + area2 + area3) {
		return true;
	}
	return false;

}

void CTriangle::PrintInfo(Output * pOut)
{
}

void CTriangle::Save(ofstream &OutFile) {
	OutFile << "Triangle " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  " << Corner3.x << "  " << Corner3.y << "  ";
}
