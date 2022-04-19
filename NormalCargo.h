#pragma once

#include "Cargo.h"

class NormalCargo:public Cargo
{
public:
	NormalCargo(Time Prep, Time Load, int DD, int C, char CT);
	void f();
};

