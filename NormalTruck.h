#pragma once

#include "Truck.h"
#include "PriorityQueue.h"

class NormalTruck:public Truck
{
	static int TruckCapacity;
	static int Speed;
	static int CheckUpDuration;
public:
	NormalTruck();
	NormalTruck(int DI);
	static void SetStaticMembers(int TC,int S,int CUD);
	void SetDeliveryInterval();
	static int GetTruckCapacity();
	int GetSpeed();
	static int GetCheckUpDuration();
	void SetEndOfCheckUp(Time EOCU);
	bool IsFull();
};

