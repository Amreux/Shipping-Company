#pragma once

struct Time {
	int hour;
	int day;
};

class Event
{
	Time EventTime;
public:

	virtual void Execute() = 0;
};

