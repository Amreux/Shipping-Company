#include "Truck.h"
#include "NormalTruck.h"

int NormalTruck::TruckCapacity = 0;
int NormalTruck::Speed = 0;

NormalTruck::NormalTruck()
{

}

NormalTruck::NormalTruck(int DI)
{
	DeliveryInterval = DI;
}

int NormalTruck::GetTruckCapacity()
{
	return TruckCapacity;
}

//void NormalTruck::SetProperties(int TC, int S)
//{
//	TruckCapacity = TC;
//	Speed = S;
//}