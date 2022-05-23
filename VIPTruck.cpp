#include "VIPTruck.h"


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
