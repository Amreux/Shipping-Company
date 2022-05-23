#pragma once

#include "Truck.h"
#include "PriorityQueue.h"

class VIPTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
	static int CheckUpDuration;
public:
	VIPTruck();
	VIPTruck(int DI);
	static void SetStaticMembers(int TC, int S, int CUD);
	static int GetTruckCapacity();
	int GetSpeed();
	static int GetCheckUpDuration();
	void SetEndOfCheckUp(Time EOCU);
	bool IsFull()
};

