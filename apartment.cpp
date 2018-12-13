/*********************************************************************************************************************************************************** Program: apartment.cpp
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all function bodies for the Apartment class
** Input: Strings and integers deciding apartment complex information
** Output: User UI about apartment information
*********************************************************************************************************************************************************/
#include "apartment.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/************************************************************************************************************************************************************ Function: Apartment
** Description: Default contructor for the Apartment class
** Parameters: None
** Pre-Conditions: An Apartment object must be declared
** Post-Conditions: An Apartment object is created and its member variables are initialized
**********************************************************************************************************************************************************/
Apartment::Apartment():Property () {

  srand(time(NULL));
  numTenants = 1 + rand() % 10;
  numRooms = 1 + rand() % 10;
  propertyValue = 300000 + rand() % 600001;
  tenants = new Tenant [numTenants];
  for (int i = 0; i < numTenants; i++) {
    tenants[i].income = 500 + rand() % 5001;
    tenants[i].agreeableness = 1 + rand() % 5;
    tenants[i].type = "Citizen";
  }
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

/************************************************************************************************************************************************************ Function: Apartment
** Description: Non-default contructor for the Apartment class
** Parameters: All member variables for the Apartment class
** Pre-Conditions: An Apartment object must be declared and passed variables
** Post-Conditions: An Apartment  object is created and its member variables are initialized to the inputted variables
**********************************************************************************************************************************************************/
Apartment::Apartment (int pv, string l, float m, float pt, int nt, Tenant* t, int nr) {

  propertyValue = pv;
  location = l;
  mortgage = m;
  propertyTax = pt;
  numTenants = nt;
  tenants = t;
  numRooms = nr;
  delete [] t;
}

/************************************************************************************************************************************************************ Function: ~Apartment
** Description: Destructor for the Apartment class
** Parameters: None
** Pre-Conditions: An Apartment object must go out of scope
** Post-Conditions: An Apartment object is destroyed and dynamic memory is freed from the heap
**********************************************************************************************************************************************************/
Apartment::~Apartment () {

  delete [] tenants;
  tenants = NULL;
}


/************************************************************************************************************************************************************ Function: Apartment
** Description: Assignment operator overload for the Apartment class
** Parameters: Apartment object by constant reference
** Pre-Conditions: An apartment object must be copied to another using the assignment operator
** Post-Conditions: An apartment object is assigned the contents of another
**********************************************************************************************************************************************************/
const Apartment& Apartment::operator= (const Apartment& copy) {

  Property::operator=(copy);
  numRooms = copy.numRooms;
}

/************************************************************************************************************************************************************ Function: Apartment
** Description: Copy constructor for the Apartment class
** Parameters: Apartment object by constant reference
** Pre-Conditions: An apartment object must be passed by value
** Post-Conditions: An apartment object is assigned the contents of another
**********************************************************************************************************************************************************/
Apartment::Apartment (const Apartment& copy):Property(copy) {

  numRooms = copy.numRooms;
}


/************************************************************************************************************************************************************ Function: get_num_rooms and set_num_rooms
** Description: Accessor and mutator functions for the Apartment class
** Parameters: Must be out of Apartment scope
** Pre-Conditions: There is no access to the member variables
** Post-Conditions: We can access the member variables
**********************************************************************************************************************************************************/
int Apartment::get_num_rooms () { return numRooms; }
void Apartment::set_num_rooms (int nr) { numRooms = nr; }
