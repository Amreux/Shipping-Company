#include "PromoteEvent.h"
#include "Company.h"


//bool PromoteEvent::Execute(Company& Comp)
//{
//	Node<NormalCargo>* CargoToBePromoted = Comp.RemoveWNC(ID);
//	if (CargoToBePromoted)
//	{
//		VIPCargo V;
//		(Cargo)V = (CargoToBePromoted);
//		V.SetCost(V.GetCost() + ExtraCost);
//		V.SetCargoType('V');
//		Comp.enqueueWVC(V);
//		return true;
//	}
//	return false;
//}

void PromoteEvent::SetParameters(int id, int EC)
{
	ID = id;
	ExtraCost = EC;
}