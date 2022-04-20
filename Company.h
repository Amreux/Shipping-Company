#pragma once
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "Cargo.h"

class Company
{
	Queue < Event* > EventsList;
	Queue<Cargo> WaitingSpecialCargos;
	PriorityQueue<Cargo> WaitingVIPCargos;
	LinkedList<Cargo> WaitingNormalCargos;
	Queue<Cargo> MovingSpecialCargos;
	Queue<Cargo> MovingNormalCargos;
	Queue<Cargo> MovingVIPCargos;
public:
	Company();
	void enqueueWSC(Cargo SC);
	void enqueueWVC(Cargo VC);
	void insertWNC(Cargo NC);
	Cargo* RemoveWNC(int id);
	void AddEvent(Event* E);
};

