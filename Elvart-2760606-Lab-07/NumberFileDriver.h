/**
*	@file: NumberFileDriver
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 10.26.15
*	@brief: 
*/

#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H
#include <string>
#include <iostream>
#include "NumberFileGenerator.h"

class NumberFileDriver
{
public:

	/*
	@pre argc and argv are valid
	@post if the args are valid, a file is created according to the appropriate command line arguments
	@return none
	*/
	static void run(int argc, char** argv);\
	/*
	@pre none
	@post the help menu will be printed to the console
	@return noen
	*/
	static void printHelpMenu();

private:
	/*
	@pre none
	@post prints a menu to help the user in numberfile generator
	@return noen
	*/
	static bool isValidOption(std::string option);
};

#endif
