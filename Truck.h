#pragma once
#include "Cargo.h"
#include "PriorityQueue.h"

class Truck 
{
protected:
	int DeliveryInterval;
	char TruckType;
	PriorityQueue <Cargo*> CargosQueue;
public:
	Truck(int DI);
	Truck();
	void LoadCargo(Cargo* C);
};