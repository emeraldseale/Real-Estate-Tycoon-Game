/************************************************************************************************************************************************************ Program: game.cpp
** Author: Emerald Seale
** Date: 5/10/18
** Description: Holds all function bodies for the game class
** Input: User input on property prices, whether or not to sell/buy property, selecting property
** Output: User UI of bank account, houses, apartments, businesses, and random events
**********************************************************************************************************************************************************/
#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <cmath>
#include "game.h"

using namespace std;

/************************************************************************************************************************************************************ Function: Game
** Description: Default constructor for the game class
** Parameters: None
** Pre-Conditions: A game object is declared
** Post-Conditions: A game object is created and its member variables are set to default
**********************************************************************************************************************************************************/
Game::Game () {

  bankAccount = 500000;
  month = 0;
  numHouses = 0;
  numBusinesses = 0;
  numApartments = 0;
  ownedHouses = NULL;
  ownedApartments = NULL;
  ownedBusinesses = NULL;
}

/************************************************************************************************************************************************************ Function: ~Game
** Description: Destructor for the Game class
** Parameters: None
** Pre-Conditions: A game object goes out of scope
** Post-Conditions: A game object is destroyed and dynamic memory is freed from the heap
**********************************************************************************************************************************************************/
Game::~Game () {

  delete [] ownedHouses;
  delete [] ownedBusinesses;
  delete [] ownedApartments;
}

/************************************************************************************************************************************************************ Function: get_bank_account
** Description: Accessor function for the bankAccount member variable
** Parameters: None
** Pre-Conditions: bankAccount is unaccessable
** Post-Conditions: bankAccount is returned
**********************************************************************************************************************************************************/
int Game::get_bank_account() { return bankAccount; }


/************************************************************************************************************************************************************ Function: print_house
** Description: Prints a house object
** Parameters: House h
** Pre-Conditions: A house object needs to be printed to the screen
** Post-Conditions: A house object is printed to the screen
**********************************************************************************************************************************************************/
void Game::print_house (House h) {

  cout << "\tType: House" << endl;
  cout << "\tProperty Value: $" << h.get_property_value() << endl;
  cout << "\tLocation: " << h.get_location() << endl;
  cout << "\tMortgage: $" << h.get_mortgage() << " per month" << endl;
  cout << "\tProperty Tax: " << h.get_property_tax() << "% every 12 months" << endl;
  cout << "\tNumber of tenants: " << h.get_num_tenants() << endl;
  if (h.get_num_tenants() > 0) {
    cout << "\tTenant monthly income: $" << h.get_tenants()[0].income << endl;
    cout << "\tTenant agreeableness: " << h.get_tenants()[0].agreeableness << endl;
    cout << "\tTenant type: " << h.get_tenants()[0].type << endl;
  }
}


/************************************************************************************************************************************************************ Function: print_apartment
** Description: Prints an apartment object
** Parameters: Apartment a
** Pre-Conditions: An apartment object needs to be printed
** Post-Conditions: An apartment object is printed to the screen
**********************************************************************************************************************************************************/
void Game::print_apartment (Apartment a) {

  cout << "\tType: Apartment Complex" << endl;
  cout << "\tProperty Value: $" << a.get_property_value() << endl;
  cout << "\tLocation: " << a.get_location() << endl;
  cout << "\tMortgage: $" << a.get_mortgage() << " per month"<< endl;
  cout << "\tProperty Tax: " << a.get_property_tax() << "% every 12 months"<< endl;
  cout << "\tNumber of rooms: " << a.get_num_rooms() << endl;
  cout << "\tNumber of tenants: " << a.get_num_tenants() << endl;
  if (a.get_num_tenants() > 0) {
    for (int i = 0; i < a.get_num_tenants(); i++) {
      cout << "\tTenant " << (i + 1) << "'s monthly income, agreeableness, and type: $" << a.get_tenants()[i].income << ", ";
      cout << a.get_tenants()[i].agreeableness << ", " << a.get_tenants()[i].type << endl;
    }
  }
}


/************************************************************************************************************************************************************ Function: print_business
** Description: Prints a business object
** Parameters: Business b
** Pre-Conditions: A business object needs to be printed
** Post-Conditions: A business object is printed to the screen
**********************************************************************************************************************************************************/
void Game::print_business (Business b) {
  cout << "\tType: Business Complex" << endl;
  cout << "\tProperty Value: $" << b.get_property_value() << endl;
  cout << "\tLocation: " << b.get_location() << endl;
  cout << "\tMortgage: $" << b.get_mortgage() << " per month"<< endl;
  cout << "\tProperty Tax: " << b.get_property_tax() << "% every 12 months"<< endl;
  cout << "\tNumber of spaces: " << b.get_num_spaces() << endl;
  for (int i = 0; i < b.get_num_spaces(); i++) {
    cout << "\tSpace " << (i + 1) << " size: " << b.get_spaces()[i] << endl;
  }
  cout << "\tNumber of tenants: " << b.get_num_tenants() << endl;
  if (b.get_num_tenants() > 0) {
    for (int i = 0; i < b.get_num_tenants(); i++) {
      cout << "\tTenant " << (i + 1) << "'s monthly income, agreeableness, and type: $" << b.get_tenants()[i].income << ", ";
      cout << b.get_tenants()[i].agreeableness << ", " << b.get_tenants()[i].type << endl;
    }
  }

}


