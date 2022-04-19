#pragma once

#include "Event.h"

class PromoteEvent:public Event
{
	int ID;
	int ExtraCost;
public:
	bool Execute(Company& C);
	void SetParameters(int id, int EC);
};

