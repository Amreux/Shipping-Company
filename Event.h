#pragma once
#include "Time.h"
class Company;

class Event
{
	Time EventTime;
public:
	Event();
	virtual bool Execute(Company &Comp) = 0;
	Time GetEventTime();
	void SetEventTime(Time ET);
};

