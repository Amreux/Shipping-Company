#include "UI.h"
#include<fstream>
#include<iostream>
#include"Time.h"
#include"PreparationEvent.h"
#include"CancelEvent.h"
#include"PromoteEvent.h"
#include<Windows.h>

using namespace std;
void UI::GenerateOutputFile(Company& C)
{

}


void UI::Simulate(Company& C,int Type, string Input)
{
	int hour = 0;
	int day = 0;
	int DeliveryPeriod = 0;
	C.LoadFile("");
	Event* CurrentEvent = nullptr;
	C.DequeueEvent(CurrentEvent);
	while (CurrentEvent || !C.AllIsDelivered())
	{
		system("cls");
		if (Type == 1 || Type == 2)
		{
			cout << "Current Time(Day:Hour) :" << day << ":" << hour << endl;
			Display(C);
		}
		while ( CurrentEvent && CurrentEvent->GetEventTime().day == day && CurrentEvent->GetEventTime().hour == hour)
		{
			CurrentEvent->Execute(C);
			if (!C.DequeueEvent(CurrentEvent))
				CurrentEvent = nullptr;
		}
		
		/*Cargo Temp1;
		bool Test1;
		Test1 = C.DequeueWSC(Temp1);
		if (Test1)
			C.EnqueueMSC(Temp1);
		Test1 = C.DequeueWVC(Temp1);
		if (Test1)
			C.EnqueueMVC(Temp1);
		Test1 = C.RemoveFirstWNC(Temp1);
		if (Test1)
			C.EnqueueMNC(Temp1);*/

		if (DeliveryPeriod % 5 == 0)
		{
			Cargo Temp2;
			bool Test2;
			Test2 = C.DequeueWSC(Temp2);
			if (Test2)
				C.EnqueueDSC(Temp2);
			Test2 = C.DequeueWVC(Temp2);
			if (Test2)
				C.EnqueueDVC(Temp2);
			Test2 = C.RemoveFirstWNC(Temp2);
			if (Test2)
				C.EnqueueDNC(Temp2);
		}
		DeliveryPeriod++;
		hour++;
		if (hour == 24)
		{
			hour = 0;
			day++;
		}
		if (Type == 1)
			cin.get();
		if (Type == 2)
			Sleep(1000);
	}
	system("cls");
	if (Type == 1 || Type == 2)
	{
		cout << "Current Time(Day:Hour) :" << day << ":" << hour << endl;
		Display(C);
		cout << endl;
		cout << "Simulation Finished" << endl;
	}
	else
	{
		GenerateOutputFile(C);
		cout << "Silent Mode " << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
	}
}

void UI::Display(Company& C)
{
	cout << C.WaitingCount() << "  Waiting Cargos: [";
	C.PrintWNC();
	cout << "] (";
	C.PrintWSC();
	cout << ") {";
	C.PrintWVC();
	cout << "}" << endl;
	cout << "-------------------------------------------------------" << endl;

	cout << C.DeliveredCount() << "  Delivered Cargos: [";
	C.PrintDNC();
	cout << "] (";
	C.PrintDSC();
	cout << ") {";
	C.PrintDVC();
	cout << "}" << endl;
}