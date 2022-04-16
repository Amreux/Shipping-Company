#include "Cargo.h"

Cargo::Cargo(Time Prep, Time Load, int DD, int C) 
{
	PreparationTime = Prep;
	LoadUnloadTime = Load;
	DeliveryDistance = DD;
	Cost = C;
}