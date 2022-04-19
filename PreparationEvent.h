#pragma once

#include "Event.h"
#include "SpecialCargo.h"

class PreparationEvent:public Event
{
	char CargoType;
	Time EventTime;
	int Distance;
	Time LoadTime;
	int Cost;
	int ID;
public:
	bool Execute( Company& Comp);
	void SetParameters(char CT, Time ET, int D, Time LT, int C,int id);
};

