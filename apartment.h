/*********************************************************************************************************************************************************** Program: apartment.h
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all member functions and variables for the Apartment class
** Input: None
** Output: None
*********************************************************************************************************************************************************/
#ifndef APARTMENT_H
#define APARTMENT_H
#include "property.h"
#include "tenant.h"
#include <string>

using namespace std;

class Apartment: public Property {

  private:
    int numRooms;

  public:
    Apartment (); // default constructor
    Apartment (int, string, float, float, int, Tenant*, int); // non-default constructor
    ~Apartment (); // destructor
    Apartment (const Apartment&); // copy constructor
    const Apartment& operator= (const Apartment&); // Assignment operator overload
    //Accessors:
    int get_num_rooms ();
    //Mutators:
    void set_num_rooms (int);

};

#endif
