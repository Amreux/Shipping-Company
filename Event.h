#pragma once
#include "Time.h"
#include "SpecialCargo.h"
#include "NormalCargo.h"
#include "VIPCargo.h"

class Company;

class Event
{
	Time EventTime;
	Cargo* CargoInfo;
public:
	Event();
	virtual bool Execute(Company &Comp) = 0;

};

