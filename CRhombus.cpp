#include "CRhombus.h"
#include<iostream>
#include <sstream>      // std::istringstream
#include <string> 
using namespace std;

CRhombus::CRhombus()
{
}

CRhombus::CRhombus(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	this->Corner1 = P;
	d = 150;
	P1.x = Corner1.x + d; P1.y = Corner1.y;
	P2.x = Corner1.x; P2.y = Corner1.y + d;
	P3.x = Corner1.x - d; P3.y = Corner1.y;
	P4.x = Corner1.x; P4.y = Corner1.y - d;
	type = Figure_Type::RHUMBOS;

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

Point CRhombus::getCenter()
{
	return Corner1;
}

void CRhombus::PrintInfo(Output * pOut)
{
}

void CRhombus::Save(ofstream &OutFile) {
	OutFile << "Rhombus " << ID << " " << Corner1.x << " " << Corner1.y << " ";
}
void CRhombus::Hide(bool h)
{
	isHidden = h;
}

void CRhombus::Load(string s)
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
	//Checks the draw color
	if (arr[4] == "BLACK") {
		DrawColor = BLACK;
	}
	else if (arr[4] == "BLUE") {
		DrawColor = BLUE;
	}
	else if (arr[4] == "WHITE") {
		DrawColor = WHITE;
	}
	else if (arr[4] == "RED") {
		DrawColor = RED;
	}
	else if (arr[4] == "GREEN") {
		DrawColor = GREEN;
	}
	//Checks the fill color
	if (arr[5] == "BLACK") {
		FillColor = BLACK;
	}
	else if (arr[5] == "BLUE") {
		FillColor = BLUE;
	}
	else if (arr[5] == "WHITE") {
		FillColor = WHITE;
	}
	else if (arr[5] == "RED") {
		FillColor = RED;
	}
	else if (arr[5] == "GREEN") {
		FillColor = GREEN;
	}
	this->FigGfxInfo.DrawClr = DrawColor;
	this->FigGfxInfo.FillClr = FillColor;
	this->isHidden = false;
	this->Selected = false;
	this->d = 150;
	P1.x = Corner1.x + d; P1.y = Corner1.y;
	P2.x = Corner1.x; P2.y = Corner1.y + d;
	P3.x = Corner1.x - d; P3.y = Corner1.y;
	P4.x = Corner1.x; P4.y = Corner1.y - d;
}

GfxInfo CRhombus::GetFigGfxInfo()
{
	return FigGfxInfo;
}

bool CRhombus::checkHidden()
{
	return isHidden;
}

void CRhombus::GetFigPoints(Point & P)
{
	P = Corner1;
}
