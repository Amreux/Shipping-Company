#include "Company.h"

Company::Company()
{

}

void Company::enqueueWSC(Cargo SC)
{
	WaitingSpecialCargos.Enqueue(SC);
}

void Company::enqueueWVC(Cargo VC)
{
	WaitingVIPCargos.enqueue(VC);
}

void Company::insertWNC(Cargo NC)
{
	WaitingNormalCargos.insert(NC);
}


Cargo* Company::RemoveWNC(int id)
{
	return WaitingNormalCargos.Delete(id);
}