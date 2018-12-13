/*********************************************************************************************************************************************************** Program: driver.cpp
** Author: Emerald Seale
** Date: 5/10/18
** Input: None
** Output: None
*********************************************************************************************************************************************************/
#include "property.h"
#include "house.h"
#include "apartment.h"
#include "business.h"
#include "game.h"
#include <iostream>
#include <string>

using namespace std;

/********************************************************************************************************************************************************** Function: main
** Description: Is called when program starts
** Paramters: None
** Input: None
** Output: None
*********************************************************************************************************************************************************/
int main () {

	Game g;
	g.start_game();
	do {
		g.run_turn();
	} while (g.get_bank_account() > 0 && g.get_bank_account() < 1000000);
	g.end_game();

	return 0;
}
