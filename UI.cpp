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
	//int hour = 0;
	//int day = 0;
	////    Variable that ensures that after each 5 Steps the functions dequeue a cargo from each waiting list and enqueue it
	////    in each delivered list 
	//int DeliveryPeriod = 0;
	//C.LoadFile("");
	//Event* CurrentEvent = nullptr;
	//C.DequeueEvent(CurrentEvent);
	//while (CurrentEvent || !C.AllIsDelivered())
	//{
	//	//      AT each hour the Function asks if there is an Event that should be excuted in this time
	//	while ( CurrentEvent && CurrentEvent->GetEventTime().day == day && CurrentEvent->GetEventTime().hour == hour)
	//	{
	//		CurrentEvent->Execute(C);
	//		if (!C.DequeueEvent(CurrentEvent))
	//			CurrentEvent = nullptr;
	//	}

	//	//      After each 5 Steps the functions dequeue a cargo from each waiting list and enqueue it
	//	//      in each delivered list
	//	/*if (DeliveryPeriod % 5 == 0)
	//	{
	//		Cargo Temp2;
	//		bool Test2;
	//		Test2 = C.DequeueWSC(Temp2);
	//		if (Test2)
	//			C.EnqueueDSC(Temp2);
	//		Test2 = C.DequeueWVC(Temp2);
	//		if (Test2)
	//			C.EnqueueDVC(Temp2);
	//		Test2 = C.RemoveFirstWNC(Temp2);
	//		if (Test2)
	//			C.EnqueueDNC(Temp2);
	//	}*/

	//	C.AutoPromote(DeliveryPeriod);
	//	/*Cargo Temp;
	//	while (C.RemoveFirstWNC(Temp))
	//	{
	//		int PrepHours;
	//		int AutoP = C.GetAutoPromotion();
	//		Time PrepTime = Temp.GetPreparationTime();
	//		PrepHours = PrepTime.day * 24 + PrepTime.hour;
	//		if (DeliveryPeriod - PrepHours >= AutoP)
	//		{
	//			Temp.SetCargoType('V');
	//			C.enqueueWVC(Temp);
	//		}
	//		else
	//		{
	//			C.insertFirstWNC(Temp);
	//			break;
	//		}
	//	}*/

	//	
	//	system("cls");
	//	//     Type1---> Interactive Mode 
	//	//     Type2---> Step-By-STep Mode
	//	if (Type == 1 || Type == 2)
	//	{
	//		cout << "Current Time(Day:Hour) :" << day << ":" << hour << endl;
	//		Display(C);
	//	}

	//	DeliveryPeriod++;
	//	hour++;
	//	if (hour == 24)
	//	{
	//		hour = 0;
	//		day++;
	//	}

	//	//       In Interactive Mode :Console waits for an Input from the User  
	//	if (Type == 1)
	//		cin.get();

	//	//       In Step-By-STep Mode Mode :Function waits a minute then it clears the console screen  
	//	if (Type == 2)
	//		Sleep(1000);
	//}

	//system("cls");
	//if (Type == 1 || Type == 2)
	//{
	//	cout << "Current Time(Day:Hour) :" << day << ":" << hour << endl;
	//	Display(C);
	//	cout << endl;
	//	cout << "Simulation Finished" << endl;
	//}
	//else
	//{
	//	GenerateOutputFile(C);
	//	cout << "Silent Mode " << endl;
	//	cout << "Simulation Starts..." << endl;
	//	cout << "Simulation ends, Output file created" << endl;
	//}
}

void UI::Display(Company& C)
{
	//cout << C.WaitingCount() << "  Waiting Cargos: [";
	//C.PrintWNC();
	//cout << "] (";
	//C.PrintWSC();
	//cout << ") {";
	//C.PrintWVC();
	//cout << "}" << endl;
	//cout << "-------------------------------------------------------" << endl;

	//cout << C.DeliveredCount() << "  Delivered Cargos: [";
	//C.PrintDC();
	//cout << "] " << endl;
	///*C.PrintDSC();
	//cout << ") {";
	//C.PrintDVC();
	//cout << "}" << endl;*/
}