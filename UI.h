#pragma once
#include"Company.h"
#include<string.h>
class UI
{
public:
	//     Function GenerateOutputFile that Generates the Output File
	void GenerateOutputFile(Company& C);

	//     Function Simulate that loads input file and excutes the Events and calls Function Display 
	void Simulate(Company& C,int Type, string Input);

	//     Function Display that Print The Cargos Lists data according to the desired format
	//void Display(Company & C);
};

