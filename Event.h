#pragma once
#include "Time.h"
#include "Company.h"

class Event
{
	Time EventTime;
	Cargo* CargoInfo;
public:

	virtual void Execute(Cargo* C) = 0;

};

