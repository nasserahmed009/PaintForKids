#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
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

void CFigure::ChngFigSize(double figSize)
{
}

void CFigure::GetFigPoints(Point & P1)
{
}

void CFigure::GetFigPoints(Point & P1, Point & P2)
{
}

void CFigure::GetFigPoints(Point & P1, Point & P2, Point & P3)
{
}

GfxInfo CFigure::GetFigGfxInfo()
{
	return FigGfxInfo;
}

