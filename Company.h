#pragma once
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "SpecialCargo.h"
#include "VIPCargo.h"
#include "NormalCargo.h"

class Company
{
	Queue < Event* > EventsList;
	Queue<SpecialCargo> WaitingSpecialCargos;
	PriorityQueue<VIPCargo> WaitingVIPCargos;
	LinkedList<NormalCargo> WaitingNormalCargos;
	Queue<SpecialCargo> MovingSpecialCargos;
	Queue<NormalCargo> MovingNormalCargos;
	Queue<VIPCargo> MovingVIPCargos;
public:
	Company();
	void enqueueWSC(SpecialCargo SC);
	void enqueueWVC(VIPCargo VC);
	void insertWNC(NormalCargo NC);
};