/************************************************************************************************************************************************************ Function: start_game
** Description: The game begins and an intro is printed
** Parameters: None
** Pre-Conditions: The program starts
** Post-Conditions: An intro to the game is printed to the screen
**********************************************************************************************************************************************************/
void Game::start_game () {

  cout << "\nWelcome to Real Estate Tycoon!" << endl;
  cout << "In this game the goal is to buy and sell properties and reach a bank account of $1,000,000, while avoiding bankruptcy at $0." << endl;
  cout << "Each turn you'll buy and sell properties, collect rent from tenants, re-adjust rents, pay off property tax and mortgages, as well as";
  cout << " experience a random event." << endl;
  cout << "\nGood luck, and have fun!" << endl;
}


/************************************************************************************************************************************************************ Function: display_stats
** Description: Prints player stats to the screen such as bank account and owned properties
** Parameters: None
** Pre-Conditions: It is the beginning of a new month/turn
** Post-Conditions: The player's updated stats are printed to the screen
**********************************************************************************************************************************************************/
void Game::display_stats () {


  cout << "\nIt is month " << month << "." << " Here's how you're doing: " << endl;
  cout << "\tYour bank account is at: $" << bankAccount << "." << endl;
  if (ownedHouses == NULL) {
    cout << "\tYou currently do not own any houses." << endl;
  } else {
    cout << "\tYou currently own " << numHouses << " house(s)." << endl;
  }
  if (ownedApartments == NULL) {
    cout << "\tYou currently do not own any apartment complexes." << endl;
  } else {
    cout << "\tYou currently own " << numApartments << " apartment complexe(s)." << endl;
  }
  if (ownedBusinesses == NULL) {
    cout << "\tYou currently do not own any business complexes." << endl;
  } else {
    cout << "\tYou currently own " << numBusinesses << " business complexe(s)." << endl;
  }
}


/************************************************************************************************************************************************************ Function: present_properties
** Description: Prints the 3 properties that are for sale
** Parameters: House h, Apartment a, and Business b
** Pre-Conditions: The player chooses to browse properties for sale
** Post-Conditions: The player's options of properties to buy are displayed
**********************************************************************************************************************************************************/
bool Game::present_properties (House h, Apartment a, Business b) {

  string choice = " ";
  do {
    cout << "\nThere are 3 properties on the market. Would you like to check them out? Y/N: ";
    getline(cin, choice);
  } while (choice != "y" && choice != "Y" && choice != "n" && choice != "N");
  if (choice == "y" || choice == "Y") {
    cout << "Here's whats for sale: " << endl;
    cout << "\n\tOPTION (1): " << endl;
    print_house(h);
    cout << "\n\tOPTION (2): " << endl;
    print_apartment(a);
    cout << "\n\tOPTION (3): " << endl;
    print_business(b);
    return true;
  } else {
    return false;
  }
}


/************************************************************************************************************************************************************ Function: add_house
** Description: Adds a purchased house to the array of owned houses
** Parameters: House h
** Pre-Conditions: The player decides to buy a house
** Post-Conditions: The owned houses array is resized and the new house is added to it
**********************************************************************************************************************************************************/
void Game::add_house (House h) {

  numHouses++;
  if (numHouses > 1) {
    House* temp = new House [numHouses];
    for (int i = 0; i < (numHouses - 1); i++) {
      temp[i] = ownedHouses[i];
    }
    temp[(numHouses - 1)] = h;
    delete [] ownedHouses;
    ownedHouses = new House [numHouses];
    for (int i = 0; i < numHouses; i++) {
      ownedHouses[i] = temp[i];
    }
    delete [] temp;
  } else {
    ownedHouses = new House [1];
    ownedHouses[0] = h;
  }
  bankAccount = (bankAccount - h.get_property_value());
  int newRent = 0;
  cout << "Congratulations, you've purchased a new property! What will you set the monthly rent to?" << endl;
  cout << "Enter the monthly rent for this property: ";
  cin >> newRent;
  ownedHouses[(numHouses - 1)].set_rent(newRent);
}


/************************************************************************************************************************************************************ Function: add_apartment
** Description: Adds a purchased apartment to the array of owned apartments
** Parameters: Apartment a
** Pre-Conditions: The player purchases a new apartment
** Post-Conditions: The array of owned apartments is resized and the new apartment is added to it
**********************************************************************************************************************************************************/
void Game::add_apartment (Apartment a) {

  numApartments++;
  if (numApartments > 1) {
    Apartment* temp = new Apartment [numApartments];
    for (int i = 0; i < (numApartments - 1); i++) {
      temp[i] = ownedApartments[i];
    }
    temp[(numApartments - 1)] = a;
    delete [] ownedApartments;
    ownedApartments = new Apartment [numApartments];
    for (int i = 0; i < numApartments; i++) {
      ownedApartments[i] = temp[i];
    }
    delete [] temp;
  } else {
    ownedApartments = new Apartment [1];
    ownedApartments[0] = a;
  }
  bankAccount = (bankAccount - a.get_property_value());
  int newRent = 0;
  cout << "Congratulations, you've purchased a new property! What will you set the monthly rent to?" << endl;
  cout << "Enter the monthly rent for this property: ";
  cin >> newRent;
  ownedApartments[(numApartments - 1)].set_rent(newRent);
}


