#include "CancelEvent.h"
#include "Company.h"
#include <iostream>
using namespace std;

bool CancelEvent::Execute(Company& Comp)
{
	Cargo* CargoToBeDeleted = Comp.RemoveWNC(ID);
	if (CargoToBeDeleted)
	{
		delete CargoToBeDeleted;
		return true;
	}
	return false;
}

void CancelEvent::SetParameters(int id)
{
	ID = id;
}