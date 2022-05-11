/**
 * Contessa Role function
 *
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Game.hpp"
#include "Contessa.hpp"

const int two_Coins = 2;
static string Player_role = "Contessa";

using namespace std;

namespace coup
{
    // constructor
    Contessa::Contessa(Game &game, string name): Player(game, move(name))
    {
        this->PlayerRole = Player_role;
    }

    // get the role of the player
    string Contessa::role()
    {
        return Player_role;
    }

    // block the player that has a assassin role
    void Contessa::block(Player &player)
    {
        isAlive();
        player.isAlive();
        if(player.action != "coup Assassin" || Player::action != "foreign_aid")
        {
             throw runtime_error("error- this is not the action to blocked");
        }
        player.subPlayerCoins(two_Coins);
    }
}