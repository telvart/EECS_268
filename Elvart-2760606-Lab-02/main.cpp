/**
*	@file: main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.14
*	@brief: A driver for the user to interact with the LinkedList class
*/
#include <iostream>
#include "LinkedList.h"
#include "Test.h"

void printMenu()
{
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Exit\n"
			<< "8) Run tests\n"
			<< "Enter your choice: ";
}

int main()
{	
	int choice;
	int value;
	LinkedList List;
	Test Tester(std::cout);	
	do
	{
		printMenu();
		std::cin>>choice;
		std::cout<<"\nYou chose: "<<choice;
		if (choice==1)
		{
			std::cout<<"\nInput a value to add:\n";
			std::cin>>value;
			std::cout<<"\nAdding "<<value<<" to the front of the list.";
			List.addFront(value);
		}
		else if (choice==2)
		{
			std::cout<<"\nInput a value to add:\n";
			std::cin>>value;
			std::cout<<"\nAdding "<<value<<" to the end of the list.";
			List.addBack(value);
		}
		else if (choice==3)
		{
			std::cout<<"\nAttempting to remove from the front of the list";
			if(List.removeFront())
			{
				std::cout<<"\nThe removal was successful";
			}
			else
			{
				std::cout<<"\nThere are no values to remove";
			}
		}
		else if (choice==4)
		{
			std::cout<<"\nAttempting removal from the end of the list";
			if (List.removeBack())
			{
				std::cout<<"\nThe removal was true";
			}
			else
			{
				std::cout<<"\nThere are no values to remove";
			}
		}
		else if (choice==5)
		{
			std::cout<<"\nPrinting the list:\n";
			List.printList();
		}
		else if (choice==6)
		{
			std::cout<<"\nEnter a value to search for:\n";
			std::cin>>value;
			std::cout<<"\nSearching for "<<value<<"...";
			if (List.search(value))
			{
				std::cout<<"\n"<<value<<" is in the list.";
			}
			else
			{
				std::cout<<"\n"<<value<<" is not in the list.";
			}
		}
		else if (choice==7)
		{
			std::cout<<"\nExiting...\n";
		}
		else if (choice==8)
		{
			Tester.runTests();
		}
		else
		{
			std::cout<<"\nInvalid input, please enter again";
		}
	}while(choice!=7);
	

	return 0;
}
