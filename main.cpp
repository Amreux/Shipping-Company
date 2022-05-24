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
	Interface.Simulate(C, 1, "Input.txt");
	//int Type;
	//    Type1---> Interactive Mode 
	//    Type2---> Step-By-STep Mode
	//cin >> Type;

	//cin.get();
	/*Interface.Simulate(C, Type,"");*/

	//NormalTruck NT1(20);
	//NT1.SetJ(1);

	//Time T1(1, 2);
	//Time T25(2, 0);

	//Time T3(3, 0);
	//Time T4(4, 0);
	//Time T5(5, 0);


	//NT1.SetStaticMembers(1, 111, 2);
	//
	//Cargo C1(T1,1,111,11,1,'N');
	//Cargo C2(T1, 1, 111, 22, 2, 'N');

	///*Cargo C2();
	//Cargo C3;*/
	//NT1.LoadCargo(&C1);
	//NT1.LoadCargo(&C2);
	//C.enmoving(&NT1);
	//C.DeliverCargos(T25);
	////C.MoveToAvail();
	////NT1.SetTotalJourneys(2);

	//C.MoveToCheckUp(T25);

	//NT1.SetTotalJourneys(1);
	//C.DeliverCargos(T3);
	//C.MoveToCheckUp(T3);
	//C.MoveCheckUpToAvail(T4);
	//C.MoveCheckUpToAvail(T5);
	
}