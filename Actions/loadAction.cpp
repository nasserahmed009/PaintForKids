#include "loadAction.h"
#include <fstream>
using namespace std;
ifstream inputFile("test.txt", ios::in);

loadAction::loadAction(ApplicationManager * pApp) :Action(pApp)
{
}

void loadAction::ReadActionParameters()
{
}

void loadAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	int x;
	inputFile >> x;
	pOut->PrintMessage(to_string(x));
}


loadAction::~loadAction()
{
}
