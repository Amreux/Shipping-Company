#include "CancelEvent.h"
#include "Company.h"
#include <iostream>
using namespace std;

bool CancelEvent::Execute(Company& Comp)
{
	//removing the cargo from waiting normal by ID list if found

	Cargo* CargoToBeDeleted = Comp.RemoveWNC(ID);

	//checking whether it was found or not

	if (CargoToBeDeleted)
	{

		//deallocating the cargo
		delete CargoToBeDeleted;
		return true;
	}
	return false;
}

void CancelEvent::SetParameters(int id)
{
	ID = id;
}