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
	Queue<Cargo> DeliveredNormalCargos;
	Queue<Cargo> DeliveredVIPCargos;
	Queue<Cargo> DeliveredSpecialCargos;
public:
	Company();
	void enqueueWSC(Cargo SC);
	void enqueueWVC(Cargo VC);
	void insertWNC(Cargo NC);
	void AddEvent(Event* E);
	void EnqueueMSC(Cargo SC);
	void EnqueueMNC(Cargo NC);
	void EnqueueMVC(Cargo VC);
	void EnqueueDSC(Cargo SC);
	void EnqueueDNC(Cargo NC);
	void EnqueueDVC(Cargo VC);
	Cargo* RemoveWNC(int id);
	bool DequeueWVC(Cargo& VC);
	bool DequeueWSC(Cargo& SC);
	bool DequeueEvent(Event*& E);
	bool DequeueMVC(Cargo& VC);
	bool DequeueMSC(Cargo& SC);
	bool DequeueMNC(Cargo& NC);
	bool RemoveFirstWNC(Cargo& NC);
	void PrintWNC();
	void PrintWSC();
	void PrintWVC();
	void PrintMNC();
	void PrintMSC();
	void PrintMVC(); 
	void PrintDNC();
	void PrintDSC();
	void PrintDVC();
	int WaitingCount();
	int MovingCount();
	int DeliveredCount();
	bool AllIsDelivered();
};

