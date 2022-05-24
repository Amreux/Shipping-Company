#include "Company.h"

Company::Company()
{

}

void Company::enqueueWSC(Cargo* SC)
{
	WaitingSpecialCargos.Enqueue(SC);
}

void Company::enqueueWVC(Cargo* VC, int Priority)
{
	WaitingVIPCargos.enqueue(VC, Priority);
}

void Company::insertWNC(Cargo* NC)
{
	WaitingNormalCargos.insert(NC);
}

void Company::insertFirstWNC(Cargo* NC)
{
	WaitingNormalCargos.InsertFirst(NC);
}

Cargo* Company::RemoveWNC(int id)
{
	return WaitingNormalCargos.Delete(id);
}


void Company::AddEvent(Event* E)
{
	if (E)
		EventsList.Enqueue(E);
}

//void Company::EnqueueMSC(Cargo* SC)
//{
//	MovingSpecialCargos.enqueue(SC);
//}
//
//void Company::EnqueueMNC(Cargo* NC)
//{
//	MovingNormalCargos.enqueue(NC);
//}
//
//void Company::EnqueueMVC(Cargo* VC)
//{
//	MovingVIPCargos.enqueue(VC);
//}

void Company::EnqueueDC(Cargo* SC)
{
	DeliveredCargos.Enqueue(SC);
}

void Company::EnqueueMT(Truck* MT) //////////
{
	MovingTrucks.enqueue(MT);
}


bool Company::DequeueEvent(Event*& E)
{
	return EventsList.Dequeue(E);
}

bool Company::DequeueWVC(Cargo*& VC)
{
	return WaitingVIPCargos.Dequeue(VC);
}

bool Company::DequeueWSC(Cargo*& SC)
{
	return WaitingSpecialCargos.Dequeue(SC);
}

void Company::SetNormalLoadingTruck(Truck* Nptr)
{
	NormalLoadingTruck = Nptr;
}
void Company::SetVIPLoadingTruck(Truck* Vptr)
{
	VIPLoadingTruck = Vptr;
}
void Company::SetSpecialLoadingTruck(Truck* Sptr)
{
	SpecialLoadingTruck = Sptr;
}
Truck* Company::GetNormalLoadingTruck()
{
	return NormalLoadingTruck;
}
Truck* Company::GetVIPLoadingTruck()
{
	return VIPLoadingTruck;
}
Truck* Company::GetSpecialLoadingTruck()
{
	return SpecialLoadingTruck;
}

//bool Company::DequeueMSC(Cargo*& SC)
//{
//	return MovingSpecialCargos.Dequeue(SC);
//}
//
//bool Company::DequeueMVC(Cargo*& VC)
//{
//	return MovingVIPCargos.Dequeue(VC);
//}
//
//bool Company::DequeueMNC(Cargo*& NC)
//{
//	return MovingNormalCargos.Dequeue(NC);
//}

bool Company::RemoveFirstWNC(Cargo*& NC)
{
	return WaitingNormalCargos.RemoveFirst(NC);
}

//bool Company::AllIsDelivered()
//{
//	return (WaitingNormalCargos.IsEmpty() && WaitingSpecialCargos.IsEmpty() && WaitingVIPCargos.IsEmpty()) && (MovingNormalCargos.IsEmpty() && MovingSpecialCargos.IsEmpty() && MovingVIPCargos.IsEmpty());
//}

void Company::PrintWNC()
{
	WaitingNormalCargos.Print();
}
void Company::PrintWSC()
{
	WaitingSpecialCargos.Print();
}
void Company::PrintWVC()
{
	WaitingVIPCargos.Print();
}
//void Company::PrintMNC()
//{
//	MovingNormalCargos.Print();
//}
//void Company::PrintMSC()
//{
//	MovingSpecialCargos.Print();
//}
//void Company::PrintMVC()
//{
//	MovingVIPCargos.Print();
//}
void Company::PrintDC()
{
	DeliveredCargos.Print();
}

int Company::WaitingNormalCount()
{
	return WaitingNormalCargos.GetCount();
}

int Company::WaitingSpecialCount()
{
	return WaitingSpecialCargos.GetCount();
}

int Company::WaitingVIPCount()
{
	return WaitingVIPCargos.GetCount();
}

//int Company::MovingCount()
//{
//	return MovingNormalCargos.GetCount() + MovingSpecialCargos.GetCount() + MovingVIPCargos.GetCount();
//}
int Company::DeliveredCount()
{
	return DeliveredCargos.GetCount() ;
}

