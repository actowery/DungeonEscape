/*********************************************************************
** Program name: 	item.hpp
** Author: 		    Cihan Adrian Towery
** Date: 		    11jun17
** Description: 	inventory item creation for final project
*********************************************************************/

#include "item.hpp"
#include <iostream>
Item::Item(int i)
{
	switch (i)
	{
	case 1:
	{
		itemname = "Needle";
		break;
	}
	case 2:
	{
		itemname = "Bucket Handle";
		break;
	}
	case 4:
	{
		itemname = "Silver Coin";
		break;
	}
	}


}

Item::~Item()
{
}

void Item::get_itemname()
{
	std::cout << itemname << std::endl;
}
