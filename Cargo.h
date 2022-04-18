#pragma once
#include "Time.h"

class Cargo
{
	Time PreparationTime;
	Time LoadUnloadTime;
	int DeliveryDistance;
	int Cost;
	char CargoType;

public:
	Cargo(Time Prep, Time Load, int DD, int C,char CT);
	char GetCT();
};

