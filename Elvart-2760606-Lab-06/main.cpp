/**
*	@file:main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 10.19.15
*	@brief: A driver to interact with different iterative sort algorithms
*/

#include "Sorts.h"
#include <iostream>
#include "Test.h"

void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "5) Run Tests using Test class\n"
			<< "Enter choice: ";
}

void printintArray(int* arr, int size)
{
	std::cout<<"\n[";
	for (int i=0; i<size; i++)
	{
		if (i==size-1)
		{
			std::cout<<arr[i];
		}
		else
		{
			std::cout<<arr[i]<<", ";
		}
	}
	std::cout<<"]\n";
}

int main()
{
	Sorts<int> Sorter;
	Test Tester(std::cout);
	double elapsedtime;
	int choice, size, min, max;
	char goagain='y';
	char tempchar;
	int* array;

	do
	{
		printMenu();
		std::cin>>choice;

		if (choice<5)
		{
			std::cout<<"\nEnter a size for the random array: ";
			std::cin>>size;
			std::cout<<"\nEnter a lower bound on the range of random numbers: ";
			std::cin>>min;
			std::cout<<"\nEnter an upper bound on the range of random numbers: ";
			std::cin>>max;

			array=Sorter.createTestArray(size,min,max);
			
			std::cout<<"\nDo you want to print the unsorted array? (y/n): ";
			std::cin>>tempchar;
			if (tempchar=='y')
			{
				std::cout<<"\nHere is the unsorted array: ";
				printintArray(array,size);
			}
			if (choice==1)
			{
				std::cout<<"\nSorting array with bubble sort...";
				elapsedtime=Sorter.sortTimer(Sorter.bubbleSort, array, size);
				
			}
			else if (choice==2)
			{
				std::cout<<"\nSorting array with insertion sort...";
				elapsedtime=Sorter.sortTimer(Sorter.insertionSort, array, size);
			}
			else if (choice==3)
			{
				std::cout<<"\nSorting array with selection sort...";
				elapsedtime=Sorter.sortTimer(Sorter.selectionSort, array, size);
			}
			else if (choice==4)
			{
				std::cout<<"\nSorting array with bogo sort (you've been warned!)";
				elapsedtime=Sorter.sortTimer(Sorter.bogoSort, array, size);
			}
			
			std::cout<<"\n\nDo you want to print the sorted array? (y/n)\n";
			std::cin>>tempchar;
			if(tempchar=='y')
			{
				std::cout<<"\nHere is the sorted array";
				printintArray(array,size);
			}
			
			std::cout<<"\n"<<size<<" numbers were sorted in "<<elapsedtime<< " seconds\n"
				 <<"\nDo you want to go again? (y/n)\n";
			std::cin>>goagain;
		}
		else if (choice==5)
		{
			Tester.runTests();
			std::cout<<"\nDo you want to go again? (y/n)";
			std::cin>>goagain;
		}
		else
		{
			std::cout<<"\nInvalid choice, please try again\n";
		}

	} while (goagain!='n');
	
	delete[] array;
	return 0;
}

