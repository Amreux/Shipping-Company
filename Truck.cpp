#include "Truck.h"
int Truck::J = 0;

Truck::Truck(int DI)
{
	DeliveryInterval = DI;
	TotalJourneys = 0;
	EndOfCheckUp = 0;
	TruckActiveTime = 0;
}

Truck::Truck()
{
	DeliveryInterval = 0;
	TotalJourneys = 0;
	EndOfCheckUp = 0;
	TruckActiveTime = 0;
}

void Truck::LoadCargo(Cargo* C)
{
	int Prio = C->CalcPrio();
	CargosQueue.enqueue(C,Prio);
}

void Truck::SetMovingTime(Time T)
{
	MovingTime = T;
}

Time Truck::GetMovingTime()
{
	return MovingTime;
}

bool Truck::PeekCargosQueue(Cargo*& C)
{
	return CargosQueue.Peek(C);
}

bool Truck::DequeueCargo(Cargo*& C)
{
	return CargosQueue.Dequeue(C);
}

int Truck::GetDeliveryInterval()
{
	return DeliveryInterval;
}

int Truck::CalcPrio()
{
	int MTHours = MovingTime.hour + MovingTime.day * 24;
	int Prio = MTHours + DeliveryInterval;
	return 10000 / Prio;
}

void Truck::SetTotalJourneys(int TJ)
{
	TotalJourneys = TJ;
}

int Truck::GetTotalJourneys()
{
	return TotalJourneys;
}

void Truck::SetJ(int j)
{
	J = j;
}

int Truck::GetJ()
{
	return J;
}

bool Truck::IsEmpty()
{
	return CargosQueue.IsEmpty();
}

int Truck::GetEndOfCheckUp()
{
	return EndOfCheckUp;
}

