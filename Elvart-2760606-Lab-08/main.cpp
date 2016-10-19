/**
*	@file: main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date:11/4/15
*	@brief: A driver that will sort arrays depending on the command line arguments passed in
*/

#include "Test.h"
#include "BinarySearchTree.h"
#include <iostream>

int generateRandomInt()
{
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(1,10);
	int ran=distribution(generator);
	return ran;
}

void printMenu()
{
	std::cout<<"\nInput a selection"
		 <<"\n1) Add more values to the original tree"
		 <<"\n2) Copy the original tree"
		 <<"\n3) Delete the original tree (one time only)"
		 <<"\n4) Print original tree"
		 <<"\n5) Print copy"
		 <<"\n6) Search original tree"
		 <<"\n7) Search copy"
	  	 <<"\n8) Exit"
		 <<"\n9) Run Tests"
		 <<"\nYour Choice:";
}

int main(int argc, char** argv)
{
	BinarySearchTree<int>* BST=new BinarySearchTree<int>();
	BSTI<int>* BST2=nullptr;
	Test Tester;
	int choice=0;
	int tempint;
	bool originalexists=true;
	bool copyexists=false;
	if (argc>1)
	{
		int temp;
		int numnodes=std::stoi(argv[1]);
		std::default_random_engine generator(time(nullptr));
		std::uniform_int_distribution<int> distribution(-32000,32000);
		std::cout<<"\nArg Count: "<<argc;
		std::cout<<"\nNode Count: "<<numnodes<<"\n";
		std::cout<<"\nFilling original tree with "<<numnodes<<" values";
		for (int i=0; i<numnodes; i++)
		{	
			temp=distribution(generator);
			std::cout<<"\nAdding "<<temp<<" to the original tree";
			BST->add(temp);
		}
		std::cout<<"\n";

	}

	do
	{
		printMenu();
		std::cin>>choice;
		std::cout<<"\nYou chose: "<<choice;
		
		if (choice==1)
		{
			if (originalexists==true)
			{
				std::cout<<"\nInput a value to add to the original: ";
				std::cin>>tempint;
				std::cout<<"\nAdding "<<tempint<<" to the original tree\n";
				BST->add(tempint);
			}
			else
			{
				std::cout<<"\nThis tree doesn't exist, no values can be added\n";
			}
		}
		else if (choice==2)
		{
			std::cout<<"\nCreating a copy of the original tree";
			//if (!(BST->isEmpty()))
			//{
				//BST2=new BinarySearchTree<int>(*(BST));
				BST2=BST->clone();
				copyexists=true;
				std::cout<<"\nCopy created, you may now interact with it\n";
			//}
			//else
			//{
			//	std::cout<<"\nThe origianl tree was empty and didnt exist\n";
			//}
			
			
		
			
		}
		else if(choice==3)
		{
			delete BST;
			originalexists=false;
			std::cout<<"\nOriginal tree deleted\n";
		}
		else if(choice==4)
		{
			
			if (originalexists==true)
			{
				std::cout<<"\nPrint order options: "
					 <<"\n0 - Pre-order"
					 <<"\n1 - In-order"
					 <<"\n2 - Post-order"
					 <<"\nChoice: ";
				std::cin>>tempint;
				if (tempint==0)
				{
					BST->printTree(PRE_ORDER);
				}
				if (tempint==1)
				{
					BST->printTree(IN_ORDER);
				}
				else if(tempint==2)
				{
					BST->printTree(POST_ORDER);
				}
				std::cout<<"\n";
			}
			else
			{
				std::cout<<"\nThe tree doesn't exist, it cant be printed\n";
			}
		}
		else if(choice==5)
		{
			if (copyexists==true)
			{
				std::cout<<"\nPrint order options: "
					 <<"\n0 - Pre-order"
					 <<"\n1 - In-order"
					 <<"\n2 - Post-order"
					 <<"\nChoice: ";
				std::cin>>tempint;
					if (tempint==0)
				{
					BST2->printTree(PRE_ORDER);
				}
				if (tempint==1)
				{
					BST2->printTree(IN_ORDER);
				}
				else if(tempint==2)
				{
					BST2->printTree(POST_ORDER);
				}
				std::cout<<"\n";
			}
			else
			{
				std::cout<<"\nThe tree doesn't exist, it cant be printed\n";
			}
		}
		else if(choice==6)
		{
			if (originalexists==true)
			{
				std::cout<<"\nEnter a value to search for in the original tree\n";
				std::cin>>tempint;
				if (BST->search(tempint))
				{
					std::cout<<"\n"<<tempint<<" is in the tree\n";
				}
				else
				{
					std::cout<<"\n"<<tempint<<" is not in the tree\n";
				}
			}
			else
			{
				std::cout<<"\nThe tree doesn't exist, it cannot be searched\n";
			}
		}
		else if(choice==7)
		{
			if (copyexists==true)
			{
				std::cout<<"\nEnter a value to search for in the copy\n";
				std::cin>>tempint;
				if (BST2->search(tempint))
				{
					std::cout<<"\n"<<tempint<<" is in the copied tree\n";
				}
				else
				{
					std::cout<<"\n"<<tempint<<" is not in the copied tree\n";
				}
			}
			else
			{
				std::cout<<"\nThe tree doesn't exist, it cannot be searched\n";
			}
		}
		else if (choice==8)
		{
			std::cout<<"\nProgram ending...\n\n";
		}
		else if (choice==9)
		{
			Tester.runTests();
		}
		else
		{
			std::cout<<"\nInvalid choice, please try again\n";
		}

	
	} while(choice!= 8);

	if (originalexists)
	{
		delete BST;
	}
	if (copyexists)
	{
		delete BST2;
	}

	return 0;

}













