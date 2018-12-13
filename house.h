/*********************************************************************************************************************************************************** Program: house.h
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all member variables and functions for the House class
** Input: None
** Output: None
*********************************************************************************************************************************************************/
#ifndef HOUSE_H
#define HOUSE_H
#include <string>
#include "property.h"
#include "tenant.h"

using namespace std;

class House: public Property {

	public:
		House (); //default constructor
		House (int, string, float, float, int, Tenant*); //non-default constructor
		~House (); //destructor
		const House& operator= (const House&); // assignment operator overload
		//bool operator> (const House&);
		House (const House&); // copy constructor
};

#endif
