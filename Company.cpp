#include "Company.h"

Company::Company()
{

}

void Company::enqueueWSC(Cargo SC)
{
	WaitingSpecialCargos.Enqueue(SC);
}

void Company::enqueueWVC(Cargo VC)
{
	WaitingVIPCargos.enqueue(VC);
}

void Company::insertWNC(Cargo NC)
{
	WaitingNormalCargos.insert(NC);
}


Cargo* Company::RemoveWNC(int id)
{
	return WaitingNormalCargos.Delete(id);
}


void Company::AddEvent(Event* E)
{
	if (E)
		EventsList.Enqueue(E);
}

void Company::EnqueueMSC(Cargo SC)
{
	MovingSpecialCargos.Enqueue(SC);
}

void Company::EnqueueMNC(Cargo NC)
{
	MovingNormalCargos.Enqueue(NC);
}

void Company::EnqueueMVC(Cargo VC)
{
	MovingVIPCargos.Enqueue(VC);
}

void Company::EnqueueDSC(Cargo SC)
{
	DeliveredSpecialCargos.Enqueue(SC);
}

void Company::EnqueueDNC(Cargo NC)
{
	DeliveredNormalCargos.Enqueue(NC);
}

void Company::EnqueueDVC(Cargo VC)
{
	DeliveredVIPCargos.Enqueue(VC);
}

bool Company::DequeueEvent(Event*& E)
{
	return EventsList.Dequeue(E);
}

bool Company::DequeueWVC(Cargo& VC)
{
	return WaitingVIPCargos.Dequeue(VC);
}

bool Company::DequeueWSC(Cargo& SC)
{
	return WaitingSpecialCargos.Dequeue(SC);
}

bool Company::DequeueMSC(Cargo& SC)
{
	return MovingSpecialCargos.Dequeue(SC);
}

bool Company::DequeueMVC(Cargo& VC)
{
	return MovingVIPCargos.Dequeue(VC);
}

bool Company::DequeueMNC(Cargo& NC)
{
	return MovingNormalCargos.Dequeue(NC);
}

bool Company::AllIsDelivered()
{
	return (WaitingNormalCargos.IsEmpty() && WaitingSpecialCargos.IsEmpty() && WaitingVIPCargos.isempty()) && (MovingNormalCargos.IsEmpty() && MovingSpecialCargos.IsEmpty() && MovingVIPCargos.IsEmpty());
}

