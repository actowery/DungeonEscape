/*********************************************************************
** Program name: 	main.cpp
** Author: 			Cihan Adrian Towery
** Date: 	    	11jun17
** Description: 	Main program used to create a dungeon crawler
**					for our final project
*********************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


#include "inputvalidation.hpp"
#include "creature.hpp"
#include "hero.hpp"
#include "game.hpp"


int main()
{
	srand(time(NULL));
	//call menu function
	int listchoice;
	do
	{

		//welcome after menu selection
		std::cout << "------------------------------------------------------------------------\n"
			<< "Hello and welcome to the dungeon crawler final project..\n"
			<< "This project will demonstrate the use of all OOP topics we have covered\n"
			<< "in cs162. Your goal is to escape imprisonment by a band of vampyres\n"
			<< "------------------------------------------------------------------------\n\n";
		std::cout
			<< " \nWelcome to the  menu. Please choose your action\n"
			<< " 1 - Play \n"
			<< " 2 - How to\n"
			<< " 3 - Exit\n";
		std::string choice;
		std::string tempstr = validintcheck(choice);
		int chc = std::stoi(tempstr, nullptr, 0);
		listchoice = chc;
		Game game1;
		switch (listchoice)
		{
		case 1:
		{
			game1.playgame();
			break;
		}
		case 2:
		{
			std::cout << "------------------------------------------------------------------------\n"
				<< "you have been captured by Vampyres, assumably brought to their lair to be used\n"
				<< "as blood cattle. You heard them leave for a raid under cover of night and you have\n"
				<< "one hour before they return. Each action takes 1 minute (move, fight, etc) but \n"
				<< "looking around or staying idle does not harm you\n"
				<< "Use menu options to navigate and take actions\n"

				<< "------------------------------------------------------------------------\n\n";
			break;
		}
		}
	} while (listchoice != 3);
}