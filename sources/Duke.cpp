/**
 * Duke Role function
 *
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"

using namespace std;

const int three_Coins = 3;
const int two_Coins = 2;
static string Player_role = "Duke";

namespace coup
{ 
    // constructor
    Duke::Duke(Game &game, const string &name): Player(game, name)
    {
        this->PlayerRole = Player_role;
    }

    // get the role of the player
    string Duke::role()
    {
        return Player_role;
    }

    // tax 3 Coins from the cash register
    void Duke::tax()
    {
        isAlive();
        isYourTurn();
        this->addPlayerCoins(three_Coins);
        this->action = "tax";
        this->game->nextTurn();
    }

    // block the player that has a foreigen_aid
    void Duke::block(Player &player)
    {
        isAlive();
        player.isAlive();
        if(player.action != "foreign_aid")
        {
            throw runtime_error("error- this is not the action to blocked");
        }
        player.subPlayerCoins(two_Coins);
    }
}