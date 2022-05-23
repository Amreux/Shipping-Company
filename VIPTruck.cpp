#include "VIPTruck.h"
#include "Queue.h"

int VIPTruck::TruckCapacity = 0;
int VIPTruck::Speed = 0;
int VIPTruck::CheckUpDuration = 0;
VIPTruck::VIPTruck()
{

}

VIPTruck::VIPTruck(int DI) :Truck(DI)
{

}


void VIPTruck::SetStaticMembers(int TC, int S, int CUD)
{
	TruckCapacity = TC;
	Speed = S;
	CheckUpDuration = CUD;
}

void VIPTruck::SetDeliveryInterval()
{
	int LoadHours = 0;
	int FurthestDis;
	Queue<Cargo*> CargosTemp;
	Cargo* CTemp;
	while (CargosQueue.Dequeue(CTemp))
	{
		LoadHours += CTemp->GetLoadUnloadTime();
		CargosTemp.Enqueue(CTemp);
	}
	if (CTemp)
		FurthestDis = CTemp->GetDeliveryDistance();
	while (CargosTemp.Dequeue(CTemp))
	{
		CargosQueue.enqueue(CTemp, CTemp->CalcPrio());
	}
	DeliveryInterval = 2.0 * FurthestDis / Speed + LoadHours;
}

int VIPTruck::GetTruckCapacity()
{
	return TruckCapacity;
}

int VIPTruck::GetSpeed()
{
	return Speed;
}
int VIPTruck::GetCheckUpDuration()
{
	return CheckUpDuration;
}

void VIPTruck::SetEndOfCheckUp(Time EOCU)
{
	EndOfCheckUp = EOCU.hour + EOCU.day * 24 + CheckUpDuration;
}

bool VIPTruck::IsFull()
{
	return (CargosQueue.GetCount() == TruckCapacity);
}
