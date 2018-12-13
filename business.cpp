/*********************************************************************************************************************************************************** Program: business.cpp
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all function bodies for the Business class
** Input: Strings and integers deciding business complex information
** Output: User UI to the screen about business complex information
*********************************************************************************************************************************************************/
#include "business.h"
#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

/************************************************************************************************************************************************************ Function: Business
** Description: Default contructor for the Business class
** Parameters: None
** Pre-Conditions: A Business object must be declared
** Post-Conditions: A Business object is created and its member variables are initialized
**********************************************************************************************************************************************************/
Business::Business():Property () {

  srand(time(NULL));
  numTenants = 1 + rand() % 5;
  numSpaces = 1 + rand() % 5;
  propertyValue = 400000 + rand() % 500001;
  tenants = new Tenant [numTenants];
  for (int i = 0; i < numTenants; i++) {
    tenants[i].income = 2000 + rand() % 8001;
    tenants[i].agreeableness = 1 + rand() % 5;
    tenants[i].type = "Business";
  }
  spaces = new string [numSpaces];
  for (int i = 0; i < numSpaces; i++) {
    int spaceNum = rand() % 3;
    if (spaceNum == 0) {
      spaces[i] = "Small";
    } else if (spaceNum == 1) {
      spaces[i] = "Medium";
    } else {
      spaces[i] = "Large";
    }
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

/************************************************************************************************************************************************************ Function: Business
** Description: Non-default contructor for the Business class
** Parameters: All member variables
** Pre-Conditions: A Business object must be declared and variables must be passed
** Post-Conditions: A Business object is created and its member variables are initialized to passed variables
**********************************************************************************************************************************************************/
Business::Business (int pv, string l, float m, float pt, int nt, Tenant* t, int ns, string* s) {

  propertyValue = pv;
  location = l;
  mortgage = m;
  propertyTax = pt;
  numTenants = nt;
  tenants = t;
  numSpaces = ns;
  spaces = s;
  delete [] t;
  delete [] s;
}

/************************************************************************************************************************************************************ Function: ~Business
** Description: Destructor for the Business class
** Parameters: None
** Pre-Conditions: A Business object must go out of scope
** Post-Conditions: A Business object is destroyed, it's dynamic memory is cleared from the heap
**********************************************************************************************************************************************************/
Business::~Business () {

  delete [] tenants;
  tenants = NULL;
  delete [] spaces;
  spaces = NULL;
}

/************************************************************************************************************************************************************ Function: Business
** Description: Business operator overload for the Apartment class
** Parameters: Business object by constant reference
** Pre-Conditions: A Business object must be copied to another using the assignment operator
** Post-Conditions: A Business object is assigned the contents of another
**********************************************************************************************************************************************************/
const Business& Business::operator= (const Business& copy) {

  Property::operator=(copy);
  numSpaces = copy.numSpaces;
  if (spaces != NULL) {
    delete [] spaces;
    spaces = NULL;
  }
  if (numSpaces == 0) {
    spaces = NULL;
  } else {
    spaces = new string [numSpaces];
    for (int i = 0; i < numSpaces; i++) {
      spaces[i] = copy.spaces[i];
    }
  }
}

/************************************************************************************************************************************************************ Function: Business
** Description: Copy constructor for the Business class
** Parameters: Business object by constant reference
** Pre-Conditions: A Business object must be passed by value
** Post-Conditions: A Business object is assigned the contents of another
**********************************************************************************************************************************************************/
Business::Business (const Business& copy):Property(copy) {

  numSpaces = copy.numSpaces;
  spaces = new string [numSpaces];
  for (int i = 0; i < numSpaces; i++) {
    spaces[i] = copy.spaces[i];
  }
}

/************************************************************************************************************************************************************ Function: All accessor function for the Business class
** Description: Returns private member variables
** Parameters: None
** Pre-Conditions: Must be outside of business scope, member variables are unreachable
** Post-Conditions: Returns member variables
**********************************************************************************************************************************************************/
int Business::get_num_spaces () { return numSpaces; }
string* Business::get_spaces () { return spaces; }

/************************************************************************************************************************************************************ Function: All mutator functions
** Description: Mutates private member variables
** Parameters: Member variable types
** Pre-Conditions: Must be outside of Business class, member variables are unreachable
** Post-Conditions: Mutates member variables
**********************************************************************************************************************************************************/
void Business::set_num_spaces (int ns) { numSpaces = ns; }
void Business::set_spaces (string* s) { spaces = s; }
