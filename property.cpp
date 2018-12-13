/************************************************************************************************************************************************************ Program: property.cpp
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all function bodies for the Property class
** Input: Strings and integers deciding property based information
** Output: User UI surrounding property based information
**********************************************************************************************************************************************************/
#include "property.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>

using namespace std;

/************************************************************************************************************************************************************ Function: Property
** Description: Default constructor for the Property class
** Parameters: None
** Input: None
** Output: None
**********************************************************************************************************************************************************/
Property::Property () {

  srand(time(NULL));
  propertyValue = 0;
  rent = 0;
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
  propertyTax = 1.5;
  numTenants = 0;
  tenants = NULL;
}

/************************************************************************************************************************************************************ Function: Property
** Description: Non-default constructor for the Property class
** Parameters: int pv, string l, float m, float pt, Tenant* t
** Input: None
** Output: None
**********************************************************************************************************************************************************/
Property::Property (int pv, string l, float m, float pt, int nt, Tenant* t) {

  propertyValue = pv;
  location = l;
  mortgage = m;
  propertyTax = pt;
  numTenants = nt;
  tenants = t;
  delete [] t;
}

/************************************************************************************************************************************************************ Function: ~Property
** Description: Destructor for the Property class
** Parameters: None
** Input: None
** Output: None
**********************************************************************************************************************************************************/
Property::~Property () {

  delete [] tenants;
  tenants = NULL;
}

/************************************************************************************************************************************************************ Function: operator=
** Description: Assignment operator overload for the Property class
** Parameters: Property object by constant reference
** Input: None
** Output: None
**********************************************************************************************************************************************************/
const Property& Property::operator= (const Property& copy) {

  propertyValue = copy.propertyValue;
  rent = copy.rent;
  location = copy.location;
  mortgage = copy.mortgage;
  propertyTax = copy.propertyTax;
  numTenants = copy.numTenants;
  if (tenants != NULL) {
    delete [] tenants;
  }
  if (numTenants == 0) {
    tenants = NULL;
  } else {
    tenants = new Tenant [numTenants];
    for (int i = 0; i < numTenants; i++) {
      tenants[i].income = copy.tenants[i].income;
      tenants[i].agreeableness = copy.tenants[i].agreeableness;
      tenants[i].type = copy.tenants[i].type;
    }
  }
  return *this;
}

//GREATER THAN OP OVERLOAD:
bool Property::operator> (const Property& other) {

	cout << propertyValue << endl;
	cout << other.propertyValue << endl;
	cout << numTenants << endl;
	cout << other.numTenants << endl;
	
	if (propertyValue > other.propertyValue && numTenants > other.numTenants) {
		return true;
	} else { 
		return false;
	}
}

/************************************************************************************************************************************************************ Function: Property
** Description: Copy constructor for the Property class
** Parameters: Property object passed by constant reference
** Input: None
** Output: None
**********************************************************************************************************************************************************/
Property::Property (const Property& copy) {
  propertyValue = copy.propertyValue;
  location = copy.location;
  rent = copy.rent;
  mortgage = copy.mortgage;
  propertyTax = copy.propertyTax;
  numTenants = copy.numTenants;
  tenants = copy.tenants;
  if (numTenants == 0) {
    tenants = NULL;
  } else {
    tenants = new Tenant [numTenants];
    for (int i = 0; i < numTenants; i++) {
      tenants[i].income = copy.tenants[i].income;
      tenants[i].agreeableness = copy.tenants[i].agreeableness;
      tenants[i].type = copy.tenants[i].type;
    }
  }
}

/************************************************************************************************************************************************************ Function: Accessor Functions
** Description: All accessor functions for the Property class
** Parameters: None
** Input: None
** Output: None
**********************************************************************************************************************************************************/
int Property::get_property_value () { return propertyValue; }
string Property::get_location () { return location; }
float Property::get_mortgage () { return mortgage; }
float Property::get_property_tax () { return propertyTax; }
int Property::get_num_tenants () { return numTenants; }
Tenant* Property::get_tenants () { return tenants; }
int Property::get_rent () { return rent; }

/************************************************************************************************************************************************************ Function: Mutator Functions
** Description: All mutator functions for the Property class
** Parameters: int, string, float, Property*
** Input: None
** Output: None
**********************************************************************************************************************************************************/
void Property::set_property_value (int pv) { propertyValue = pv; }
void Property::set_location (string l) { location = l; }
void Property::set_mortgage (float m) { mortgage = m; }
void Property::set_property_tax (float pt) { propertyTax = pt; }
void Property::set_num_tenants (int t) { numTenants = t; }
void Property::set_tenants (Tenant* t) { tenants = t; }
void Property::set_rent (int r) { rent = r; }
