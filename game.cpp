/*********************************************************************
** Program name: 	game.cpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	game class with all functions necerrary to play the game
*********************************************************************/

#include "game.hpp"
#include "creature.hpp"
#include "hero.hpp"
#include "room.hpp"
#include "daughterrooms.hpp"
#include "inputvalidation.hpp"
#include "item.hpp"
#include <iostream>
#include <queue>

Game::Game()
{
}

Game::~Game()
{
}

void Game::playgame()
{

	int action;
	int timeleft = 60;
	bool complete = false;
	std::cout << "You wake up in a dark cell. The last thing you remember is a tall,\n"
		<< "pale man attacking you in the night. You have 1 hour to escape before sun up.\n";

//create the rooms in  avector. the first is  ageneric room for later secrets!	
	std::vector<Item> items;
	std::vector<Room*> rooms;
	rooms.push_back(new Room);
	rooms.push_back(new SW);
	rooms.push_back(new SE);
	rooms.push_back(new NW);
	rooms.push_back(new NE);
	rooms.push_back(new Guard);
	rooms.push_back(new Wayout);

	Room *current = rooms[1];
	while (timeleft > 0 && !complete)
	{
		if (current->get_type() == 6)
		{
			complete = true;
		}
		current->displayroommessage();
		action = roommenu();
		std::cout << "\n*Minutes Left: " << timeleft << std::endl;
		switch (action)
		{
		case 1:
		{
			if (current->get_interact())
			{
				std::cout << "Nothing left in this room\n";
				timeleft--;
			}
			else
			{
				int numitems = items.size();
				current->set_interact(numitems);
				if (current->get_type() == 1 || current->get_type() == 2 || current->get_type() == 4)
				{
					Item temp(current->get_type());
					items.push_back(temp);
				}
				timeleft--;
			}
			break;
		}
		case 2:
		{
			int dec = 0;
			std::cout
				<< " \nChoose a Direction. Moving takes 1 minute:\n"
				<< " 1 - North \n"
				<< " 2 - East\n"
				<< " 3 - South\n"
				<< " 4 - West\n";
			std::cin.ignore();
			std::cin.clear();
			std::string choice;
			std::string tempstr = validintcheck(choice);
			int chc = std::stoi(tempstr, nullptr, 0);
			dec = chc;
			int typeroom = current->get_type();
			switch (dec)
			{
			case 1:
				if (typeroom == 1)
				{
					current = rooms[3];
				}
				if (typeroom == 2)
				{
					current = rooms[4];
				}
				if (typeroom == 3)
				{
					if (current->get_interact())
					{
						current = rooms[5];
					}
					else
					{
						std::cout << "the gate is locked!\n";
					}
				}
				if (typeroom == 4)
				{
					std::cout << "There is a wall there..";

				}
				if (typeroom == 5)
				{
					if (current->get_interact())
					{
						current = rooms[6];
					}
					else
					{
						std::cout << "You're not getting past Mr Vampy that easily!\n";
					}
				}
				if (typeroom == 6)
				{
					std::cout << "Escaped!\n";

				}
				break;
			case 2:
				if (typeroom == 1)
				{
					current = rooms[2];
				}
				if (typeroom == 2)
				{
					std::cout << "There is a wall there..";
				}
				if (typeroom == 3)
				{
					
					current = rooms[4];
					
				}
				if (typeroom == 4)
				{
					std::cout << "There is a wall there..";

				}
				if (typeroom == 5)
				{
					std::cout << "There is a wall there..";
				}
				if (typeroom == 6)
				{
					std::cout << "There is a wall there..";

				}
				break;
			case 3:
				if (typeroom == 1)
				{
					std::cout << "There is a wall there..";
				}
				if (typeroom == 2)
				{
					std::cout << "There is a wall there..";
				}
				if (typeroom == 3)
				{
					current = rooms[1];
				}
				if (typeroom == 4)
				{
					current = rooms[2];

				}
				if (typeroom == 5)
				{
					std::cout << "There is a wall there..";
				}
				if (typeroom == 6)
				{
					std::cout << "There is a wall there..";

				}
				break;
			case 4:
				if (typeroom == 1)
				{
					std::cout << "There is a wall there..";
				}
				if (typeroom == 2)
				{
					current = rooms[1];
				}
				if (typeroom == 3)
				{
					std::cout << "There is a wall there..";
				}
				if (typeroom == 4)
				{
					current = rooms[3];

				}
				if (typeroom == 5)
				{
					std::cout << "There is a wall there..";
				}
				if (typeroom == 6)
				{
					std::cout << "There is a wall there..";

				}
				break;
			}
			break;
		}
		case 3:
		{
			std::cout << "Items in inventory: " << items.size() << std::endl;
			for (int i = 0; i < items.size(); i++)
				{
				items[i].get_itemname();
				std::cout << std::endl;
				timeleft--;
				}
			}
			}
	}
	std::cout << "Game over due to ";
	if (complete && timeleft > 0)
	{
		std::cout << " escaping! Run!!!\n";
	}
	else
		std::cout << "time running out. Enjoy being Vampyre food.\n";
	
	delete current;
}

//room meenu
int roommenu()
{
	int dec = 0;
	std::cout
		<< " \nWelcome to the  menu. Please choose your action\n"
		<< " 1 - Interact with your environment \n"
		<< " 2 - Move locations\n"
		<< " 3 - Check inventory\n";
	std::cin.ignore();
	std::cin.clear();
	std::string choice;
	std::string tempstr = validintcheck(choice);
	int chc = std::stoi(tempstr, nullptr, 0);
	dec = chc;
	return dec;
}
