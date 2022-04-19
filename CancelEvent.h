#pragma once

#include "Event.h"

class CancelEvent:public Event
{
	int ID;
public:
	bool Execute(Company& Comp);
	void SetParameters(int id);

};

