#pragma once
#include"Company.h"
#include<string.h>
class UI
{
public:
	//     Function GenerateOutputFile that Generates the Output File
	void GenerateOutputFile(Company& C);

	//     Function Simulate that loads input file and excutes the Events and calls Function Display 
	// 
	//     Function Display that Print The Cargos Lists data according to the desired format
	void Display(Company & C,int Type,Time CurrentTime);
	void DisplayT3(Company& C,int Type);
};

