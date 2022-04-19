#include<iostream>
#include "Company.h"
#include "PreparationEvent.h"


using namespace std;

int main()
{
	Company C;
	PreparationEvent E1;
	E1.GetParameters('S', Time(1, 2), 111111, Time(1, 2), 4);
	E1.Execute(C);
	E1.GetParameters('S', Time(1, 2), 222222, Time(1, 2), 4);
	E1.Execute(C); 
	E1.GetParameters('S', Time(1, 2), 333333, Time(1, 2), 4);
	E1.Execute(C); 
	E1.GetParameters('S', Time(1, 2), 444444, Time(1, 2), 4);
	E1.Execute(C);
}