/**
*	@file:SortDriver.h
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.26.15
*	@brief: Acts as a driver for the sorts class, this class calls other class methods to create arrays, files, and sort them.
*/

#ifndef SORTDRIVER_H
#define SORTDRIVER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Sorts.h"

class SortDriver
{
public:

	/*
	@pre argc and argv are valid
	@post the correct sort will be used according to the command line arguments
	@return none
	*/
	static void run(int argc, char** argv);
	/*
	@pre none
	@post the help menu will be printed to the console 
	@return none
	*/
	static void printHelpMenu();

private:
	/*
	@pre the input file was created by the NumberFileGenerator
	@post none
	@return true if the file is accessible, otherwise false
	*/
	static bool isFileAccessible(std::string fileName);
	/*
	@pre none
	@post none
	@return true if the sort parameter matches one of the known ones from the help menu
	*/
	static bool isSortValid(std::string sortParameter);
	/*
	@pre none
	@post none
	@return true if the inputFileName exists and the sort parameter is vlaid, otherwse false
	*/
	static bool areParametersValid(std::string sortName, std::string inputFileName);
	/*
	@pre the inputFile was created by NumFileGenerator
	@post the first line of the file is read in, containing the size of the array in the file
	@return the count from the inputFile that was read in
	*/
	static int getFileCount(std::ifstream& inputFile);\
	/*
	@pre the inputFile exists, the size was read in
	@post an array will be created using the numbers from the inputFile
	@return a pointer to the array that was created
	*/
	static int* createArray(std::ifstream& inputFile, int size);
	/*
	@pre original and copy have the same size
	@post all values from the original will be copied into the copy
	@return none
	*/
	static void copyArray(int original[], int copy[], int size);

};

#endif