void Company::LoadFile( string Input)
{

	//opening the input file to read from

	ifstream InputFile("Input.txt");


	//checking whether the file is opened/found 

	if (!InputFile.is_open())
	{
		cout << "Could not open the file..." << endl;
		return;
	}

	//opening the output file

	ofstream OutputFile("Output.txt");
	OutputFile << "Done";
	int NumN, NumS, NumVIP;
	int NSpeed, SpSpeed, VIPSpeed;
	int NCap, SCap, VIPCap;
	int j;
	int CN, CS, CV;
	int AP,No_Events;

	InputFile >> NumN >> NumS >> NumVIP;
	InputFile >> NSpeed >> SpSpeed >> VIPSpeed;
	InputFile >> NCap >> SCap >> VIPCap;
	InputFile >> j >> CN >> CS >> CV;
	Truck::SetJ(j);
	NormalTruck::SetStaticMembers(NCap, NSpeed, CN);
	SpecialTruck::SetStaticMembers(SCap, SpSpeed, CS);
	VIPTruck::SetStaticMembers(VIPCap, VIPSpeed, CV);

	for (int i = 0; i < NumN; i++)
	{
		NormalTruck* NT = new NormalTruck;
		EmptyNormalTrucks.Enqueue(NT);
	}

	for (int i = 0; i < NumS; i++)
	{
		SpecialTruck* ST = new SpecialTruck;
		EmptySpecialTrucks.Enqueue(ST);
	}
	
	for (int i = 0; i < NumVIP; i++)
	{
		VIPTruck* NVIP = new VIPTruck;
		EmptyVIPTrucks.Enqueue(NVIP);
	}

	//reading the number of events from input file

	InputFile >> AP >> MaxW >> No_Events;

	SetAutoPromotion(AP);

	//variables for diffrent events
	char EventType, CargoType;
	Time T;
	int ID, Distance, LoadTime, Cost, ExtraCost;


	for (int i = 0; i < No_Events; i++)
	{
		InputFile >> EventType;

		//switch case to check wich EVENT will be executed

		switch (EventType)
		{
		case 'R':
		{
			//allocating a new  event

			PreparationEvent* RE = new PreparationEvent;

			//reading event variables
			InputFile >> CargoType >> T.day;
			InputFile.ignore();
			InputFile >> T.hour >> ID >> Distance >> LoadTime >> Cost;
			RE->SetParameters(CargoType, T, Distance, LoadTime, Cost, ID);
			RE->SetEventTime(T);

			//adding the event to the Event queue
			AddEvent(RE);

			break;
		}
		case 'X':
		{

			//allocating a new event
			CancelEvent* CE = new CancelEvent;


			//reading event variables
			InputFile >> T.day;
			InputFile.ignore();
			InputFile >> T.hour >> ID;
			CE->SetParameters(ID);
			CE->SetEventTime(T);

			//adding the event to the Event queue
			AddEvent(CE);
			break;
		}
		case 'P':
		{
			//allocating a new event
			PromoteEvent* PE = new PromoteEvent;

			//reading event variables
			InputFile >> T.day;
			InputFile.ignore();
			InputFile >> T.hour >> ID >> ExtraCost;
			PE->SetParameters(ID, ExtraCost);
			PE->SetEventTime(T);

			//adding the event to the Event queue
			AddEvent(PE);
		}
		}
	}
}

int Company::GetAutoPromotion()
{
	return AutoPromotion;
}

void Company::SetAutoPromotion(int AP)
{
	AutoPromotion = AP;
}

void Company::AutoPromote(int time)
{
	Cargo* Temp;
	while (RemoveFirstWNC(Temp))
	{
		int PrepHours;
		int AutoP = GetAutoPromotion();
		Time PrepTime = Temp->GetPreparationTime();
		PrepHours = PrepTime.day * 24 + PrepTime.hour;
		if (time - PrepHours >= AutoP)
		{
			Temp->SetCargoType('V');
			enqueueWVC(Temp, Temp->CalcPrio());
		}
		else
		{
			insertFirstWNC(Temp);
			break;
		}
	}
}

