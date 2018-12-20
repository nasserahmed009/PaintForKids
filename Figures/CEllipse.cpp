#include "CEllipse.h"
#include<iostream>
#include <sstream>      // std::istringstream
#include <string> 
using namespace std;
CEllipse::CEllipse() { }
////////////////////////////////////////////////////////////////////////////////////
CEllipse::CEllipse(Point Corner1,  GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	this->Corner1 = Corner1;
	dx = 93.75, dy = 150;
	P2 = { Corner1.x + dx, Corner1.y + dy}; //Upper right corner
	P3 = { Corner1.x - dx, Corner1.y - dy}; //Lower left corner
	type=Figure_Type::ELLIPSE;
	figSize = 1.0;
}
////////////////////////////////////////////////////////////////////////////////////
//change the figure size
void CEllipse::ChngFigSize(double figSize)  // Changes the points of the figure according to the figSize
{
	Point C = { (P2.x + P3.x) / 2 , (P2.y + P3.y) / 2 }; // Gets the centroid
	P2.x -= C.x; P2.y -= C.y; // Translates the axis back to origin
	P3.x -= C.x; P3.y -= C.y;
	P2.x *= figSize; P2.y *= figSize;  // Multiplies the point by the figSize ratio
	P3.x *= figSize; P3.y *= figSize;
	P2.x += C.x; P2.y += C.y; // Translates the axis back to it's original location
	P3.x += C.x; P3.y += C.y;
	this->figSize = this->figSize * figSize;
}

double CEllipse::GetFigSize() // returns the figure size of the ellipse
{
	return figSize;
}
////////////////////////////////////////////////////////////////////////////////////
//Draw the Ellipse
void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawEllipse(P2, P3,  FigGfxInfo, Selected);
}
////////////////////////////////////////////////////////////////////////////////////
//Check if the point in the figure or not
bool CEllipse::PointInFigure(Point Corner1)
{
	bool condition = (pow( (Corner1.x - this->Corner1.x)*1.0 / dx , 2)+pow((Corner1.y - this->Corner1.y)*1.0 / dy, 2) <= 1);
	if (condition) {
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////////
//Print all the info of the ellipse
void CEllipse::PrintInfo(Output * pOut)
{
}
////////////////////////////////////////////////////////////////////////////////////
//Save all the info of the ellipse in text file
void CEllipse::Save(ofstream &OutFile) {
	OutFile << "Ellipse " << ID << " " << Corner1.x << " " << Corner1.y << " ";
}
////////////////////////////////////////////////////////////////////////////////////
//
void CEllipse::Hide(bool h)
{
	isHidden = h;
}
////////////////////////////////////////////////////////////////////////////////////
//load the ellipse info from saved file text
void CEllipse::Load(string s)
{
	string word=s;
	istringstream iss(s);
	string arr[10];
	int k = 0;
	color DrawColor,FillColor;
	while (getline(iss, word, ' '))
	{
		arr[k] = word;
		k++;
	}
	this->type = RECTANGLE;
	this->ID = counter;
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
	this-> FigGfxInfo.FillClr = FillColor;
	this->isHidden = false;
	this->Selected = false;
	dx = 93.75, dy = 150;
	P2 = { Corner1.x + dx, Corner1.y + dy }; //Upper right corner
	P3 = { Corner1.x - dx, Corner1.y - dy }; //Lower left corner
}
////////////////////////////////////////////////////////////////////////////////////
//get the graphics info of the ellipse
GfxInfo CEllipse::GetFigGfxInfo()
{
	return FigGfxInfo;
}
////////////////////////////////////////////////////////////////////////////////////
//
bool CEllipse::checkHidden()
{
	return isHidden;
}
////////////////////////////////////////////////////////////////////////////////////
//get the point of the ellipse
void CEllipse::GetFigPoints(Point & Corner1)
{
	Corner1 = this->Corner1;
}
////////////////////////////////////////////////////////////////////////////////////