#include "Company.h"

Company::Company()
{

}

void Company::enqueueWSC(Cargo SC)
{
	WaitingSpecialCargos.Enqueue(SC);
}

void Company::enqueueWVC(Cargo VC)
{
	WaitingVIPCargos.enqueue(VC);
}

void Company::insertWNC(Cargo NC)
{
	WaitingNormalCargos.insert(NC);
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

void Company::EnqueueMSC(Cargo SC)
{
	MovingSpecialCargos.enqueue(SC);
}

void Company::EnqueueMNC(Cargo NC)
{
	MovingNormalCargos.enqueue(NC);
}

void Company::EnqueueMVC(Cargo VC)
{
	MovingVIPCargos.enqueue(VC);
}

void Company::EnqueueDSC(Cargo SC)
{
	DeliveredSpecialCargos.Enqueue(SC);
}

void Company::EnqueueDNC(Cargo NC)
{
	DeliveredNormalCargos.Enqueue(NC);
}

void Company::EnqueueDVC(Cargo VC)
{
	DeliveredVIPCargos.Enqueue(VC);
}

bool Company::DequeueEvent(Event*& E)
{
	return EventsList.Dequeue(E);
}

bool Company::DequeueWVC(Cargo& VC)
{
	return WaitingVIPCargos.Dequeue(VC);
}

bool Company::DequeueWSC(Cargo& SC)
{
	return WaitingSpecialCargos.Dequeue(SC);
}

bool Company::DequeueMSC(Cargo& SC)
{
	return MovingSpecialCargos.Dequeue(SC);
}

bool Company::DequeueMVC(Cargo& VC)
{
	return MovingVIPCargos.Dequeue(VC);
}

bool Company::DequeueMNC(Cargo& NC)
{
	return MovingNormalCargos.Dequeue(NC);
}

bool Company::RemoveFirstWNC(Cargo& NC)
{
	return WaitingNormalCargos.RemoveFirst(NC);
}

bool Company::AllIsDelivered()
{
	return (WaitingNormalCargos.IsEmpty() && WaitingSpecialCargos.IsEmpty() && WaitingVIPCargos.IsEmpty()) && (MovingNormalCargos.IsEmpty() && MovingSpecialCargos.IsEmpty() && MovingVIPCargos.IsEmpty());
}

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
void Company::PrintMNC()
{
	MovingNormalCargos.Print();
}
void Company::PrintMSC()
{
	MovingSpecialCargos.Print();
}
void Company::PrintMVC()
{
	MovingVIPCargos.Print();
}
void Company::PrintDNC()
{
	DeliveredNormalCargos.Print();
}
void Company::PrintDSC()
{
	DeliveredSpecialCargos.Print();
}
void Company::PrintDVC()
{
	DeliveredVIPCargos.Print();
}

int Company::WaitingCount()
{
	return WaitingNormalCargos.GetCount() + WaitingSpecialCargos.GetCount() + WaitingVIPCargos.GetCount();
}

int Company::MovingCount()
{
	return MovingNormalCargos.GetCount() + MovingSpecialCargos.GetCount() + MovingVIPCargos.GetCount();
}
int Company::DeliveredCount()
{
	return DeliveredNormalCargos.GetCount() + DeliveredSpecialCargos.GetCount() + DeliveredVIPCargos.GetCount();
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
	int No_Events;


	//reading the number of events from input file
	InputFile >> No_Events;


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
