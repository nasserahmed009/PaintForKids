#include "CFigure.h"

int CFigure::counter = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = ++counter;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::setPrevDrawColor(color c)
{
	PrevDrawColor = c;
}

color CFigure::getPrevDrawColor()
{
	return PrevDrawColor;
}

color CFigure::getDrawColor()
{
	return FigGfxInfo.DrawClr;
}

color CFigure::getFillColor()
{
	return FigGfxInfo.FillClr;
}
