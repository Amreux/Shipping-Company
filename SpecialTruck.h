#pragma once

#include "Truck.h"

class SpecialTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
public:
	SpecialTruck(int DI);
	static void SetProperties(int TC, int S);
};

