#include "CTriangle.h"
#include<iostream>
#include <sstream>      // std::istringstream
#include <string> 
using namespace std;
CTriangle::CTriangle()
{
}
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	type = Figure_Type::TRIANGLE;
}


void CTriangle::ChngFigSize(double figSize)
{
	Point C = { (Corner1.x + Corner2.x + Corner3.x) / 3 , (Corner1.y + Corner2.y + Corner3.y) / 3 };
	Corner1.x -= C.x; Corner1.y -= C.y;
	Corner2.x -= C.x; Corner2.y -= C.y;
	Corner3.x -= C.x; Corner3.y -= C.y;
	Corner1.x *= figSize; Corner1.y *= figSize;
	Corner2.x *= figSize; Corner2.y *= figSize;
	Corner3.x *= figSize; Corner3.y *= figSize;
	Corner1.x += C.x; Corner1.y += C.y;
	Corner2.x += C.x; Corner2.y += C.y;
	Corner3.x += C.x; Corner3.y += C.y;
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
	OutFile << "Triangle " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " ";
}
void CTriangle::Hide(bool h)
{
	isHidden = h;
}

GfxInfo CTriangle::GetFigGfxInfo()
{
	return FigGfxInfo;
}

bool CTriangle::checkHidden()
{
	return isHidden;
}

void CTriangle::Load(string s)
{
	string word = s;
	istringstream iss(s);
	string arr[10];
	int k = 0;
	color DrawColor, FillColor;
	while (getline(iss, word, ' '))
	{
		arr[k] = word;
		k++;
	}
	this->ID = stoi(arr[1]);
	this->Corner1.x = stoi(arr[2]);
	this->Corner1.y = stoi(arr[3]);
	this->Corner2.x = stoi(arr[4]);
	this->Corner2.y = stoi(arr[5]);
	this->Corner3.x = stoi(arr[6]);
	this->Corner3.y = stoi(arr[7]);
	//Checks the draw color
	if (arr[8] == "BLACK") {
		DrawColor = BLACK;
	}
	else if (arr[8] == "BLUE") {
		DrawColor = BLUE;
	}
	else if (arr[8] == "WHITE") {
		DrawColor = WHITE;
	}
	else if (arr[8] == "RED") {
		DrawColor = RED;
	}
	else if (arr[8] == "GREEN") {
		DrawColor = GREEN;
	}
	//Checks the fill color
	if (arr[9] == "BLACK") {
		FillColor = BLACK;
	}
	else if (arr[9] == "BLUE") {
		FillColor = BLUE;
	}
	else if (arr[9] == "WHITE") {
		FillColor = WHITE;
	}
	else if (arr[9] == "RED") {
		FillColor = RED;
	}
	else if (arr[9] == "GREEN") {
		FillColor = GREEN;
	}
	this->FigGfxInfo.DrawClr = DrawColor;
	this->FigGfxInfo.FillClr = FillColor;
	this->isHidden = false;
	this->Selected = false;
}

void CTriangle::GetFigPoints(Point & P1, Point & P2, Point & P3)
{
	P1 = Corner1;
	P2 = Corner2;
	P3 = Corner3;
}
