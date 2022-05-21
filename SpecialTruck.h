#pragma once

#include "Truck.h"
#include "PriorityQueue.h"

class SpecialTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
	static int CheckUpDuration;
public:
	SpecialTruck();
	SpecialTruck(int DI);
	static void SetStaticMembers(int TC, int S, int CUD);
	static int GetTruckCapacity();
	static int GetSpeed();
	static int GetCheckUpDuration();
	void SetEndOfCheckUp(Time EOCU);

};

