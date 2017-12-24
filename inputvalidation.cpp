/*********************************************************************
** Program name: 	inputvalidation.cpp
** Author: 			Cihan Adrian Towery
** Date: 			09Apr17 (updated 24Apr17)
** Description: 	group of input reusable validation parameters
**			        for my projects in cs162 and beyond
*********************************************************************/


//inclusions
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include "inputvalidation.hpp"

using std::string;
using std::cout;
using std::cin;


string validintcheck(string str)
{
	bool isValid = false;
	do
	{
		cout << "Enter your choice:\t";
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}

		cin >> str;
		//check for validity and loop until true
		isValid = ((!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit)));
		int chc = stoi(str, nullptr, 0);
		if (chc == 0)
		{
			cout << "Can not be zero\n";
			isValid = false;
		}

		if (isValid)
		{
			
			
			break;
		}

		else
		{
			cout << "Please give me a valid input as described...\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!isValid);

	return str;
}
//for yes/no confirmatons throughout many programs
char validcharcheck(char chr)
{
	bool isValid = false;
	do
	{
		cout << "Enter your choice:\t";
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}

		cin >> chr;
		//check for validity and loop until true
		isValid = chr == 'Y' || chr == 'N';

		if (isValid)
		{

			break;
		}

		else
		{
			cout << "Please give me a valid input as described...\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!isValid);

	return chr;
}

