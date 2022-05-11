/**
 * Captain Role function
 *
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Game.hpp"
#include "Captain.hpp"

const int two_Coins = 2;
static string Player_role = "Captain";

using namespace std;

namespace coup
{
    // constructor
    Captain::Captain(Game &game, string name): Player(game, move(name))
    {
        this->PlayerRole = Player_role;
    }

    // get the role of the player
    string Captain::role()
    {
        return Player_role;
    }

    // block the player that has a foreigen_aid
    void Captain::block(Player &player)
    {
        isAlive();
        player.isAlive();
        if(player.action != "steal" || Player::action != "foreign_aid")
        {
             throw runtime_error("error- this is not the action to blocked");
        }
        player.subPlayerCoins(two_Coins);
    }

    // steal 2 coins from anther player
    void Captain::steal(Player &player)
    {
        isAlive();
        isYourTurn();
        if(player.SumOfCoins > 1)
        {
            this->addPlayerCoins(two_Coins);
            player.subPlayerCoins(two_Coins);

            this->action = "steal";
        }
        

    }
}