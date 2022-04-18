#pragma once
#include "Time.h"
#include "Company.h"
#include "Cargo.h"
class Event
{
	Time EventTime;
	Cargo* CargoInfo;
public:
	Event();
	virtual void Execute(Cargo* C) = 0;

};

