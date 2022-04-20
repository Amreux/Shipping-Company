#include "UI.h"
#include<fstream>
#include<iostream>
#include"Time.h"
#include"PreparationEvent.h"
#include"CancelEvent.h"
#include"PromoteEvent.h"

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

void UI::Simulate(Company& C)
{
	int hour = 0;
	int day = 0;
	int DeliveryPeriod = 0;
	LoadFile(C);
	Event* CurrentEvent = nullptr;
	while (CurrentEvent || !C.AllIsDelivered())
	{
		while ( CurrentEvent && CurrentEvent->GetEventTime().day == day && CurrentEvent->GetEventTime().hour == hour)
		{
			CurrentEvent->Execute(C);
			C.DequeueEvent(CurrentEvent);
		}
		
		
		
		
		if (DeliveryPeriod % 5 == 0)
		{

		}
		
		
		
		hour++;
		if (hour == 24)
		{
			hour = 0;
			day++;
		}

	}
}