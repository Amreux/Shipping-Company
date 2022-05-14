#pragma once

#include "Truck.h"
#include "PriorityQueue.h"

class VIPTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
	static int CheckUpTime;
	PriorityQueue <Cargo*> CargosQueue;
public:
	VIPTruck();
	VIPTruck(int DI);
	//static void SetProperties(int TC, int S);
};

