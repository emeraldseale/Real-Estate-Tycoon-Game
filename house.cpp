/*********************************************************************************************************************************************************** Program: house.cpp
** Author: Emerald Seale
** Date: 5/10/18
** Desription: Holds all function bodies for the House class
** Input: Strings and integers deciding house based information
** Output: User UI about house based information
*********************************************************************************************************************************************************/
#include <iostream>
#include <string>
#include "house.h"
#include "property.h"
#include <time.h>
#include <cstdlib>

using namespace std;

/************************************************************************************************************************************************************ Function: House
** Description: Default contructor for the House class
** Parameters: None
** Pre-Conditions: A House object must be declared
** Post-Conditions: A house object is created and its member variables are initialized
**********************************************************************************************************************************************************/
House::House():Property () {

  srand(time(NULL));
  numTenants = 1;
  propertyValue = 100000 + rand() % 800001;
  tenants = new Tenant [numTenants];
  tenants[0].income = 500 + rand() % 5001;
  tenants[0].agreeableness = 1 + rand() % 5;
  tenants[0].type = "Citizen";
  int numLocation = rand() % 5;
  if (numLocation == 0) {
    location = "SE";
  } else if (numLocation == 1) {
    location = "NE";
  } else if (numLocation == 2) {
    location = "Midwest";
  } else if (numLocation == 3) {
    location = "SW";
  } else {
    location = "NW";
  }
  mortgage = rand() % 5001;
}

/************************************************************************************************************************************************************ Function: House
** Description: Non-default constructor for the House class
** Parameters: All house member variables
** Pre-Conditions: A house object must be declared and passed in variables
** Post-Conditions: A house object is created and initialized with passed-in variables
**********************************************************************************************************************************************************/
House::House (int pv, string l, float m, float pt, int nt, Tenant* t) {

  propertyValue = pv;
  location = l;
  mortgage = m;
  propertyTax = pt;
  numTenants = nt;
  tenants = t;
  delete [] t;
}

/************************************************************************************************************************************************************ Function: ~House
** Description: Desctructor for the House class
** Parameters: None
** Pre-Conditions: A house object goes out of scope or the program ends
** Post-Conditions: The house object is destroyed and dynamic memory is cleared from the heap
**********************************************************************************************************************************************************/
House::~House () {

  delete [] tenants;
  tenants = NULL;
}

/*********************************************************************************************************************************************************** Function: operator=
** Description: Assignment operator overload for house class
** Parameters: House by constant reference
** Pre-Conditions: One house object is assigned to another
** Post-Conditions: Member variables are deep copied
*********************************************************************************************************************************************************/
const House& House::operator= (const House& copy) {

  Property::operator=(copy);
}

//GREATER THAN OP OVERLOAD:
//bool House::operator> (const House& other) {

	//Property::operator>(other);
//}

/*********************************************************************************************************************************************************** Function: House
** Description: Copy constructor for the house class
** Parameters: House by constant reference
** Pre-Conditions: A house is passed by value
** Post-Conditions: Member variables are deep copied
*********************************************************************************************************************************************************/
House::House (const House& copy):Property(copy) {}
