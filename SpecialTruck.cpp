#include "SpecialTruck.h"

int SpecialTruck::TruckCapacity = 0;
int SpecialTruck::Speed = 0;
int SpecialTruck::CheckUpDuration = 0;

SpecialTruck::SpecialTruck(int DI) :Truck(DI)
{

}

SpecialTruck::SpecialTruck()
{

}

void SpecialTruck::SetStaticMembers(int TC, int S, int CUD)
{
	TruckCapacity = TC;
	Speed = S;
	CheckUpDuration = CUD;
}

int SpecialTruck::GetTruckCapacity()
{
	return TruckCapacity;
}

int SpecialTruck::GetSpeed()
{
	return Speed;
}
int SpecialTruck::GetCheckUpDuration()
{
	return CheckUpDuration;
}

void SpecialTruck::SetEndOfCheckUp(Time EOCU)
{
	EndOfCheckUp = EOCU.hour + EOCU.day * 24 + CheckUpDuration;
}
