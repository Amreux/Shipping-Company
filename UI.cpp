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


void UI::Simulate(Company& C, int Type, string Input)
{
	int hour = 0;
	int day = 1;

	C.SetNormalLoadingTruck(nullptr);
	C.SetSpecialLoadingTruck(nullptr);
	C.SetVIPLoadingTruck(nullptr);

	int NLT = -1, SLT = -1, VLT = -1;

	C.LoadFile(Input);
	Event* CurrentEvent = nullptr;
	C.DequeueEvent(CurrentEvent);
	while (true)
	{
		//      AT each hour the Function asks if there is an Event that should be excuted in this time
		while (CurrentEvent && CurrentEvent->GetEventTime().day == day && CurrentEvent->GetEventTime().hour == hour)
		{
			CurrentEvent->Execute(C);
			if (!C.DequeueEvent(CurrentEvent))
				CurrentEvent = nullptr;
		}
		C.LoadCargos(NLT, SLT, VLT);




		hour++;
		if (hour == 24)
		{
			hour = 0;
			day++;
		}


		NLT--;
		SLT--;
		VLT--;

















		//C.AutoPromote(DeliveryPeriod);




	}
}
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


	//	//system("cls");
	//	//     Type1---> Interactive Mode 
	//	//     Type2---> Step-By-STep Mode
	//	if (Type == 1 || Type == 2)
	//	{
	//		cout << "Current Time(Day:Hour) :" << day << ":" << hour << endl;
	//		Display(C);
	//	}

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
	//	//	cout << "Current Time(Day:Hour) :" << day << ":" << hour << endl;
	//	//	Display(C);
	//	//	cout << endl;
	//	//	cout << "Simulation Finished" << endl;
	//	//}
	//	//else
	//	//{
	//	//	GenerateOutputFile(C);
	//	//	cout << "Silent Mode " << endl;
	//	//	cout << "Simulation Starts..." << endl;
	//	//	cout << "Simulation ends, Output file created" << endl;
	//	//}
	//}

//void UI::Display(Company& C)
//{
//	//cout << C.WaitingCount() << "  Waiting Cargos: [";
//	//C.PrintWNC();
//	//cout << "] (";
//	//C.PrintWSC();
//	//cout << ") {";
//	//C.PrintWVC();
//	//cout << "}" << endl;
//	//cout << "-------------------------------------------------------" << endl;
//
//	//cout << C.DeliveredCount() << "  Delivered Cargos: [";
//	//C.PrintDC();
//	//cout << "] " << endl;
//	///*C.PrintDSC();
//	//cout << ") {";
//	//C.PrintDVC();
//	//cout << "}" << endl;*/
//}