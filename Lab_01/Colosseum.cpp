/**
*	@file: Colosseum.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.2
*	Purpose: implementation of methods declared in the Colosseum.h file to emulate a pokemon game.
*/

#include "Colosseum.h"

Colosseum::Colosseum()
{
	d6=Dice(6);
	d20=Dice(20);
}

void Colosseum::userBuild(Pokemon& p)
{
	std::string name;
	int tempint;	
	std::cout<<"Please name your pokemon:";
	std::cin>> name;
	p.setName(name);
	std::cout<<"\nHow many hitpoints will the pokemon have? (1-50)";
	//the do while will loop until valid input is given for hp
	do
	{
		std::cin>> tempint;
		if (!(tempint>=1 && tempint<=50))
		{
			std::cout<<"\nThe HP must be between 1 and 50, please enter again. \n";
		}
		p.setHP(tempint);
	}while(!(tempint>=1 && tempint<=50));

	std::cout<<"\nSplit 50 points between your attack and defense levels."
		 <<"\nEnter your attack level(1-49)";
	//do while will continue until the user gives valid input for the attack level
	do
	{
		std::cin>> tempint;
		if (!(tempint>=1 && tempint<=49))
		{
			std::cout<<"\nThe attack level must be between 1 and 49, please try again.\n"; 
		}
		p.setAttackLevel(tempint);
	}while(!(tempint>=1 && tempint<=49));
	
	int defensemax=50-tempint;
	std::cout<<"\nEnter your defense level (1-"<<defensemax<<")";
	//do while will contnue until valid input is given for the defense level
	do
	{
		std::cin>>tempint;
		if (!(tempint >=1 && tempint<=defensemax))
		{
			std::cout<<"\nThe defense level must be between 1 and "<<defensemax<<".\n";
		}
		p.setDefenseLevel(tempint);
	}while(!(tempint>=1 && tempint<=defensemax));
}

bool Colosseum::attack(Pokemon& attacker, Pokemon& defender)
{
	int attackbonus=d20.roll();
	int defensebonus=d20.roll();
	std::cout<<"\n"<<attacker.getName()<<" is attacking "<<defender.getName()
		 <<"\n"<<attacker.getName()<<" rolls an attack bonus of "<<attackbonus
		 <<"\n"<<defender.getName()<<" rolls a defense bonus of "<<defensebonus;
	if (attacker.getAttackLevel()+attackbonus > defender.getDefenseLevel()+defensebonus)
	{
		int attack1=d6.roll();
		int attack2=d6.roll();
		int attack3=d6.roll();
		int damage=attack1+attack2+attack3;
		std::cout<<"\nThe attack hits, dealing 3 D-6 damage!"
			 <<"\nThe rolls are "<<attack1<<", "<<attack2<<", and "<<attack3<<", totalling "<<damage<<" damage!";
	defender.reduceHP(damage);
	}
	else
	{
		std::cout<<"\nThe attack missed!";
	}
	if (defender.getHP()==0)
	{
		std::cout<<"\n"<<defender.getName()<<" has been defeated!";
		return true;
	}
	else
	{
		std::cout<<"\n"<<defender.getName()<<" has "<<defender.getHP()<<" hit points left.";
		return false;
	}
}

void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
	Dice d2=Dice(2);
	int round=1;
	std::cout<< "\nPlayer 1 will roll a D2 to decide who goes first";
	int order=d2.roll();
	if (order==1)
	{
		std::cout <<"\nPlayer 1 rolls a 1 and will go first\n";
		while (round<=9)
		{
			std::cout << "\nRound " << round << ":\n";
			if (attack(p1,p2)==true)
			{
				break;
			}
			else if (attack(p2,p1)==true)
			{
				break;
			}
			round++;
		}
		//round 10 has special rules and connot be included in the loop
		if (round==10)
		{
			std::cout<< "\nRound 10:";
			std::cout<<"\n";
			attack(p1,p2);
			attack(p2,p1);
			if (p1.getHP()>0 && p2.getHP() >0)
			{
				std::cout<< "\nBoth fighters are still standing, its a draw!";
			}
		}
	}
	else if (order==2)
	{
		std::cout <<"\nPlayer 1 rolls a 2 and will go second\n";
		while (round <=9)
		{
			std::cout << "\nRound " << round << ":\n";
			if (attack(p2,p1)==true)
			{
				break;
			}
			else if (attack(p1,p2)==true)
			{
				break;
			}
			round++;
		}
		if (round==10)
		{
			std::cout <<"\nRound 10:\n";
			attack(p2,p1);
			attack(p1,p2);
			if (p1.getHP()>0 && p2.getHP()>0)
			{
				std::cout <<"\nBoth fighters are still standing, its a draw!";
			}
		}
	}
}
