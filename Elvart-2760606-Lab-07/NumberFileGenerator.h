/**
*	@file:NumberFileGenerator.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.26.15
*	@brief:A class that will create .txt files to be used in the creation of arrays
*/

#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H
#include <string>
#include <fstream>
#include <chrono>
#include <random>

class NumberFileGenerator
{

public:
	//For all files created with the following, the first line is the amount of numbers in the file

	/*
	@pre fileName is a valid path
	@post a file is created and filled with the amount of numbers in ascending order
	@return none
	*/
	static void ascending(std::string fileName, int amount);
	/*
	@pre fileName is a valid path
	@post a file is created and filled with the numbers in descending order
	@return none
	*/
	static void descending(std::string fileName, int amount);
	/*
	@pre fileName is a valid path
	@post a file is created and filled with random numbers within the range of min, max
	@return none
	*/
	static void random(std::string fileName, int amount, int min, int max);
	/*
	@pre fileName is a valid path
	@post a file is created and filled with a single value value, amount times
	@return none
	*/
	static void singleValue(std::string fileName, int amount, int value);
};

#endif

