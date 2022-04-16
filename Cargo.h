#pragma once

struct Time {
	int hour;
	int day;
};

class Cargo
{
	Time PreparationTime;
	Time LoadUnloadTime;
	int DeliveryDistance;
	int Cost;

public:
	Cargo(Time Prep, Time Load, int DD, int C);
};

