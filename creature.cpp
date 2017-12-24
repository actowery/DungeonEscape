/*********************************************************************
** Program name: 	creature.cpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	abstract creature parent class used to organize 
**					creature subclasses and resolve combat.
*********************************************************************/
#include "creature.hpp"
#include "vampyre.hpp"
#include "inputvalidation.hpp"
#include <iostream>
//default  wont be used as it is virtual
Creature::Creature()
{
}
//deconstruct
Creature::~Creature()
{
}
//returns and updates remaining strength
int Creature::getrstr(int s)
{
//dbg	std::cout << "default";
	str = str - s;
	return str;
}
int Creature::attack()
{
	return 0;
}
int Creature::defend()
{
	return 0;
}
//returns strength
int Creature::getstr()
{
	return str;
}
//adds player number to the creature name
void Creature::set_name()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, name);
	std::cout << "Creature name is now " << name;
}
//returns name after player number added
void Creature::get_name()
{
	std::cout << name;
}
//heals a small amount of hp from the surviving creature. althoug it is a small bonus, 
//it will make your max hp higher than what you started as a tradeoff (a "feature", lol)
void Creature::refresh()
{
	str = str + 5;
	std::cout << name << " heals 5 str and steps to the back of the line! str is now " << str;

}

//not a part of the class but works with it so i put it here
int resolvecombat(Creature *&c1, Creature *&c2)
{
	int winner;
	
	do
	{
		int goesfirst = rand() % 2;

		int c1damagedealt;
		int c2damagedealt;
		//c1 goes first
		if (goesfirst == 0)
		{

			c1->get_name();
			std::cout<< " goes first this round!\n";
			c1damagedealt = c1->attack() - c2->defend();
			c2damagedealt = c2->attack() - c1->defend();
			if (c1damagedealt <= 0)
			{
				c1->get_name();
				std::cout << " couldn't get through armor! Full block!\n";
				c1damagedealt = 0;
			}
			c1->get_name();
			std::cout << " hits for " << c1damagedealt;
			c2->getrstr(c1damagedealt);
			std::cout << " and " << c2->getstr() << " str remains\n";
			if (c2damagedealt <= 0)
			{
				c2->get_name();
				std::cout << " couldn't get through armor! Full block!\n";
				c2damagedealt = 0;
			}
			c2->get_name();
			std::cout << " hits for " << c2damagedealt;
			c1->getrstr(c2damagedealt);
			std::cout << " and " << c1->getstr() << " str remains\n";
		}
		else if (goesfirst == 1)
		{

			c2->get_name();
			std::cout << " goes first this round!\n";
			c1damagedealt = c1->attack() - c2->defend();
			c2damagedealt = c2->attack() - c1->defend();
			if (c2damagedealt <= 0)
			{
				c2->get_name();
				std::cout << " couldn't get through armor! Full block!\n";
				c2damagedealt = 0;
			}
			c2->get_name();
			std::cout << " hits for " << c2damagedealt;
			c1->getrstr(c2damagedealt);
			std::cout << " and " << c1->getstr() << " str remains\n";
			if (c1damagedealt <= 0)
			{
				c1->get_name();
				std::cout << " couldn't get through armor! Full block!\n";
				c1damagedealt = 0;
			}
			c1->get_name();
			std::cout << " hits for " << c1damagedealt;
			c2->getrstr(c1damagedealt);
//debug			std::cout << " and " << c2->getstr() << " str remains\n";
		}
	} while (c1->getstr() > 0 && c2->getstr() > 0);
	//see who lives
	if (c1->getstr() <= 0 && c2->getstr() > 0)
	{
		c1->get_name();
		std::cout << " is dead.";
		c2->get_name();
		std::cout << " wins!" << std::endl;
		winner = 2;
		c2->refresh();
	}
	else if (c2->getstr() <= 0 && c1->getstr() > 0)
	{
		c2->get_name();
		std::cout << " is dead.";
		c1->get_name();
		std::cout << " wins!" << std::endl;
		winner = 1;
		c1->refresh();
	}
	else if (c1->getstr() <= 0 && c2->getstr() <= 0)
	{
		std::cout << "The creatures have killed each other..." << std::endl;
		winner = 0;
	}
	return winner;

}

