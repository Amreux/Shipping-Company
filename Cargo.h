#pragma once
#include "Time.h"

class Cargo
{
	Time PreparationTime;
	Time LoadUnloadTime;
	int DeliveryDistance;
	int Cost;
	char CargoType; 
	int ID;
public:
	Cargo(Time Prep, Time Load, int DD, int C,int id,char CT);
	Cargo();
	char GetCT();
};