void Company::LoadCargos(int& NLT, int& SLT, int& VLT)
{
	if (!VIPLoadingTruck)
	{
		if (!EmptyVIPTrucks.IsEmpty() && (WaitingVIPCount() >= VIPTruck::GetTruckCapacity()))
		{
			VIPTruck* VT;
			EmptyVIPTrucks.Dequeue(VT);
			VIPLoadingTruck = VT;
			Cargo* VC;
			WaitingVIPCargos.Peek(VC);
			VLT = VC->GetLoadUnloadTime();
		}

		else if (!EmptyNormalTrucks.IsEmpty() && (WaitingVIPCount() >= NormalTruck::GetTruckCapacity()))
		{
			NormalTruck* NT;
			EmptyNormalTrucks.Dequeue(NT);
			VIPLoadingTruck = NT;
			Cargo* VC;
			WaitingVIPCargos.Peek(VC);
			VLT = VC->GetLoadUnloadTime();
		}

		else if (!EmptySpecialTrucks.IsEmpty() && (WaitingVIPCount() >= SpecialTruck::GetTruckCapacity()))
		{
			SpecialTruck* ST;
			EmptySpecialTrucks.Dequeue(ST);
			VIPLoadingTruck = ST;
			Cargo* VC;
			WaitingVIPCargos.Peek(VC);
			VLT = VC->GetLoadUnloadTime();
		}
	}

	if (VLT == 0)
	{
		Cargo* VC;
		WaitingVIPCargos.Dequeue(VC);
		VIPLoadingTruck->LoadCargo(VC);
		if (VIPLoadingTruck->IsFull())
		{
			VIPLoadingTruck->SetDeliveryInterval();
			MovingTrucks.enqueue(VIPLoadingTruck, VIPLoadingTruck->CalcPrio());
			VLT = -1;
			VIPLoadingTruck = nullptr;
		}
		else if (WaitingVIPCargos.Peek(VC))
		{
			VLT = VC->GetLoadUnloadTime();
		}
	}

	// ------------------------------------------- //

	if (!SpecialLoadingTruck)
	{
		if (!EmptySpecialTrucks.IsEmpty() && (WaitingSpecialCount() >= SpecialTruck::GetTruckCapacity()))
		{
			SpecialTruck* ST;
			EmptySpecialTrucks.Dequeue(ST);
			SpecialLoadingTruck = ST;
			Cargo* SC;
			WaitingSpecialCargos.Peek(SC);
			SLT = SC->GetLoadUnloadTime();
		}
	}

	if (SLT == 0)
	{
		Cargo* SC;
		WaitingSpecialCargos.Dequeue(SC);
		SpecialLoadingTruck->LoadCargo(SC);
		if (SpecialLoadingTruck->IsFull())
		{
			SpecialLoadingTruck->SetDeliveryInterval();
			MovingTrucks.enqueue(SpecialLoadingTruck, SpecialLoadingTruck->CalcPrio());
			SLT = -1;
			SpecialLoadingTruck = nullptr;
		}
		else if (WaitingSpecialCargos.Peek(SC))    
		{
			SLT = SC->GetLoadUnloadTime();
		}
	}

	// -------------------------------------------------- //

	if (!NormalLoadingTruck)
	{
		if (!EmptyNormalTrucks.IsEmpty() && (WaitingNormalCount() >= NormalTruck::GetTruckCapacity()))
		{
			NormalTruck* NT;
			EmptyNormalTrucks.Dequeue(NT);
			NormalLoadingTruck = NT;
			Cargo* NC;
			WaitingNormalCargos.RemoveFirst(NC);
			NLT = NC->GetLoadUnloadTime();
			WaitingNormalCargos.InsertFirst(NC);
		}
		else if(!EmptyVIPTrucks.IsEmpty() && (WaitingNormalCount() >= VIPTruck::GetTruckCapacity()))
		{
			VIPTruck* VT;
			EmptyVIPTrucks.Dequeue(VT);
			NormalLoadingTruck = VT;
			Cargo* NC;
			WaitingNormalCargos.RemoveFirst(NC);
			NLT = NC->GetLoadUnloadTime();
			WaitingNormalCargos.InsertFirst(NC);
		}
	}
	
	if (NLT == 0)
	{
		Cargo* NC;
		WaitingNormalCargos.RemoveFirst(NC);
		NormalLoadingTruck->LoadCargo(NC);
		if (NormalLoadingTruck->IsFull())
		{
			NormalLoadingTruck->SetDeliveryInterval();
			MovingTrucks.enqueue(NormalLoadingTruck, NormalLoadingTruck->CalcPrio());
			NLT = -1;
			NormalLoadingTruck = nullptr;
		}
		else if (WaitingNormalCargos.RemoveFirst(NC))    
		{
			NLT = NC->GetLoadUnloadTime();
			WaitingNormalCargos.InsertFirst(NC);
		}
	}
}

