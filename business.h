/*********************************************************************************************************************************************************** Program: business.h
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all member functions and variables for the Business class
** Input: None
** Output: None
*********************************************************************************************************************************************************/
#ifndef BUSINESS_H
#define BUSINESS_H
#include "property.h"
#include "tenant.h"
#include <string>

using namespace std;

class Business: public Property {

  private:
    int numSpaces;
    string* spaces;

  public:
    Business (); // default constructor
    Business (int, string, float, float, int, Tenant*, int, string*); // non-default constructor
    ~Business (); // destructor
    Business (const Business&); // copy constructor
    const Business& operator= (const Business&); // Assignment operator overload
    //Accessor Functions:
    int get_num_spaces ();
    string* get_spaces ();
    //Mutator Functions:
    void set_num_spaces (int);
    void set_spaces (string*);
};

#endif
