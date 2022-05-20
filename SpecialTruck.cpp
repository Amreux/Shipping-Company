#include "SpecialTruck.h"

int SpecialTruck::TruckCapacity = 0;
int SpecialTruck::Speed = 0;

SpecialTruck::SpecialTruck(int DI) :Truck(DI)
{

}

SpecialTruck::SpecialTruck()
{

}

int SpecialTruck::GetTruckCapacity()
{
	return TruckCapacity;
}

void SpecialTruck:: SetProperties(int TC, int S)
{
	TruckCapacity = TC;
	Speed = S;
}
