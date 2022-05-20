#pragma once

#include "Truck.h"
#include "PriorityQueue.h"

class SpecialTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
	static int CheckUpTime;
	//PriorityQueue <Cargo*> CargosQueue;
public:
	SpecialTruck();
	SpecialTruck(int DI);
	static int GetTruckCapacity();
	static void SetProperties(int TC, int S);
};

