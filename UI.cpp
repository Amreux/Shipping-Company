#include "UI.h"
#include<fstream>
#include<iostream>
#include"Time.h"
#include"PreparationEvent.h"
#include"CancelEvent.h"
#include"PromoteEvent.h"
#include<Windows.h>

using namespace std;
void UI::LoadFile( Company& C)
{
	ifstream InputFile("Input.txt");
	if (!InputFile.is_open())
	{
		cout << "Could not open the file..." << endl;
		return;
	}
	ofstream OutputFile("Output.txt");
	OutputFile << "Done";
	int No_Events;
	InputFile >> No_Events;
	char EventType, CargoType;
	Time T;
	int ID, Distance, LoadTime, Cost,ExtraCost;
	for (int i = 0; i < No_Events; i++)
	{
			InputFile >> EventType;
			switch (EventType)
			{
			case 'R':
			{
				PreparationEvent* RE = new PreparationEvent;
				InputFile >> CargoType >> T.day;
				InputFile.ignore();
				InputFile >> T.hour >> ID >> Distance >> LoadTime >> Cost;
				RE->SetParameters(CargoType, T, Distance, LoadTime, Cost, ID);
				RE->SetEventTime(T);
				C.AddEvent(RE);
				break;
			}
			case 'X':
			{
				CancelEvent* CE = new CancelEvent;
				InputFile  >> T.day;
				InputFile.ignore();
				InputFile >> T.hour >> ID;
				CE->SetParameters(ID);
				CE->SetEventTime(T);
				C.AddEvent(CE);
				break;
			}
			case 'P':
			{
				PromoteEvent* PE = new PromoteEvent;
				InputFile >> T.day;
				InputFile.ignore();
				InputFile >> T.hour >> ID >> ExtraCost;
				PE->SetParameters(ID, ExtraCost);
				PE->SetEventTime(T);
				C.AddEvent(PE);
			}
			}
	}
}

void UI::GenerateOutputFile(Company& C)
{

}


void UI::Simulate(Company& C,int Type)
{
	int hour = 0;
	int day = 0;
	int DeliveryPeriod = 0;
	LoadFile(C);
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
		
		Cargo Temp1;
		bool Test1;
		Test1 = C.DequeueWSC(Temp1);
		if (Test1)
			C.EnqueueMSC(Temp1);
		Test1 = C.DequeueWVC(Temp1);
		if (Test1)
			C.EnqueueMVC(Temp1);
		Test1 = C.RemoveFirstWNC(Temp1);
		if (Test1)
			C.EnqueueMNC(Temp1);

		if (DeliveryPeriod % 5 == 0)
		{
			Cargo Temp2;
			bool Test2;
			Test2 = C.DequeueMSC(Temp2);
			if (Test2)
				C.EnqueueDSC(Temp2);
			Test2 = C.DequeueMVC(Temp2);
			if (Test2)
				C.EnqueueDVC(Temp2);
			Test2 = C.DequeueMNC(Temp2);
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

	cout << C.MovingCount() << "  Moving Cargos: [";
	C.PrintMNC();
	cout << "] (";
	C.PrintMSC();
	cout << ") {";
	C.PrintMVC();
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