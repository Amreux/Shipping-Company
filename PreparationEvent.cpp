#include "PreparationEvent.h"
#include "Company.h"

bool PreparationEvent::Execute( Company& Comp) {
	if (CargoType == 'S')
	{
		//assumed that Prep time is event time
		Cargo SC(EventTime, LoadTime, Distance, Cost, ID,'S');
		Comp.enqueueWSC(SC);
	}
	else if (CargoType == 'V')
	{
		Cargo V(EventTime, LoadTime, Distance, Cost, ID,'V');
		Comp.enqueueWVC(V);
	}
	else if (CargoType == 'N')
	{
		Cargo N(EventTime, LoadTime, Distance, Cost, ID,'N');
		Comp.insertWNC(N);
	}
	return true;
}


void PreparationEvent::SetParameters(char CT, Time ET, int D, int LT, int C,int id)
{
	CargoType = CT;
	EventTime = ET;
	Distance = D;
	LoadTime = LT;
	Cost = C;
	ID = id;
}
