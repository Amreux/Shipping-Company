#include "PreparationEvent.h"
#include "Company.h"

void PreparationEvent::Execute( Company& Comp) {
	if (CargoType == 'S')
	{
		//assumed that Prep time is event time
		SpecialCargo SC(EventTime, LoadTime, Distance, Cost);
		Comp.enqueueWSC(SC);
	}
}


void PreparationEvent::GetParameters(char CT, Time ET, int D, Time LT, int C)
{
	CargoType = CT;
	EventTime = ET;
	Distance = D;
	LoadTime = LT;
	Cost = C;
}
