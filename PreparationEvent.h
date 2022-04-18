#pragma once

#include "Event.h"
#include "Cargo.h"

class PreparationEvent:public Event
{
public:
	void Execute(Cargo* C);
};

