#include "CLine.h"
#include<iostream>
#include <sstream>      // std::istringstream
#include <string> 
using namespace std;
CLine::CLine()
{
}

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	type=Figure_Type::LINE;
}
	

void CLine::ChngFigSize(double figSize) // Changes size of figure
{
	Point C = { (Corner1.x + Corner2.x) / 2 , (Corner1.y + Corner2.y) / 2 }; // Gets the centroid
	Corner1.x -= C.x; Corner1.y -= C.y; // Translates the axis back to origin
	Corner2.x -= C.x; Corner2.y -= C.y;
	Corner1.x *= figSize; Corner1.y *= figSize; // Multiplies the point by the figSize ratio
	Corner2.x *= figSize; Corner2.y *= figSize;
	Corner1.x += C.x; Corner1.y += C.y; // Translates the axis back to it's original location
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
	OutFile << "Line " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
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

void CLine::Load(string s)
{
	string word = s;
	istringstream iss(s);
	string arr[10];
	int k = 0;
	color DrawColor;
	while (getline(iss, word, ' '))
	{
		arr[k] = word;
		k++;
	}
	this->type = LINE;
	this->ID = counter;
	this->Corner1.x = stoi(arr[2]);
	this->Corner1.y = stoi(arr[3]);
	this->Corner2.x = stoi(arr[4]);
	this->Corner2.y = stoi(arr[5]);
	//Checks the draw color
	if (arr[6] == "BLACK") {
		DrawColor = BLACK;
	}
	else if (arr[6] == "BLUE") {
		DrawColor = BLUE;
	}
	else if (arr[6] == "WHITE") {
		DrawColor = WHITE;
	}
	else if (arr[6] == "RED") {
		DrawColor = RED;
	}
	else if (arr[6] == "GREEN") {
		DrawColor = GREEN;
	}
	this->FigGfxInfo.DrawClr = DrawColor;
	this->FigGfxInfo.FillClr = BLUE;
	this->FigGfxInfo.isFilled = false;
	this->isHidden = false;
	this->Selected = false;
}

void CLine::GetFigPoints(Point & P1, Point & P2)
{
	P1 = Corner1;
	P2 = Corner2;
}
