#include "Cargo.h"


Cargo::Cargo(Time Prep, Time Load, int DD, int C,int id,char CT)
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

