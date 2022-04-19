#include "PreparationEvent.h"
#include "Company.h"

void PreparationEvent::Execute( Company& Comp) {
	if (CargoType == 'S')
	{
		//assumed that Prep time is event time
		SpecialCargo SC(EventTime, LoadTime, Distance, Cost, ID);
		Comp.enqueueWSC(SC);
	}
	else if (CargoType == 'V')
	{
		VIPCargo V(EventTime, LoadTime, Distance, Cost, ID);
		Comp.enqueueWVC(V);
	}
	else if (CargoType == 'N')
	{
		NormalCargo N(EventTime, LoadTime, Distance, Cost, ID);
		Comp.insertWNC(N);
	}
}


void PreparationEvent::GetParameters(char CT, Time ET, int D, Time LT, int C,int id)
{
	CargoType = CT;
	EventTime = ET;
	Distance = D;
	LoadTime = LT;
	Cost = C;
	ID = id;
}
