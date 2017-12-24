/*********************************************************************
** Program name: 	creature.hpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	room class used to create individual rooms for interaction
*********************************************************************/

#include "room.hpp"
#include <string>
#include <iostream>

Room::Room()
{
	west = NULL;
	east = NULL;
	north = NULL;
	south = NULL;
}
//deconstruct
Room::~Room()
{
}
int Room::get_type()
{
	return type;
}
void Room::set_interact(int s)
{
	interacted = true;
}
bool Room::get_interact()
{
	return interacted;
}
void Room::displayroommessage()
{
	std::cout << "You are currently in ";
	switch (type)
	{
	case 1:
	{
		std::cout << " the SW corner of the cell. This is where you woke up.\n";
		break;
	}
	case 2:
	{
		std::cout << " the SE corner of the cell. You see a dirty bucket..\n";
		break;
	}
	case 3:
	{
		std::cout << " the NW corner of the cell. A gate leading to the outside is here.\n";
		break;
	}
	case 4:
	{
		std::cout << " the NE corner of the cell. This corner is particularly dark.\n";
		break;
	}
	case 5:
	{
		std::cout << " the exit area. There is a guard here....\n";
		break;
	}
	}

}

