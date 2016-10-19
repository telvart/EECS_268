/**
*	@file: main.cpp
*	@author: Tim Elvart
*	KUID: 2760606
*	Email: telvart@ku.edu
*	@date: 2015.9.2
*	Purpose: acts as the driver for the pokemon and colosseum classes, makes the game work
*/


#include <iostream>
#include <string>
#include "Colosseum.h"
#include "Pokemon.h"


int main()
{
	std::string playagain;
	Colosseum colosseum;
	Pokemon p1;
	Pokemon p2;
	std::cout <<"\nWelcome to the Pokemon Game!\n";
	do
	{
		std::cout <<"\nPlayer 1, build your pokemon!\n";
		colosseum.userBuild(p1);
		std::cout <<"\n\nPlayer 2, build your pokemon!\n";
		colosseum.userBuild(p2);
		colosseum.play(p1,p2);
		std::cout <<"\nDo you want to play again? (y/n)";
		std::cin >> playagain;
	}while (playagain!="n");
	std::cout << "\nThanks for playing!\n";

}