/************************************************************************************************************************************************************ Function: add_business
** Description: Adds a newly purchased business to the array of owned businesses
** Parameters: Business b
** Pre-Conditions: The player buys a new business complex
** Post-Conditions: The array of owned businesses is resized and the new business is added to it
**********************************************************************************************************************************************************/
void Game::add_business (Business b) {

  numBusinesses++;
  if (numBusinesses > 1) {
    Business* temp = new Business [numBusinesses];
    for (int i = 0; i < (numBusinesses - 1); i++) {
      temp[i] = ownedBusinesses[i];
    }
    temp[(numBusinesses - 1)] = b;
    delete [] ownedBusinesses;
    ownedBusinesses = new Business [numBusinesses];
    for (int i = 0; i < numBusinesses; i++) {
      ownedBusinesses[i] = temp[i];
    }
    delete [] temp;
  } else {
    ownedBusinesses = new Business [1];
    ownedBusinesses[0] = b;
  }
  bankAccount = (bankAccount - b.get_property_value());
  int newRent = 0;
  cout << "Congratulations, you've purchased a new property! What will you set the monthly rent to?" << endl;
  cout << "Enter the monthly rent for this property: ";
  cin >> newRent;
  ownedBusinesses[(numBusinesses - 1)].set_rent(newRent);
}


/************************************************************************************************************************************************************ Function: buy_property
** Description: Allows the user to choose whether or not to buy a new property
** Parameters: None
** Pre-Conditions: The user decides to look at properties
** Post-Conditions: The user can choose to buy 1 of 3 properties or back out
**********************************************************************************************************************************************************/
void Game::buy_property () {

  string choice = " ";
  House h;
  Apartment a;
  Business b;
  if (present_properties(h, a, b) == true) {
    do {
      cout << "Enter the number of the property you want to buy, or enter (Q) to cancel: ";
      getline(cin, choice);
    } while (choice != "1" && choice != "2" && choice != "3" && choice != "Q" && choice != "q");
    if (choice == "1") {
      add_house(h);
    } else if (choice == "2") {
      add_apartment(a);
    } else if (choice == "3") {
      add_business(b);
    } else {
      cout << "You gotta spend money to make money... maybe next time." << endl;
    }
  } else {
    cout << "You gotta spend money to make money... maybe next time." << endl;
  }
}


/************************************************************************************************************************************************************ Function: collect_rent
** Description: Collects rent from all existing tenants in owned properties
** Parameters: None
** Pre-Conditions: It is the beginning of a new month/turn
** Post-Conditions: Total rent is added up, added to the bank account, and printed to the screen
**********************************************************************************************************************************************************/
void Game::collect_rent () {

  if (ownedHouses == NULL && ownedApartments == NULL && ownedBusinesses == NULL) {
    cout << "\nYou don't have any tenants to collect rent from!" << endl;
  } else {
    int totalRent = 0;
    for (int i = 0; i < numHouses; i++) {
      bankAccount = bankAccount + ownedHouses[i].get_rent();
      totalRent = totalRent + ownedHouses[i].get_rent();
    }
    for (int i = 0; i < numApartments; i++) {
      bankAccount = bankAccount + (ownedApartments[i].get_rent() * ownedApartments[i].get_num_tenants());
      totalRent = totalRent + (ownedApartments[i].get_rent() * ownedApartments[i].get_num_tenants());
    }
    for (int i = 0; i < numBusinesses; i++) {
      bankAccount = bankAccount + (ownedBusinesses[i].get_rent() * ownedBusinesses[i].get_num_tenants());
      totalRent = totalRent + (ownedBusinesses[i].get_rent() * ownedBusinesses[i].get_num_tenants());
    }
    cout << "\nYou've collected $" << totalRent << " in rent this month." << endl;
  }
}


/************************************************************************************************************************************************************ Function: subtract_tenant_apartment
** Description: Deletes a tenant from an apartment when they move out
** Parameters: Apartment a by reference
** Pre-Conditions: The rent is set above the tenant's income and the tenant's agreeableness is above 2
** Post-Conditions: The tenant moves out and the rent is set to 0
**********************************************************************************************************************************************************/
void Game::subtract_tenant_apartment (Apartment& a) {

  int numMove = 0;
  for (int i = 0; i < a.get_num_tenants(); i++) {
    if (a.get_rent() > a.get_tenants()[i].income) {
      numMove++;
    }
  }
  int num = a.get_num_tenants() - numMove;
  a.set_num_tenants(0);
}


/************************************************************************************************************************************************************ Function: subtract_tenant_business
** Description: Deletes a tenant from a business when they move out
** Parameters: Business b by reference
** Pre-Conditions: The rent is set above the tenant's income and the tenant's agreeableness is above 2
** Post-Conditions: The tenant moves out and the rent is set to 0
**********************************************************************************************************************************************************/
void Game::subtract_tenant_business (Business& b) {

  int numMove = 0;
  for (int i = 0; i < b.get_num_tenants(); i++) {
    if (b.get_rent() > b.get_tenants()[i].income) {
      numMove++;
    }
  }
  int num = b.get_num_tenants() - numMove;
  b.set_num_tenants(0);
}


/************************************************************************************************************************************************************ Function: check_tenants_houses
** Description: Checks to see if any tenants in houses can't pay the rent
** Parameters: None
** Pre-Conditions: It is the start of a new turn or the player has just adjusted the rent of a house
** Post-Conditions: If the rent is above the tenant's income the tenant moves out or refuses to pay
**********************************************************************************************************************************************************/
void Game::check_tenants_houses () {

  for (int i = 0; i < numHouses; i++) {
    for (int j = 0; j < ownedHouses[i].get_num_tenants(); j++) {
      if (ownedHouses[i].get_rent() > ownedHouses[i].get_tenants()[j].income)
        if (ownedHouses[i].get_tenants()[j].agreeableness >= 3) {
          cout << "\nYou've set the rent for house " << (i + 1) << " too high! The tenant has moved out." << endl;
          ownedHouses[i].set_rent(0);
          ownedHouses[i].set_num_tenants(0);
        } else {
          cout << "\nYou've set the rent for house " << (i + 1) << " too high! The tenant refuses to pay." << endl;
          ownedHouses[i].set_rent(0);
        }
      }
  }
}


