#pragma once
#include "Event.h"
#include "Queue.h"
#include "SpecialCargo.h"

class Company
{
	Queue<Event*> EventsList;
	Queue<SpecialCargo> WaitingSpecialCargos;

};

