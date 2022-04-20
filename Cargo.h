#pragma once
#include "Time.h"

class Cargo
{
	Time PreparationTime;
	int LoadUnloadTime;
	int DeliveryDistance;
	int Cost;
	char CargoType; 
	int ID;
public:
	Cargo(Time Prep, int Load, int DD, int C,int id,char CT);
	Cargo();
	char GetCT();
	int GetID();
	int GetCost();
	int GetDeliveryDistance();
	Time GetPreparationTime();
	int GetLoadUnloadTime();
	void SetCost(int C);
	void SetCargoType(char CT);
};

