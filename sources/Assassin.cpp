/**
 * Assassin Role function
 * 
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Game.hpp"
#include "Assassin.hpp"

const int three_Coins = 3;
const int seven_Coins = 7;
static string Player_role = "Assassin";

using namespace std;

namespace coup
{
    // constructor
    Assassin::Assassin(Game &game, string name) : Player(game, move(name))
    {
        this->PlayerRole = Player_role;
    }

    // get the role of the player
    string Assassin::role()
    {
        return Player_role;
    }

    // function to kill the player
    void Assassin::coup(Player &player)
    {
        isAlive();
        player.isAlive();
        isYourTurn();
        check_3coins();
        if(this->SumOfCoins >= seven_Coins)
        {
            Player::coup(player);
        }
        else{
            player.playerAlive = false;
            this->subPlayerCoins(three_Coins);
            this->action = "coup Assassin";
        }
    }

    // check if the player have 3 or more coins
    void Assassin::check_3coins()
    {
        if(this->SumOfCoins < three_Coins)
        {
            throw runtime_error("the player don't have engoth coins");
        }
    }
}