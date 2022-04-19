#include "Cargo.h"


Cargo::Cargo(Time Prep, Time Load, int DD, int C,char CT)
{
	PreparationTime = Prep;
	LoadUnloadTime = Load;
	DeliveryDistance = DD;
	Cost = C;
	CargoType = CT;
}

Cargo::Cargo()
{

}

char Cargo::GetCT()
{
	return CargoType;
}

