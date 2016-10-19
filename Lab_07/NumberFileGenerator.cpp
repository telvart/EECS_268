/**
*	@file: NumberFileGenerator.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.26.15
*	@brief:Implementation of methods declared in NumberFileGenerator.h
*/

#include "NumberFileGenerator.h"


void NumberFileGenerator::ascending(std::string fileName, int amount)
{
	std::ofstream myOutputFile(fileName);
	myOutputFile << amount;
	for (int i=1; i<=amount; i++)
	{	
		myOutputFile << "\n" << i;
	}
	myOutputFile.close();
}

void NumberFileGenerator::descending(std::string fileName, int amount)
{
	std::ofstream myOutputFile(fileName);
	myOutputFile <<amount;
	for (int i=amount; i>0; i--)
	{
		myOutputFile<<"\n"<<i;
	}
	myOutputFile.close();
}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max)
{
	int randint;
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min,max);
	std::ofstream myOutputFile(fileName);
	myOutputFile<<amount;
	for (int i=0; i<amount; i++)
	{
		randint=distribution(generator);
		myOutputFile <<"\n"<< randint;
	}
	myOutputFile.close();
}

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value)
{
	std::ofstream myOutputFile(fileName);
	myOutputFile<<amount;
	for (int i=0;i<amount;i++)
	{
		myOutputFile <<"\n"<<value;
	}
	myOutputFile.close();
}

