/************************************************************************************************************************************************************ Function: check_tenants_apartments
** Description: Checks to see if tenants in apartments can't pay the rent
** Parameters: None
** Pre-Conditions: The player adjusts an apartments rent or a new turn begins
** Post-Conditions: The tenant moves out or refuses to pay if the rent is above their income
**********************************************************************************************************************************************************/
void Game::check_tenants_apartments () {

  for (int i = 0; i < numApartments; i++) {
    for (int j = 0; j < ownedApartments[i].get_num_tenants(); j++) {
      if (ownedApartments[i].get_rent() > ownedApartments[i].get_tenants()[j].income)
        if (ownedApartments[i].get_tenants()[j].agreeableness >= 3) {
          cout << "\nYou've set the rent for apartment complex " << (i + 1) << " too high! The tenant has moved out." << endl;
          ownedApartments[i].set_rent(0);
          subtract_tenant_apartment(ownedApartments[i]);
        } else {
          cout << "\nYou've set the rent for apartment complex " << (i + 1) << " too high! The tenant refuses to pay." << endl;
          ownedApartments[i].set_rent(0);
        }
      }
  }
}


/************************************************************************************************************************************************************ Function: check_tenants_businesses
** Description: Checks to see if any tenants in businesses can pay the rent
** Parameters: None
** Pre-Conditions: The player adjusts a business rent or the turn begins
** Post-Conditions: The tenant moves out or refuses to pay if the rent is above their income
**********************************************************************************************************************************************************/
void Game::check_tenants_businesses () {

  for (int i = 0; i < numBusinesses; i++) {
    for (int j = 0; j < ownedBusinesses[i].get_num_tenants(); j++) {
      if (ownedBusinesses[i].get_rent() > ownedBusinesses[i].get_tenants()[j].income)
        if (ownedBusinesses[i].get_tenants()[j].agreeableness >= 3) {
          cout << "\nYou've set the rent for business complex  " << (i + 1) << " too high! The tenant has moved out." << endl;
          ownedBusinesses[i].set_rent(0);
          subtract_tenant_business(ownedBusinesses[i]);
        } else {
          cout << "\nYou've set the rent for business complex  " << (i + 1) << " too high! The tenant refuses to pay." << endl;
          ownedBusinesses[i].set_rent(0);
        }
      }
  }
}


/************************************************************************************************************************************************************ Function: pay_mortgage_taxes
** Description: Pays all mortgage every turn, taxes every 12 turns, and raises property value by 1% for businesses
** Parameters: None
** Pre-Conditions: The turn begins
** Post-Conditions: Mortages and taxes are subtracted from the bank account
**********************************************************************************************************************************************************/
void Game::pay_mortgage_taxes() {

  int totalValue = 0;
  int totalMortgage = 0;
  for (int i = 0; i < numHouses; i++) {
    totalMortgage = totalMortgage + ownedHouses[i].get_mortgage();
    totalValue = totalValue + ownedHouses[i].get_property_value();
  }
  for (int i = 0; i < numApartments; i++) {
    totalMortgage = totalMortgage + ownedApartments[i].get_mortgage();
    totalValue = totalValue + ownedApartments[i].get_property_value();
  }
  for (int i = 0; i < numBusinesses; i++) {
    totalMortgage = totalMortgage + ownedBusinesses[i].get_mortgage();
    totalValue = totalValue + ownedBusinesses[i].get_property_value();
  }
  cout << "\nYou have paid $" << totalMortgage << " in mortgage this month." << endl;
  bankAccount = (bankAccount - totalMortgage);
  float num = (float)month / (float)12;
  if (num == 1.0 || num == 2.0 || num == 3.0 || num == 4.0 || num == 5.0) {
    bankAccount = bankAccount - ((float)totalValue * .015);
    cout << "\nYou have paid $" << (totalValue * .015) << " in taxes this year." << endl;
  }
}


/************************************************************************************************************************************************************ Function: hurricane
** Description: Lowers all SE properties value by 50%
** Parameters: None
** Pre-Conditions: The hurricane random event is triggered
** Post-Conditions: All SE property values are cut by 50%
**********************************************************************************************************************************************************/
void Game::hurricane() {

  for (int i = 0; i < numHouses; i++) {
    if (ownedHouses[i].get_location() == "SE") {
      ownedHouses[i].set_property_value((ownedHouses[i].get_property_value() * .5));
    }
  }
  for (int i = 0; i < numApartments; i++) {
    if (ownedApartments[i].get_location() == "SE") {
      ownedApartments[i].set_property_value((ownedApartments[i].get_property_value() * .5));
    }
  }
  for (int i = 0; i < numBusinesses; i++) {
    if (ownedBusinesses[i].get_location() == "SE") {
      ownedBusinesses[i].set_property_value((ownedBusinesses[i].get_property_value() * .5));
    }
  }
}


