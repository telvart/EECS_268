/**     @name: main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 10.7.15
*	@brief: A place to interact with the animalPen class
*/ 
#include <iostream>
#include "FarmAnimal.h"
#include "AnimalPen.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"

void goodbyeMessage(const FarmAnimal& animal)
{
	std::cout<<"\nUpon release the "<<animal.getName()<<" said "<<animal.getSound()<<".";
}

void printMenu()
{
	std::cout<<"\nSelect an animal to add to the pen: " 
		 <<"\n1.) Cow (produces milk)"
		 <<"\n2.) Chicken (cannot lay eggs) "
		 <<"\n3.) Cyber Chicken (seems dangerous, but lays eggs) "
		 <<"\n--------------------------------------------------\n";
		
}

int main()
{
	AnimalPen pen;
	int choice;
	double tempint;
	char goagain;

	do
	{
		printMenu();
		std::cin>>choice;
		std::cout<<"\nYour choice: "<<choice;

		if (choice==1)
		{
			Cow* cow= new Cow();
			std::cout<<"\nHow many gallons of milk did this cow produce? ";
			std::cin>>tempint;
			cow->setMilkProduced(tempint);

			pen.push(cow);
		}

		else if (choice==2)
		{
			Chicken* chicken=new Chicken();
			std::cout<<"\nAdd an eggless chicken to the pen? whatever you say man ";

			pen.push(chicken);
		}

		else if (choice==3)
		{
			CyberChicken* cyberchicken=new CyberChicken();
			std::cout<<"\nHow many eggs did this cyber chicken produce? ";
			std::cin>>tempint;
			cyberchicken->setCyberEggs(tempint);
	
			pen.push(cyberchicken);
		}

		std::cout<<"\nDone adding animals? (y/n)";
		std::cin>>goagain;

	}while(goagain!='y');

	double totaleggs=0;
	double totalmilk=0;
	std::cout<<"\nReleasing all animals!";
	std::cout<<"\n-------------------------";
	
	while (!pen.isPenEmpty())
	{
		FarmAnimal* tempptr=pen.peekAtNextAnimal();
		if (tempptr->getName()=="Cow")
		{
			Cow* cow=static_cast<Cow*>(tempptr);
			std::cout<<"\nThis cow Produced "<<cow->getMilkProduced()<<" gallons of milk";
			goodbyeMessage(*(cow));
			totalmilk+=cow->getMilkProduced();
			pen.releaseAnimal();
		}
		else if (tempptr->getName()=="Chicken")
		{
			Chicken* chicken=static_cast<Chicken*>(tempptr);
			std::cout<<"\nChicken unable to lay eggs, maybe cybernetic implants will help?";
			goodbyeMessage(*(chicken));
			pen.releaseAnimal();
		}
		else if (tempptr->getName()=="Cyber Chicken")
		{
			CyberChicken* cyberchicken=static_cast<CyberChicken*>(tempptr);
			std::cout<<"\nThis cyber chicken laid "<<cyberchicken->getCyberEggs()<<" cyber eggs, this is bad";
			goodbyeMessage(*(cyberchicken));
			totaleggs+=cyberchicken->getCyberEggs();
			pen.releaseAnimal();
		}

	}
	
	std::cout<<"\nYour farm produced "<<totalmilk<<" gallons of milk, and "<<totaleggs<<" eggs.";
	return 0;

}



