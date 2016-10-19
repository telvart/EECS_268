/**
*	@file:SortDriver.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:10.26.15
*	@brief: Implementation of methods declared in SortDriver.h
*/

#include "SortDriver.h"



void SortDriver::run(int argc, char** argv)
{
	Sorts<int> Sorter;
	std::string mode=argv[2];
	std::string inputname=argv[3];
	std::string outputname=argv[4];
	double time;

	if (areParametersValid(mode,inputname))
	{
		std::ifstream inputFile(inputname);
		std::ofstream outputFile(outputname);
		std::cout<<"\nCalculating sort timing information...";
		int* array;
		int* array2;
		int size=getFileCount(inputFile);
		array=createArray(inputFile,size);

		if (mode=="-bubble")
		{
			time=Sorter.sortTimer(Sorter.bubbleSort,array,size);
			outputFile<<"\nbubble "<< size <<" "<< time;
		}
		else if (mode=="-selection")
		{
			time=Sorter.sortTimer(Sorter.selectionSort,array,size);
			outputFile<<"\nselection "<<size<< " "<<time;
		}
		else if (mode=="-insertion")
		{
			time =Sorter.sortTimer(Sorter.insertionSort,array,size);
			outputFile<<"\ninsertion "<<size<<" "<<time;
		}
		else if (mode=="-quick")
		{
			time=Sorter.sortTimer(Sorter.quickSort,array,size);
			outputFile<<"\nquick "<<size<<" "<<time;
		}
		else if (mode=="-quick3")
		{
			time=Sorter.sortTimer(Sorter.quickSortWithMedian,array,size);
			outputFile<<"\nquick3 "<<size<<" "<<time;
		}
		else if(mode=="-merge")
		{
			time=Sorter.sortTimer(Sorter.mergeSort,array,size);
			outputFile<<"\nmerge "<<size<<" "<<time;
		}
		else if(mode=="-all")
		{
			array2=new int[size];

			copyArray(array,array2,size);
			time=Sorter.sortTimer(Sorter.bubbleSort,array2,size);
			outputFile<<"\nbubble "<< size<<" "<<time;
			copyArray(array,array2,size);
			time=Sorter.sortTimer(Sorter.selectionSort,array2,size);
			outputFile<<"\nselection "<<size<< " "<<time;
			copyArray(array,array2,size);
			time =Sorter.sortTimer(Sorter.insertionSort,array2,size);
			outputFile<<"\ninsertion "<<size<<" "<<time;
			copyArray(array,array2,size);
			time=Sorter.sortTimer(Sorter.quickSort,array2,size);
			outputFile<<"\nquick "<<size<<" "<<time;
			copyArray(array,array2,size);
			time=Sorter.sortTimer(Sorter.quickSortWithMedian,array2,size);
			outputFile<<"\nquick3 "<<size<<" "<<time;
			copyArray(array,array2,size);
			time=Sorter.sortTimer(Sorter.mergeSort,array2,size);
			outputFile<<"\nmerge "<<size<<" "<<time;
			delete[] array2;
		}

		std::cout<<"\nCalculations finished. Results stored in "<<outputname;
		outputFile.close();
		delete[] array;
	}
	else
	{
		printHelpMenu();
	}

}

void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
		<< "./prog -sort -bubble inputFile outputFile\n"
		<< "./prog -sort -selection inputFile outputFile\n"
		<< "./prog -sort -insertion inputFile outputFile\n"
		<< "./prog -sort -quick inputFile outputFile\n"
		<< "./prog -sort -quick3 inputFile outputFile\n"
		<< "./prog -sort -merge inputFile outputFile\n"
		<< "./prog -sort -all inputFile outputFile\n"
		<< "Option explainations:\n"
		<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
		<< "\t-selection to time selection sort and store all timing results in outputFile\n"
		<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
		<< "\t-quick to time quick sort and store all timing results in outputFile\n"
		<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
		<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
		<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
		<< "\tinputFile must be file created by a NumberFileGenerator\n"
		<< "\toutputFile must be to a valid path. It will hold the timing results\n";
}

bool SortDriver::isFileAccessible(std::string fileName)
{
	std::ifstream ifile(fileName);
	if (ifile)
	{
		return true;
	}
	return false;
}

bool SortDriver::isSortValid(std::string sortParameter)
{
	if (sortParameter=="-bubble")
	{
		return true;
	}
	else if (sortParameter=="-selection")
	{
		return true;
	}
	else if (sortParameter=="-insertion")
	{
		return true;
	}
	else if (sortParameter=="-quick")
	{
		return true;
	}
	else if (sortParameter=="-quick3")
	{
		return true;
	}
	else if (sortParameter=="-merge")
	{
		return true;
	}
	else if (sortParameter=="-all")
	{
		return true;
	}
	return false;
}

bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
	if (isFileAccessible(inputFileName) && isSortValid(sortName))
	{
		return true;
	}
	return false;
}

int SortDriver::getFileCount(std::ifstream& inputFile)
{
	int temp;
	if(inputFile)
	{
		inputFile>> temp;
		return temp;
	}
	return 0;
}

int* SortDriver::createArray(std::ifstream& inputFile, int size)
{
	int* array=new int[size];
	int temp;
	inputFile>>temp;
	if (temp==size)
	{
		for (int i=0; i<size; i++)
		{
			inputFile >> array[i];
		}
	}
	return array;
}

void SortDriver::copyArray(int original[], int copy[], int size)
{
	for (int i=0; i<size; i++)
	{
		copy[i]=original[i];
	}
}
