/************************************************************************************************************************************************************ Function: tornado
** Description: Lowers all Midwest property values by 30%
** Parameters: None
** Pre-Conditions: The tornado random event is triggered
** Post-Conditions: All midwest property values are cut by 30%
**********************************************************************************************************************************************************/
void Game::tornado() {

  for (int i = 0; i < numHouses; i++) {
    if (ownedHouses[i].get_location() == "Midwest") {
      ownedHouses[i].set_property_value((ownedHouses[i].get_property_value() * .3));
    }
  }
  for (int i = 0; i < numApartments; i++) {
    if (ownedApartments[i].get_location() == "Midwest") {
      ownedApartments[i].set_property_value((ownedApartments[i].get_property_value() * .3));
    }
  }
  for (int i = 0; i < numBusinesses; i++) {
    if (ownedBusinesses[i].get_location() == "Midwest") {
      ownedBusinesses[i].set_property_value((ownedBusinesses[i].get_property_value() * .3));
    }
  }
}


/************************************************************************************************************************************************************ Function: earthquake
** Description: Lowers all NW property values by 90%
** Parameters: None
** Pre-Conditions: The earthquake random event is triggered
** Post-Conditions: All NW property values are lowered by 90%
**********************************************************************************************************************************************************/
void Game::earthquake() {

  for (int i = 0; i < numHouses; i++) {
    if (ownedHouses[i].get_location() == "NW") {
      ownedHouses[i].set_property_value((ownedHouses[i].get_property_value() * .9));
    }
  }
  for (int i = 0; i < numApartments; i++) {
    if (ownedApartments[i].get_location() == "NW") {
      ownedApartments[i].set_property_value((ownedApartments[i].get_property_value() * .9));
    }
  }
  for (int i = 0; i < numBusinesses; i++) {
    if (ownedBusinesses[i].get_location() == "NW") {
      ownedBusinesses[i].set_property_value((ownedBusinesses[i].get_property_value() * .9));
    }
  }
}

/************************************************************************************************************************************************************ Function: wildfire
** Description: Lowers all SW properties by 25%
** Parameters: None
** Pre-Conditions: The wildfire random event is triggered
** Post-Conditions: All SW property values are lowered by 25%
**********************************************************************************************************************************************************/

void Game::wildfire() {

  for (int i = 0; i < numHouses; i++) {
    if (ownedHouses[i].get_location() == "SW") {
      ownedHouses[i].set_property_value((ownedHouses[i].get_property_value() * .25));
    }
  }
  for (int i = 0; i < numApartments; i++) {
    if (ownedApartments[i].get_location() == "SW") {
      ownedApartments[i].set_property_value((ownedApartments[i].get_property_value() * .25));
    }
  }
  for (int i = 0; i < numBusinesses; i++) {
    if (ownedBusinesses[i].get_location() == "SW") {
      ownedBusinesses[i].set_property_value((ownedBusinesses[i].get_property_value() * .25));
    }
  }
}


/*********************************************************************************************************************************************************** Function: stock_market_crash
** Description: Lowers all property values by 30%
** Parameters: None
** Pre-Conditions: The stock market crash random event is triggered
** Post-Conditions: All property values are lowered by 30%
*********************************************************************************************************************************************************/
void Game::stock_market_crash () {

  for (int i = 0; i < numHouses; i++) {
      ownedHouses[i].set_property_value((ownedHouses[i].get_property_value() * .3));
  }
  for (int i = 0; i < numApartments; i++) {
      ownedApartments[i].set_property_value((ownedApartments[i].get_property_value() * .3));
  }
  for (int i = 0; i < numBusinesses; i++) {
      ownedBusinesses[i].set_property_value((ownedBusinesses[i].get_property_value() * .3));
  }
}


/*********************************************************************************************************************************************************** Function: gentrification
** Description: A property value in a random place is raised by 20%
** Parameters: None
** Pre-Conditions: The gentrification random event is triggered
** Post-Conditions: All property values in said location are raised by 20%
*********************************************************************************************************************************************************/
void Game::gentrification () {

  for (int i = 0; i < numHouses; i++) {
    if (ownedHouses[i].get_location() == "NW") {
      ownedHouses[i].set_property_value((ownedHouses[i].get_property_value() + (ownedHouses[i].get_property_value() * .2)));
    }
  }
  for (int i = 0; i < numApartments; i++) {
    if (ownedApartments[i].get_location() == "NW") {
      ownedApartments[i].set_property_value((ownedApartments[i].get_property_value() + (ownedApartments[i].get_property_value() * .2)));
    }
  }
  for (int i = 0; i < numBusinesses; i++) {
    if (ownedBusinesses[i].get_location() == "NW") {
      ownedBusinesses[i].set_property_value((ownedBusinesses[i].get_property_value() + (ownedBusinesses[i].get_property_value() * .2)));
    }
  }
}


/*********************************************************************************************************************************************************** Function: random_event
** Description: Rolls a random number to decide what kind of random event will occur
** Parameters: None
** Pre-Conditions: A new turn begins
** Post-Conditions: Some random event is triggered
*********************************************************************************************************************************************************/
void Game::random_event() {

  int randNum = rand() % 6;
  if (randNum == 0) {
    cout << "\nRANDOM EVENT! A hurricane strikes, decreasing SE property values by 50%." << endl;
    hurricane();
  } else if (randNum == 1) {
    cout << "\nRANDOM EVENT! A tornado strikes, decreasing Midwest property values by 30%." << endl;
    tornado();
  } else if (randNum == 2) {
    cout << "\nRANDOM EVENT! The big earthquake is finally here, and decreases NW property values by 90%." << endl;
    earthquake();
  } else if (randNum == 3) {
    cout << "\nRANDOM EVENT! A wildfire rages, decreasing SW property values by 25%." << endl;
    wildfire();
  } else if (randNum == 4) {
    cout << "\nRANDOM EVENT! There's a huge stock market crash, lowering all property values by 30%." << endl;
    stock_market_crash();
  } else if (randNum == 5) {
    cout << "\nRANDOM EVENT! Good news? Gentrificaiton has taken hold, pushing low-income families out of their homes... but increasing NW";
    cout << " property values by 20%!" << endl;
    gentrification();
  }
}


