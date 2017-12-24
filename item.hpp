/*********************************************************************
** Program name: 	item.hpp
** Author: 		    Cihan Adrian Towery
** Date: 		    04May17
** Description: 	hpp companion to the  item clkass for player inventory
*********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
class Item
{
public:
	Item(int);
	~Item();
	void get_itemname();


protected:
	std::string itemname;

};
#endif