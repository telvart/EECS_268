/**
*	@file: main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.26.15
*	@brief: A driver that will sort arrays depending on the command line arguments passed in
*/
#include "Test.h"
#include "SortDriver.h"
#include "NumberFileDriver.h"
#include <iostream>

int main(int argc, char** argv)
{

	SortDriver Sorter;
	NumberFileDriver FileDriver;
	Test Tester(std::cout);
	std::string mode=argv[1];

	if (mode == "-create")
	{
		FileDriver.run(argc, argv);		
	}
	else if (mode == "-sort")
	{
		Sorter.run(argc, argv);
	}
	else if (mode == "-test")
	{
		Tester.runTests();
	}



	return 0;
}
