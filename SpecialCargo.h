#pragma once

#include "Cargo.h"

class SpecialCargo:public Cargo
{

public:
	SpecialCargo(Time Prep, Time Load, int DD, int C);
};

