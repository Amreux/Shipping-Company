#pragma once

#include "Truck.h"
#include "PriorityQueue.h"

class NormalTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
	static int CheckUpTime;
	//PriorityQueue <Cargo*> CargosQueue;
public:
	NormalTruck();
	NormalTruck(int DI);
	static int GetTruckCapacity();
	//static void NormalTruck(int TC, int S);
};