/*********************************************************************************************************************************************************** Function: present_sell_properties
** Description: Presents all properties available for the player to sell
** Parameters: None
** Pre-Conditions: The player decides to sell a property
** Post-Conditions: The possible sales are diplayed to the screen
*********************************************************************************************************************************************************/
void Game::present_sell_properties () {

  if (numHouses == 0 && numApartments == 0 && numBusinesses == 0) {
    cout << "You don't have any properties to sell!" << endl;
  } else {
    for (int i = 0; i < numHouses; i++) {
      cout << "Here are the houses you can sell:" << endl;
      if (ownedHouses[i].get_num_tenants() == 0) {
        cout << "(" << (i + 1) << ")";
        print_house(ownedHouses[i]);
      } else {
        cout << "(" << (i + 1) << ")" << " This house has tenants, so it cannot be sold." << endl;
      }
    }
    for (int i = 0; i < numApartments; i++) {
      cout << "Here are the apartment complexes you can sell:" << endl;
      if (ownedApartments[i].get_num_tenants() == 0) {
        cout << "(" << (i + 1) << ")";
        print_apartment(ownedApartments[i]);
      } else {
        cout << "(" << (i + 1) << ")" << " This apartment complex has tenants, so it cannot be sold." << endl;
      }
    }
    for (int i = 0; i < numBusinesses; i++) {
      cout << "Here are the business complexes you can sell:" << endl;
      if (ownedBusinesses[i].get_num_tenants() == 0) {
        cout << "(" << (i + 1) << ")";
        print_business(ownedBusinesses[i]);
      } else {
        cout << "(" << (i + 1) << ")" << " This business complex has tenants, so it cannot be sold." << endl;
      }
    }
  }
}


/*********************************************************************************************************************************************************** Function: remove_house
** Description: Removes a house from the array of owned houses when one is sold
** Parameters: int houseNum
** Pre-Conditions: The player sells a house
** Post-Conditions: The owned houses array is resized and the house is deleted
*********************************************************************************************************************************************************/
void Game::remove_house (int houseNum) {

  numHouses--;
  if (numHouses == 0) {
    delete [] ownedHouses;
    ownedHouses = NULL;
  } else {
    House* temp = new House [numHouses];
    for (int i = 0; i < (numHouses - 1); i++) {
      if (i != houseNum) {
        temp[i] = ownedHouses[i];
      }
      delete [] ownedHouses;
      ownedHouses = new House [numHouses];
      for (int i = 0; i < (numHouses - 1); i++) {
        ownedHouses[i] = temp[i];
      }
    }
    delete [] temp;
    temp = NULL;
  }
}


/*********************************************************************************************************************************************************** Function: sell_house
** Description: Allows the player to select a house to sell and an asking price
** Parameters: None
** Pre-Conditions: The player chooses to sell a house
** Post-Conditions: The player sells the house and rolls a random number to decide if they got asking price
*********************************************************************************************************************************************************/
void Game::sell_house () {

  int houseNum = 0;
  int askingPrice = 0;
  int randNum = rand() % 3;
  cout << "Which house (by number) would you like to sell? Enter: ";
  cin >> houseNum;
  if (houseNum > numHouses || houseNum == 0) {
    cout << "You don't have that many houses!" << endl;
  } else {
    cout << "Enter your asking price for this house: ";
    cin >> askingPrice;
    if (randNum == 0) {
      cout << "Congratulations! You got the asking price!" << endl;
      bankAccount = bankAccount + askingPrice;
      remove_house(houseNum);
    } else if (randNum == 1) {
      cout << "Too bad! You didn't get the asking price, but you got the property value." << endl;
      bankAccount = bankAccount + ownedHouses[houseNum].get_property_value();
      remove_house(houseNum);
    } else {
      cout << "Too bad! You only got 90% of the property value." << endl;
      bankAccount = bankAccount + (ownedHouses[houseNum].get_property_value() * .9);
      remove_house(houseNum);
    }
  }
}


/*********************************************************************************************************************************************************** Function: remove_apartment
** Description: Removes a sold apartment from the owned apartments array
** Parameters: int apartmentNum
** Pre-Conditions: The player sells an apartment
** Post-Conditions: The owned apartments array is resized and the apartment is deleted
*********************************************************************************************************************************************************/
void Game::remove_apartment (int apartmentNum) {

  numApartments--;
  if (numApartments == 0) {
    delete [] ownedApartments;
    ownedApartments = NULL;
  } else {
    Apartment* temp = new Apartment [numApartments];
    for (int i = 0; i < (numApartments - 1); i++) {
      if (i != apartmentNum) {
        temp[i] = ownedApartments[i];
      }
      delete [] ownedApartments;
      ownedApartments = new Apartment [numApartments];
      for (int i = 0; i < (numApartments - 1); i++) {
        ownedApartments[i] = temp[i];
      }
    }
    delete [] temp;
    temp = NULL;
  }
}


