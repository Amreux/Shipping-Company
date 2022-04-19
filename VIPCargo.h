#pragma once

#include "Cargo.h"

class VIPCargo:public Cargo
{
public:
	VIPCargo(Time Prep, Time Load, int DD, int id,int C);
	VIPCargo();
};

