#include "PromoteEvent.h"
#include "Company.h"


bool PromoteEvent::Execute(Company& Comp)
{
	NormalCargo* CargoToBePromoted = Comp.RemoveWNC(ID);
	if (CargoToBePromoted)
	{
		VIPCargo V(CargoToBePromoted->GetPreparationTime(), CargoToBePromoted->GetLoadUnloadTime(), CargoToBePromoted->GetDeliveryDistance(), CargoToBePromoted->GetCost() + ExtraCost, CargoToBePromoted->GetID());
		Comp.enqueueWVC(V);
		return true;
	}
	return false;
}

void PromoteEvent::SetParameters(int id, int EC)
{
	ID = id;
	ExtraCost = EC;
}