/*********************************************************************************************************************************************************** Function: sell_apartment
** Description: Allows the user to select an apartment to sell
** Parameters: None
** Pre-Conditions: The user selects to sell an apartment
** Post-Conditions: The user specifies an apartment, asking price, and has 1/3 chance in getting it
*********************************************************************************************************************************************************/
void Game::sell_apartment () {

    int apartmentNum = 0;
    int askingPrice = 0;
    int randNum = rand() % 3;
    cout << "Which apartment complex (by number) would you like to sell? Enter: ";
    cin >> apartmentNum;
    if (apartmentNum > numApartments || apartmentNum == 0) {
      cout << "You don't have that many apartment complexes!" << endl;
    } else {
      cout << "Enter your asking price for this apartment complex: ";
      cin >> askingPrice;
      if (randNum == 0) {
        cout << "Congratulations! You got the asking price!" << endl;
        bankAccount = bankAccount + askingPrice;
        remove_apartment(apartmentNum);
      } else if (randNum == 1) {
        cout << "Too bad! You didn't get the asking price, but you got the property value." << endl;
        bankAccount = bankAccount + ownedApartments[apartmentNum].get_property_value();
        remove_apartment(apartmentNum);
      } else {
        cout << "Too bad! You only got 90% of the property value." << endl;
        bankAccount = bankAccount + (ownedApartments[apartmentNum].get_property_value() * .9);
        remove_apartment(apartmentNum);
      }
    }
}


/*********************************************************************************************************************************************************** Function: remove_business
** Description: Removes a sold business from the array of owned businesses
** Parameters: None
** Pre-Conditions: A business is sold
** Post-Conditions: The owned businesses array is resized and the business is deleted
*********************************************************************************************************************************************************/
void Game::remove_business (int businessNum) {

  numBusinesses--;
  if (numBusinesses == 0) {
    delete [] ownedBusinesses;
    ownedBusinesses = NULL;
  } else {
    Business* temp = new Business [numBusinesses];
    for (int i = 0; i < (numBusinesses - 1); i++) {
      if (i != businessNum) {
        temp[i] = ownedBusinesses[i];
      }
      delete [] ownedBusinesses;
      ownedBusinesses = new Business [numBusinesses];
      for (int i = 0; i < (numBusinesses - 1); i++) {
        ownedBusinesses[i] = temp[i];
      }
    }
    delete [] temp;
    temp = NULL;
  }
}


/*********************************************************************************************************************************************************** Function: sell_business
** Description: Allows the user to sell a business
** Parameters: None
** Pre-Conditions: The user selects to sell a business
** Post-Conditions: The user specifies a business, asking price, and has a 1/3 chance of getting it
*********************************************************************************************************************************************************/
void Game::sell_business () {

    int businessNum = 0;
    int askingPrice = 0;
    int randNum = rand() % 3;
    cout << "Which business complex (by number) would you like to sell? Enter: ";
    cin >> businessNum;
    if (businessNum > numBusinesses || businessNum == 0) {
      cout << "You don't have that many business complexes!" << endl;
    } else {
      cout << "Enter your asking price for this business complex: ";
      cin >> askingPrice;
      if (randNum == 0) {
        cout << "Congratulations! You got the asking price!" << endl;
        bankAccount = bankAccount + askingPrice;
        remove_business(businessNum);
      } else if (randNum == 1) {
        cout << "Too bad! You didn't get the asking price, but you got the property value." << endl;
        bankAccount = bankAccount + ownedBusinesses[businessNum].get_property_value();
        remove_business(businessNum);
      } else {
        cout << "Too bad! You only got 90% of the property value." << endl;
        bankAccount = bankAccount + (ownedBusinesses[businessNum].get_property_value() * .9);
        remove_business(businessNum);
      }
    }
}


/*********************************************************************************************************************************************************** Function: sell_property
** Description: Allows the user to select if they want to sell a property
** Parameters: None
** Pre-Conditions: The turn begins
** Post-Conditions: The user selects Y or N to sell a property
*********************************************************************************************************************************************************/
void Game::sell_property () {

  string choice = " ";
  do {
    cout << "\nWould you like to sell any of your properties? Y/N: ";
    getline(cin, choice);
  } while (choice != "y" && choice != "Y" && choice != "n" && choice != "N");
  if (choice == "y" || choice == "Y") {
    present_sell_properties();
    do {
      cout << "Would you like to sell a house, apartment, or business complex? H/A/B: ";
      getline(cin, choice);
    } while (choice != "h" && choice != "H" && choice != "a" && choice != "A" && choice != "b" && choice != "B");
    if (choice == "h" || choice == "H") {
      sell_house();
    } else if (choice == "a" || choice == "A") {
      sell_apartment();
    } else {
      sell_business();
    }
  }
}


/*********************************************************************************************************************************************************** Function: print_properties
** Description: Prints all owned properties to the screen
** Parameters: None
** Pre-Conditions: The owned proeprties need to be printed to the screen
** Post-Conditions: The owned properties are printed to the screen
*********************************************************************************************************************************************************/
void Game::print_properties () {

  if (numHouses == 0) {
    cout << "\nYou don't own any houses." << endl;
  } else {
    cout << "\nHOUSE(S):" << endl;
    for (int i = 0; i < numHouses; i++) {
      cout << "(" << (i + 1) << ") ";
      print_house(ownedHouses[i]);
    }
  }
  if (numApartments == 0) {
    cout << "\nYou don't own any apartment complexes." << endl;
  } else {
    cout << "\nAPARTMENT COMPLEXE(S):" << endl;
    for (int i = 0; i < numApartments; i++) {
      cout << "(" << (i + 1) << ") ";
       print_apartment(ownedApartments[i]);
    }
  }
  if (numBusinesses == 0) {
    cout << "\nYou don't own any business complexes." << endl;
  } else {
    cout << "\nBUSINESS COMPLEXE(S):" << endl;
    for (int i = 0; i < numBusinesses; i++) {
      cout << "(" << (i + 1) << ") ";
       print_business(ownedBusinesses[i]);
    }
  }
}