void Company::DeliverCargos(Time Current)
{
	int count = MovingTrucks.GetCount();
	for (int i = 0; i < count; i++)
	{
		Truck* TempTruck;
		MovingTrucks.Dequeue(TempTruck);
		int CurrPrio = TempTruck->CalcPrio();
		Cargo* TempCargo ;
		TempTruck->PeekCargosQueue(TempCargo);
		Time MT = TempTruck->GetMovingTime();
		int MTHours = MT.hour + MT.day * 24;
		int CurrentHours = Current.hour + Current.day * 24;
		int CDT = MTHours + TempCargo->GetDeliveryDistance() / TempTruck->GetSpeed() + TempCargo->GetLoadUnloadTime();
		if (CurrentHours == CDT)
		{
			Cargo* TempCargo2;
			TempTruck->DequeueCargo(TempCargo2);
			DeliveredCargos.Enqueue(TempCargo2);
			Time NewMT;
			NewMT.day = (MTHours+ TempCargo->GetLoadUnloadTime()) / 24;
			NewMT.hour = (MTHours + TempCargo->GetLoadUnloadTime()) % 24;
			TempTruck->SetMovingTime(NewMT);
		}
		MovingTrucks.enqueue(TempTruck, CurrPrio);
	}
}

void Company::MoveToAvail()
{
	Truck* TempTruck;
	MovingTrucks.Peek(TempTruck);
	while (TempTruck && TempTruck->IsEmpty())
	{
		MovingTrucks.Dequeue(TempTruck);
		if (dynamic_cast<NormalTruck*>(TempTruck))
			EmptyNormalTrucks.Enqueue((NormalTruck*)TempTruck);
		if (dynamic_cast<SpecialTruck*>(TempTruck))
			EmptySpecialTrucks.Enqueue((SpecialTruck*)TempTruck);
		if (dynamic_cast<VIPTruck*>(TempTruck))
			EmptyVIPTrucks.Enqueue((VIPTruck*)TempTruck);
		MovingTrucks.Peek(TempTruck);
	}
}

void Company::MoveToCheckUp(Time Current) // checkup el awl fel sim
{
	Truck* TempTruck;
	MovingTrucks.Peek(TempTruck);
	while (TempTruck && TempTruck->IsEmpty())
	{ 
		MovingTrucks.Dequeue(TempTruck);
		if (TempTruck->GetTotalJourneys() % TempTruck->GetJ()==0)  ///////// tot in load
		{
			TempTruck->SetEndOfCheckUp(Current);
			if (dynamic_cast<NormalTruck*>(TempTruck))
				NormalCheckUpTrucks.Enqueue((NormalTruck*)TempTruck);
			if (dynamic_cast<SpecialTruck*>(TempTruck))
				SpecialCheckUpTrucks.Enqueue((SpecialTruck*)TempTruck);
			if (dynamic_cast<VIPTruck*>(TempTruck))
				VIPCheckUpTrucks.Enqueue((VIPTruck*)TempTruck);
		}
		MovingTrucks.Peek(TempTruck);
	}
}

void Company::MoveCheckUpToAvail(Time Current)
{
	NormalTruck* TempTruck1;
	int CurrentHours = Current.hour + Current.day * 24;
	NormalCheckUpTrucks.Peek(TempTruck1);
	while (TempTruck1 && (CurrentHours == TempTruck1->GetEndOfCheckUp()))
	{
		NormalCheckUpTrucks.Dequeue(TempTruck1);
		EmptyNormalTrucks.Enqueue(TempTruck1);
		NormalCheckUpTrucks.Peek(TempTruck1);
	}

	SpecialTruck* TempTruck2;
	SpecialCheckUpTrucks.Peek(TempTruck2);
	while (TempTruck2 && (CurrentHours == TempTruck2->GetEndOfCheckUp()))
	{
		SpecialCheckUpTrucks.Dequeue(TempTruck2);
		EmptySpecialTrucks.Enqueue(TempTruck2);
		SpecialCheckUpTrucks.Peek(TempTruck2);
	}

	VIPTruck* TempTruck3;
	VIPCheckUpTrucks.Peek(TempTruck3);
	while (TempTruck3 && (CurrentHours == TempTruck3->GetEndOfCheckUp()))
	{
		VIPCheckUpTrucks.Dequeue(TempTruck3);
		EmptyVIPTrucks.Enqueue(TempTruck3);
		VIPCheckUpTrucks.Peek(TempTruck3);
	}
}

void Company::HandleMaxW(int Day, int Hour)
{
	int CurrentHours = Day * 24 + Hour;
	Cargo* NormCargo;
	WaitingNormalCargos.RemoveFirst(NormCargo);
	Time NCPrepTime= NormCargo->GetPreparationTime();
	int PrepHours = NCPrepTime.day * 24 + NCPrepTime.hour;
	/*if (CurrentHours - PrepHours >= MaxW)
	{
		if (!EmptyNormalTrucks.IsEmpty())
		{

		}
	}*/

}
