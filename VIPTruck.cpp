#include "VIPTruck.h"


int VIPTruck::TruckCapacity = 0;
int VIPTruck::Speed = 0;

VIPTruck::VIPTruck()
{

}

VIPTruck::VIPTruck(int DI) :Truck(DI)
{

}


int VIPTruck::GetTruckCapacity()
{
	return TruckCapacity;
}