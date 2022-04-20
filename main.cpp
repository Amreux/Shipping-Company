#include<iostream>
#include "Company.h"
#include "PreparationEvent.h"
#include "CancelEvent.h"
#include "PromoteEvent.h"

using namespace std;

int main()
{
	Company C;
	PreparationEvent PE1;
	CancelEvent CE1;
	PromoteEvent PE2;
	Time T1(1, 1);
	Cargo N1(T1, 10,1,2,3,'N');
	PE1.SetParameters('N', T1, 111, 1, 111, 1);
	PE1.Execute(C);
	PE1.SetParameters('N', T1, 222, 2, 222, 2);
	PE1.Execute(C);
	PE1.SetParameters('N', T1, 333, 3, 333, 3);
	PE1.Execute(C);
	PE1.SetParameters('V', T1, 444, 4, 444, 4);
	PE1.Execute(C);
	PE1.SetParameters('S', T1, 555, 10, 555, 5);
	PE1.Execute(C);
	PE2.SetParameters(2, 200);
	PE2.Execute(C);

}