#pragma once
#include "Cargo.h"
#include "PriorityQueue.h"

class Truck
{
protected:
	int DeliveryInterval;
	PriorityQueue <Cargo*> CargosQueue;
	Time MovingTime;
	int TotalJourneys;
	static int J;
	int EndOfCheckUp;
	bool EmergencyFlag;
	int TID;
	static int TruckCount;
	int TruckActiveTime;
	int TDC;
	int ReturningHours;
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
	virtual bool IsFull() = 0;
	void SetEFlag(bool F);
	bool GetEFlag();
	int GetTID();
	void PrintTruckCargos();
	void PrintID();
	int GetCargoCount();
	void SetCWT();
	int GetActiveTime();
	void SetTDC(int tdc);
	int GetTDC();
	virtual void SetReturnH(int h);
	virtual int GetReturnH();
};