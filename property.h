/*********************************************************************************************************************************************************** Program: property.h
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all member variables and functions for the Property class
** Input: None
** Output: None
*********************************************************************************************************************************************************/
#ifndef PROPERTY_H
#define PROPERTY_H
#include <string>
#include "tenant.h"

using namespace std;

class Property {

	protected:
		int propertyValue;
		int rent;
		string location;
		float mortgage;
		float propertyTax;
		int numTenants;
		Tenant* tenants;

	public:
		Property (); //default constructor
		Property (int, string, float, float, int, Tenant*); //non-default constructor
		~Property (); //destructor
		const Property& operator= (const Property&); //Assignment op overload
		bool operator> (const Property&);
		Property (const Property&); //Copy constructor
		//Accessor Functions:
		int get_property_value ();
		string get_location ();
		float get_mortgage ();
		float get_property_tax ();
		int get_num_tenants ();
		Tenant* get_tenants ();
		int get_rent ();
		//Mutator Functions:
		void set_property_value (int);
		void set_location (string);
		void set_mortgage (float);
		void set_property_tax (float);
		void set_num_tenants (int);
		void set_tenants (Tenant*);
		void set_rent (int);
};

#endif
