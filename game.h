/************************************************************************************************************************************************************ Program: game.h
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all member functions and variables for the game class
** Input: None
** Output: None
**********************************************************************************************************************************************************/
#ifndef GAME_H
#define GAME_H
#include "property.h"
#include "house.h"
#include "apartment.h"
#include "business.h"
#include "tenant.h"
#include <string>

using namespace std;

class Game {

  private:
    int bankAccount;
    int month;
    int numHouses;
    int numBusinesses;
    int numApartments;
    House* buyableHouses[3];
    Apartment* buyableApartments[3];
    Business* buyableBusinesses[3];
    House* ownedHouses;
    Apartment* ownedApartments;
    Business* ownedBusinesses;
  public:
    Game ();
    ~Game ();
    int get_bank_account ();
    void start_game ();
    void run_turn ();
    void display_stats ();
    void random_event ();
    void hurricane ();
    void tornado ();
    void earthquake ();
    void wildfire ();
    void stock_market_crash ();
    void gentrification ();
    void check_tenants_houses ();
    void check_tenants_apartments();
    void check_tenants_businesses();
    void subtract_tenant_apartment (Apartment&);
    void subtract_tenant_business (Business&);
    void collect_rent ();
    void buy_property ();
    bool present_properties (House, Apartment, Business);
    void add_house (House);
    void add_apartment (Apartment);
    void add_business (Business);
    void pay_mortgage_taxes ();
    void sell_property ();
    void present_sell_properties ();
    void sell_house ();
    void remove_house (int);
    void sell_apartment ();
    void remove_apartment (int);
    void sell_business ();
    void remove_business (int);
    void change_rent ();
    void change_rent_house ();
    void change_rent_apartment ();
    void change_rent_business ();
    void end_game ();
    void print_properties ();
    void print_house (House);
    void print_apartment (Apartment);
    void print_business (Business);
};

#endif
