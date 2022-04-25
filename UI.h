#pragma once
#include"Company.h"
#include<string.h>
class UI
{
public:
	void GenerateOutputFile(Company& C);
	void Simulate(Company& C,int Type, string Input);
	void Display(Company & C);
};

