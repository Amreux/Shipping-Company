#include "Truck.h"
#include "NormalTruck.h"
#include "Queue.h"

int NormalTruck::TruckCapacity = 0;
int NormalTruck::Speed = 0;
int NormalTruck::CheckUpDuration = 0;
NormalTruck::NormalTruck()
{

}

NormalTruck::NormalTruck(int DI)  //uidch
{
	DeliveryInterval = DI;
}


void NormalTruck::SetStaticMembers(int TC, int S, int CUD)
{
	TruckCapacity = TC;
	Speed = S;
	CheckUpDuration = CUD;
}

void NormalTruck::SetDeliveryInterval()
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

int NormalTruck::GetTruckCapacity()
{
	return TruckCapacity;
}

int NormalTruck::GetSpeed()
{
	return Speed;
}

int NormalTruck::GetCheckUpDuration()
{
	return CheckUpDuration;
}

void NormalTruck::SetEndOfCheckUp(Time EOCU)
{
	EndOfCheckUp = EOCU.hour + EOCU.day * 24 + CheckUpDuration;
}

bool NormalTruck::IsFull()
{
	return (CargosQueue.GetCount() == TruckCapacity);
}

