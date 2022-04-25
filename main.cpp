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
	Interface.Simulate(C, 2,"");
}