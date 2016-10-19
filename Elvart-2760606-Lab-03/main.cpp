/**
*	@file: main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 9.23.15
*	@brief: Acts as a driver to interact with the DLL and perform tests using the test class 
*/

#include <iostream>
#include "DoubleLinkedList.h"
#include "Test.h"

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<< 	"10) Run Tests\n"
		<< 	"Your choice: ";
}

int main()
{
	Test Tester(std::cout);
	DoubleLinkedList<int> List;
	int choice, value1, value2;
	do
	{
		printMenu();
		std::cin>>choice;
		std::cout<<"\nYou chose "<<choice<<"\n";
		if (choice==1)
		{
			std::cout<<"\nGive a value to add to the front: ";
			std::cin>>value1;
			List.pushFront(value1);
			std::cout<<"\n"<<value1<<" was added to the front of the list";
		}
		else if (choice==2)
		{
			std::cout<<"\nGive a value to add to the back: ";
			std::cin>>value1;
			List.pushBack(value1);
			std::cout<<"\n"<<value1<<" was added to the back of the list";
		}
		else if (choice==3)
		{
			std::cout<<"\nGive a value to insert into the list: ";
			std::cin>>value1;
			std::cout<<"\nPick a value to insert behind: ";
			std::cin>>value2;
			try
			{
				List.insertBehind(value2,value1);
				std::cout<<"\n"<<value1<<" was inserted behind "<<value2;
			}
			catch (std::runtime_error& e)
			{
				std::cout<<e.what()<<"\n";
			}
		}
		else if (choice==4)
		{
			std::cout<<"\nGive a value to insert into the list: ";
			std::cin>>value1;
			std::cout<<"\nPick a value to insert ahead of: ";
			std::cin>>value2;
			try
			{
				List.insertAhead(value2,value1);
				std::cout<<"\n"<<value1<<" was inserted ahead of "<<value2;
			}
			catch(std::runtime_error& e)
			{
				std::cout<<e.what()<<"\n";
			}
		}
		else if (choice==5)
		{
			if(List.removeFront())
			{
				std::cout<<"\nThe front value was removed from the list";
			}
			else
			{
				std::cout<<"\nThe list is empty";
			}
		}
		else if (choice==6)
		{
			if (List.removeBack())
			{
				std::cout<<"\nThe back value was removed from the list";
			}
			else
			{
				std::cout<<"\nThe list is empty";
			}
		}
		else if(choice==7)
		{
			std::cout<<"\nGive a value to remove from the list";
			std::cin>>value1;
			if(List.remove(value1))
			{
				std::cout<<"\n"<<value1<<" was removed from the list";
			}
			else
			{
				std::cout<<"\n"<<value1<<" could not be removed from the list";
			}	
		}
		else if(choice==8)
		{
			List.printList();
		}
		else if (choice==9)
		{
			std::cout<<"\nProgram ending!...\n";
		}
		else if(choice==10)
		{
			Tester.runTests();
		}
		else
		{
			std::cout<<"\nInvalid input given, please try again";
		}

	}while(choice!=9);

	return 0;
}
