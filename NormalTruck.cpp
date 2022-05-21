#include "Truck.h"
#include "NormalTruck.h"

int NormalTruck::TruckCapacity = 0;
int NormalTruck::Speed = 0;
int NormalTruck::CheckUpDuration = 0;
NormalTruck::NormalTruck()
{

}

NormalTruck::NormalTruck(int DI)
{
	DeliveryInterval = DI;
}


void NormalTruck::SetStaticMembers(int TC, int S, int CUD)
{
	TruckCapacity = TC;
	Speed = S;
	CheckUpDuration = CUD;
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
