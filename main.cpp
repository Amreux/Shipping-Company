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
	cin >> Type;
	Interface.Simulate(C, Type,"");
}