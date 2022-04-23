#pragma once
#include"Company.h"
class UI
{
public:
	void LoadFile(Company& C);
	void GenerateOutputFile(Company& C);
	void Simulate(Company& C,int Type);
	void Display(Company & C);
};

