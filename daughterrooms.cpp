/*********************************************************************
** Program name: 	daughterrooms.cpp
** Author: 		    Cihan Adrian Towery
** Date: 		    11jun17
** Description: 	each room interacts differently and needs its own virtual
**					functions
*********************************************************************/


#include "daughterrooms.hpp"
#include "creature.hpp"
#include "vampyre.hpp"
#include "hero.hpp"
#include <iostream>
//northwest room
NW::NW()
{


	type = 3;
}

NW::~NW()
{
}

void NW::set_interact(int s)
{
	if (s < 3)
	{
		std::cout << "There is a guard out there and you can't figure out a\n"
			<< "way to open the door and runor fight the guard..\n"
			<< "Maybe you can pick the lock?\n";

	}
	else if (s = 3)
	{
		std::cout << "You combine the needle, bucket handle, and coin to pick the lock!!\n "
			<< "Great job, Macgyver!"
			<< "The vampyre is in the next room , but didn't notice you.\n"
			<< "He will definitely hear the door open.\n";
		interacted = true;

	}
}
//southwest room
SW::SW()
{
	type = 1;
}

SW::~SW()
{
}

void SW::set_interact(int s)
{
	
		std::cout << "In the haystack you woke up on you find a needle! \n";
		interacted = true;

}
SE::SE()
{
	type = 2;
}

SE::~SE()
{
}

void SE::set_interact(int s)
{
	if (s < 3)
	{
		std::cout << "You take apart the bucket and take the handle! \n";
		interacted = true;

	}
}
NE::NE()
{
	type = 4;
}

NE::~NE()
{
}

void NE::set_interact(int s)
{
	if (s < 3)
	{
		std::cout << "Something shiny catches your eye... It's a SILVER COIN!\n";
		interacted = true;
	}
}
Guard::Guard()
{
	type = 5;
}

Guard::~Guard()
{
}

void Guard::set_interact(int s)
{

	{
		std::cout << "Upon closer inspection the Guard is a... VAMPYRE!!!\n"
			<< "He is prepared for your assault. I hope you are too!\n"
			<< "because here he comes!!!";
		Creature *creature1 = new Hero;
		Creature *creature2 = new Vampyre;
		int winner = resolvecombat(creature1, creature2);
		switch (winner)
		{
		case 1:
		{
			interacted = true;
			std::cout << "\nYou shove the silver coin into his chest to ensure vistory!\n";
			break;
		}
		default:
		{
			std::cout << "\nYou didn't make it...At least you wont be alive to be blood cattle.";

		}
		}
		delete creature1, creature2;



	}
}

Wayout::Wayout()
{
	type = 6;
}

Wayout::~Wayout()
{
}

void Wayout::set_interact(int s)
{

	{
		std::cout << "You open the door and go out into the night.\n"
			<< "Congratulations, you survived...for now.\n";
		interacted = true;

	}
}

