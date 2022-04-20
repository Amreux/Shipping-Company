#pragma once

#include "Truck.h"

class NormalTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
public:
	NormalTruck(int DI);
	static void NormalTruck(int TC, int S);
};

