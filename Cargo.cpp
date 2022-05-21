#include "Cargo.h"


Cargo::Cargo(Time Prep, int Load, int DD, int C,int id,char CT)
{
	PreparationTime = Prep;
	LoadUnloadTime = Load;
	DeliveryDistance = DD;
	Cost = C;
	CargoType = CT;
	ID = id;
}

Cargo::Cargo()
{

}

char Cargo::GetCT()
{
	return CargoType;
}

int Cargo::GetID()
{
	return ID;
}

int Cargo::GetCost()
{
	return Cost;
}

Time Cargo::GetPreparationTime()
{
	return PreparationTime;
}

int Cargo::GetLoadUnloadTime()
{
	return LoadUnloadTime;
}

int Cargo::GetDeliveryDistance()
{
	return DeliveryDistance;
}

void Cargo::SetCargoType(char CT)
{
	CargoType = CT;
}

void Cargo::SetCost(int C)
{
	Cost = C;
}

int Cargo::CalcPrio()
{
	return (1000 / DeliveryDistance);
}
