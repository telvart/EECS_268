/**     @name: main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:9.31.15
*	@brief: Acts as a driver to interact with the stack class
*/ 

#include "Test.h"
#include "StackInterface.h"
#include "Stack.h"
#include <iostream>

void printMenu()
{
	std::cout 	<< "\n\nSelect an action:\n"
			<< "1) Add to stack\n"
			<< "2) See what is at the top of stack\n"
			<< "3) Print all stack\n"
			<< "4) Pop stack\n"
			<< "5) Quit\n"
 			<< "6) Run Tests\n"
			<< "Enter choice: ";
}

int main()
{
	Test Tester(std::cout);
	StackInterface<int>* myStack=new Stack<int>();
	int choice, value;

	do
	{
		printMenu();
		std::cin>>choice;
		std::cout<<"\nYou chose "<<choice<<"\n";
		if (choice==1)
		{
			std::cout<<"\nEnter a value to add to the stack: ";
			std::cin>>value;
			myStack->push(value);
			std::cout<<"\n"<<value<<" was added to the stack sucessfully";
		}
		else if (choice==2)
		{
			try
			{
				std::cout<<"\n"<<myStack->peek()<<" is at the top of the stack";
			}
			catch(PreconditionViolationException& e)
			{
				std::cout<<"\n"<<e.what();
			}
		}
		else if (choice==3)
		{
			myStack->print();
		}
		else if (choice==4)
		{
			try
			{
				myStack->pop();
				std::cout<<"\nThe top value was removed from the list";
			}
			catch(PreconditionViolationException& e)
			{
				std::cout<<"\n"<<e.what();
			}
		}
		else if(choice==5)
		{
			std::cout<<"\nProgram ending...\n\n";
		}
		else if (choice==6)
		{
			Tester.runTests();
		}
		else
		{
			std::cout<<"\nInvalid input, please try again";
		}
	}while(choice!=5);

	delete myStack;
	return 0;
}

