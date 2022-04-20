#include "PromoteEvent.h"
#include "Company.h"


bool PromoteEvent::Execute(Company& Comp)
{
	Cargo* CargoToBePromoted = Comp.RemoveWNC(ID);

	if (CargoToBePromoted)
	{
		CargoToBePromoted->SetCargoType('V');

		CargoToBePromoted->SetCost(CargoToBePromoted->GetCost() + ExtraCost);
		Comp.enqueueWVC(*CargoToBePromoted);
		return true;
	}
	return false;
}

void PromoteEvent::SetParameters(int id, int EC)
{
	ID = id;
	ExtraCost = EC;
}