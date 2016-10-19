/**
*	@file:NumberFileDriver.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.26.15
*	@brief:
*/

#include "NumberFileDriver.h"


void NumberFileDriver::run(int argc, char** argv)
{
	NumberFileGenerator FileGenerator;
	std::string mode=argv[2];
	std::string filename=argv[3];
	int amount=std::stoi(argv[4]);
	if (isValidOption(mode)==true)
	{
		if (mode=="-a")
		{
			FileGenerator.ascending(filename,amount);
		}
		else if (mode=="-d")
		{
			FileGenerator.descending(filename,amount);
		}
		else if (mode=="-s")
		{
			int value=std::stoi(argv[5]);
			FileGenerator.singleValue(filename,amount,value);
		}
		else if (mode=="-r")
		{
			int min=std::stoi(argv[5]);
			int max=std::stoi(argv[6]);
			FileGenerator.random(filename,amount,min,max);
		}

		std::cout<<"\n"<<amount<<" numbers stored in "<<filename<<"\n";
	}
	else
	{
		printHelpMenu();	
	}
}

void NumberFileDriver::printHelpMenu()
{
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";
}


bool NumberFileDriver::isValidOption(std::string option)
{
	if ((option=="-a") || (option=="-d") || (option=="-r") || (option=="-s"))
	{
		return true;
	}
	return false;
}










