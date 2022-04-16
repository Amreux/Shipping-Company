#pragma once

struct Time {
	int hour;
	int day;
};

class Truck
{
	Time PreparationTime;
	Time LoadUnloadTime;
	char CargoType;
	int DeliveryDistance;
	int Cost;
};