#include "Company.h"

Company::Company()
{

}

void Company::enqueueWSC(SpecialCargo SC)
{
	WaitingSpecialCargos.Enqueue(SC);
}

void Company::Dis() 
{
	WaitingSpecialCargos.display();
}