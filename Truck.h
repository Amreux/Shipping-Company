#pragma once
#include "Cargo.h"
#include "PriorityQueue.h"

class Truck 
{
protected:
	int DeliveryInterval;
	char TruckType;  // zbala
	PriorityQueue <Cargo*> CargosQueue;
	Time MovingTime;
	int TotalJourneys;
	static int J;
	int EndOfCheckUp;
public:
	Truck(int DI);
	Truck();
	void LoadCargo(Cargo* C); 
	void SetMovingTime(Time T);
	Time GetMovingTime();
	bool PeekCargosQueue(Cargo*& C);
	bool DequeueCargo(Cargo*& C);
	virtual int GetSpeed() = 0;
	virtual void SetDeliveryInterval() = 0;
	int GetDeliveryInterval();
	int CalcPrio();
	void SetTotalJourneys(int TJ);
	int GetTotalJourneys();
	static void SetJ(int j);
	static int GetJ();
	bool IsEmpty();
	virtual void SetEndOfCheckUp(Time EOCU) = 0;
	int GetEndOfCheckUp();
	//int CalcDI();
	//virtual void DeliverCargos(Time Current) = 0;
	virtual bool IsFull() = 0;
	

};