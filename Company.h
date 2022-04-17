#pragma once
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "SpecialCargo.h"
#include "VIPCargo.h"
class Company
{
	Queue<Event*> EventsList;
	Queue<SpecialCargo> WaitingSpecialCargos;
	PriorityQueue<VIPCargo> WaitingVIPCargos;

};