/*********************************************************************************************************************************************************** Function: change_rent_house
** Description: Allows the user to change the rent of a specific house
** Parameters: None
** Pre-Conditions: The user selects to change rent of a property
** Post-Conditions: The user selects a specifc house to change the rent of
*********************************************************************************************************************************************************/
void Game::change_rent_house () {

  int houseNum = 0;
  int newRent = 0;
  cout << "Which house (by number) would you like to change the rent of? Enter: ";
  cin >> houseNum;
  if (houseNum > numHouses || houseNum == 0) {
    cout << "You don't have that many houses!" << endl;
  } else {
    cout << "Enter the new rent for this house: ";
    cin >> newRent;
    ownedHouses[(houseNum - 1)].set_rent(newRent);
    cout << "The rent has been set to $" << newRent << " a month." << endl;
  }
  check_tenants_houses();
}


/*********************************************************************************************************************************************************** Function: change_rent_apartment
** Description: Allows the user to change the rent of a specific apartment
** Parameters: None
** Pre-Conditions: The user selects to change rent of a property
** Post-Conditions: The user selects a specifc apartment to change the rent of
*********************************************************************************************************************************************************/
void Game::change_rent_apartment () {

  int apartmentNum = 0;
  int newRent = 0;
  cout << "Which apartment complex (by number) would you like to change the rent of? Enter: ";
  cin >> apartmentNum;
  if (apartmentNum > numApartments || apartmentNum == 0) {
    cout << "You don't have that many apartment complexes!" << endl;
  } else {
    cout << "Enter the new rent for this apartment: ";
    cin >> newRent;
    ownedApartments[(apartmentNum - 1)].set_rent(newRent);
    cout << "The rent has been set to $" << newRent << " a month." << endl;
  }
  check_tenants_apartments();
}


/*********************************************************************************************************************************************************** Function: change_rent_business
** Description: Allows the user to change the rent of a specific business
** Parameters: None
** Pre-Conditions: The user selects to change rent of a property
** Post-Conditions: The user selects a specifc business to change the rent of
*********************************************************************************************************************************************************/
void Game::change_rent_business () {

  int businessNum = 0;
  int newRent = 0;
  cout << "Which business complex (by number) would you like to change the rent of? Enter: ";
  cin >> businessNum;
  if (businessNum > numBusinesses || businessNum == 0) {
    cout << "You don't have that many business complexes!" << endl;
  } else {
    cout << "Enter the new rent for this business complex: ";
    cin >> newRent;
    ownedBusinesses[businessNum].set_rent(newRent);
    cout << "The rent has been set to $" << newRent << " a month." << endl;
  }
  check_tenants_businesses();
}


/*********************************************************************************************************************************************************** Function: change_rent
** Description: Allows the user to change the rent of a property
** Parameters: None
** Pre-Conditions: The user selects to change rent of a property
** Post-Conditions: The user selects a specifc property to change the rent of
*********************************************************************************************************************************************************/
void Game::change_rent () {

  string choice = " ";
  do {
    cout << "\nWould you like to change the rent of any of your properties? Y/N: ";
    getline(cin, choice);
  } while (choice != "y" && choice != "Y" && choice != "n" && choice != "N");
  if (choice == "y" || choice == "Y") {
    cout << "Here are the properties you currently own: " << endl;
    print_properties();
    do {
      cout << "Would you like to change a house, apartment complex, or business complex's rent? H/A/B: ";
      getline(cin, choice);
    } while (choice != "h" && choice != "H" && choice != "a" && choice != "A" && choice != "b" && choice != "B");
    if (choice == "h" || choice == "H") {
      change_rent_house();
    } else if (choice == "a" || choice == "A") {
      change_rent_apartment();
    } else {
      change_rent_business();
    }
  }
}

/*********************************************************************************************************************************************************** Function: run_turn
** Description: Calls all essential functions for one turn/month
** Parameters: None
** Pre-Conditions: The game begins
** Post-Conditions: The turns loop until the bank account is at 0 or 1000000
*********************************************************************************************************************************************************/
void Game::run_turn () {

  month++;
  display_stats();
  check_tenants_houses();
  check_tenants_apartments();
  check_tenants_businesses();
  collect_rent();
  pay_mortgage_taxes();
  random_event();
  buy_property ();
  sell_property();
  change_rent ();
}


/*********************************************************************************************************************************************************** Function: end_game
** Description: Ends the game when the bank account is at 0 or 1000000
** Parameters: None
** Pre-Conditions: The bank account is at 0 or 1000000
** Post-Conditions: Prints either a win or lose message if bank account is 1000000 or 0
*********************************************************************************************************************************************************/
void Game::end_game () {

  if (bankAccount > 1000000) {
    cout << "\nCongratulations! You're a millionare, and you've won the game!" << endl;
  } else {
    cout << "\nToo bad. You've gone bankrupt. Better luck next time!" << endl;
  }
}
