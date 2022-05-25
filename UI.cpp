#include "UI.h"
#include<iostream>
#include"Time.h"
#include"PreparationEvent.h"
#include"CancelEvent.h"
#include"PromoteEvent.h"
#include<Windows.h>

using namespace std;


void UI::Display(Company& C, int Type, Time CurrentTime)
{
	system("cls");
	if (Type == 1 || Type == 2)
	{
		cout << "Current Time(Day:Hour) :" << CurrentTime.day << ":" << CurrentTime.hour << endl;
		cout << endl;
		cout << C.WaitingNormalCount()+ C.WaitingSpecialCount()+ C.WaitingVIPCount() << "  Waiting Cargos: [";
		C.PrintWNC();
		cout << "] (";
		C.PrintWSC();
		cout << ") {";
		C.PrintWVC();
		cout << "}" << endl;
		cout << "-------------------------------------------------------" << endl;
		Truck* N;
		Truck* S;
		Truck* V;
		N = C.GetNormalLoadingTruck();
		S = C.GetSpecialLoadingTruck();
		V = C.GetVIPLoadingTruck();
		cout << C.GetLoadingTruckCount() << " Loading Trucks: ";
		if (N)
		{  
			cout << N->GetTID();
			if (N->IsEmpty())
				cout << "[ ]";
			else
			N->PrintTruckCargos();
		}
		else
		{
			cout << " [ ] ";
		}
		if (S)
		{
			cout << S->GetTID();
			if (S->IsEmpty())
				cout << "( )";
			else
			S->PrintTruckCargos();
		}
		else
		{
			cout << " ( ) ";
		}
		if (V)
		{
			cout << V->GetTID();
			if (V->IsEmpty())
				cout << "{ }";
			else
			V->PrintTruckCargos();
		}
		else
		{
			cout << " { } ";
		}
		cout << endl;
		cout << "-------------------------------------------------------" << endl;


		cout << C.GetEmptyTruckCount() << "  Empty Trucks: [";
		C.PrintENT();
		cout << "] (";
		C.PrintEST();
		cout << ") {";
		C.PrintEVT();
		cout << "}" << endl;
		cout << "-------------------------------------------------------" << endl;

		cout << C.GetMovingCargoCount() << " Moving Cargos: ";
		C.PrintMovingTrucks();
		cout << endl;
		cout << "-------------------------------------------------------" << endl;


		cout << C.GetCheckupCount() << " In-Checkup Trucks: [";
		C.PrintNCT();
		cout << "] (";
		C.PrintSCT();
		cout << ") {";
		C.PrintVCT();
		cout << "}" << endl;
		cout << "-------------------------------------------------------" << endl;


		cout << C.DeliveredCount() << "  Delivered Cargos:";
		C.PrintDC();
		cout << endl;
		cout << "-------------------------------------------------------" << endl;

		if (Type == 1)
			cin.get();
		if (Type == 2)
			Sleep(0);
	}
}

void  UI::DisplayT3(Company& C,int Type,Time EndSimTime)
{
		C.GenerateOutputFile(EndSimTime);
	if (Type == 3)
	{
		cout << "Silent Mode " << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
	}
}
