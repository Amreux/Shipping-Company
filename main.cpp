#include<iostream>
#include "Company.h"
#include "PreparationEvent.h"
#include "CancelEvent.h"
#include "PromoteEvent.h"
#include"UI.h"
#include<fstream>

using namespace std;

int main()
{
	UI Interface;
	Company C;

	int Type;
	//     Type1---> Interactive Mode 
	//     Type2---> Step-By-STep Mode
	cin >> Type;

	cin.get();
	Interface.Simulate(C, Type,"");
}