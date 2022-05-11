/**`
 * Ambassador Role function
 *
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
    
#include "Game.hpp"
#include "Ambassador.hpp"

const int one_Coins = 1;
const int two_Coins = 2;
static string Player_role = "Ambassador";


using namespace std;
namespace coup
{
    // constructor
    Ambassador::Ambassador(Game &game, string name) : Player(game, move(name))
    {
        this->PlayerRole = Player_role;
    }

    // get the role of the player
    string Ambassador::role()
    {
        return Player_role;
    }

    // transfer 1 coin from player to player
    void Ambassador::transfer(Player &x, Player &y)
    {   
        isAlive();
        isYourTurn();
        if(x.SumOfCoins > 0){
            x.subPlayerCoins(one_Coins);
            y.addPlayerCoins(one_Coins);
            this->action = "transfer";
        }
        else{
            x.have_Coins();
        }
    }

    // block the player that want steal
    void Ambassador::block(Player &player)
    {
        isAlive();
        player.isAlive();
        if(player.action != "steal" || Player::action != "foreign_aid")
        {
             throw runtime_error("error- this is not the action to blocked");
        }
        player.subPlayerCoins(two_Coins);
    }
}