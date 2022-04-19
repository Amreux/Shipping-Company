#include "Company.h"

Company::Company()
{

}

void Company::enqueueWSC(SpecialCargo SC)
{
	WaitingSpecialCargos.Enqueue(SC);
}

void Company::enqueueWVC(VIPCargo VC)
{
	WaitingVIPCargos.enqueue(VC);
}
