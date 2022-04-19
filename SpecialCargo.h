#pragma once

#include "Cargo.h"
#include <iostream>
using namespace std;

class SpecialCargo:public Cargo
{

public:
	SpecialCargo(Time Prep, Time Load, int DD, int C);
	SpecialCargo();
};

