#include "Truck.h"

Truck::Truck(int DI)
{
	DeliveryInterval = DI;
}

Truck::Truck()
{
	DeliveryInterval = 0;
}

void Truck::LoadCargo(Cargo* C)
{
	CargosQueue.enqueue(C);
}