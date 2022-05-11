/**
 * Player function
 *
 * Author: Eyad Amer
 * Since : 2022-04
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Player.hpp"
#include "Game.hpp"

const int nine_Coines = 9;
const int seven_Coines = 7;

using namespace std;

namespace coup
{

    // empty constructur
    Player::Player()
    {
        this->SumOfCoins = 0;
        this->playerAlive = false;
        this->PlayerName = "";
        this->PlayerRole = "";
    }

    // constructur
    Player::Player(Game &game, string name)
    {
        //this->game->check_gamestart();
        this->game->check_MaxPlayer();
        this->game = &game;
        this->PlayerName = move(name);
        this->PlayerRole = "";
        this->SumOfCoins = 0;
        this->playerAlive = true;
        this->game->addPlayers(this);
    }

    // income function
    void Player::income()
    {
        isAlive();
        isYourTurn();
        limited_Coins();
        this->addPlayerCoins(1);
        action = "income";
        this->game->nextTurn();
    }

    // foreign_aid function
    void Player::foreign_aid()
    {
        isAlive();
        isYourTurn();
        limited_Coins();
        this->addPlayerCoins(2);
        action = "foreign_aid";
        this->game->nextTurn();
    }

    // coup function
    void Player::coup(Player &player)
    {
        isAlive();
        isYourTurn();
        player.isAlive();
        if (this->SumOfCoins >= seven_Coines)
        {
            player.playerAlive = false;
            this->subPlayerCoins(seven_Coines);
            action = "coup";
            this->game->nextTurn();
        }
        else
        {
            throw runtime_error("not enough coins");
        }
    }

    // get the role of the player
    string Player::role() const
    {
        return PlayerRole;
    }

    // get the sum of the coins the player have
    int Player::coins() const
    {
        return this->SumOfCoins;
    }
/**
    // get player name
    string Player::getPlayerName()
    {
        return PlayerName;
    }
*/

    // add coins to the player
    void Player::addPlayerCoins(int coin)
    {
        this->SumOfCoins += coin;
    }

    // sub coints to the player
    void Player::subPlayerCoins(int coin)
    {
        this->SumOfCoins -= coin;
    }

    // check if is the turn of the player
    void Player::isYourTurn() const
    {
        if (this->game->turn() != this->PlayerName)
        {
            throw runtime_error("is not your turn");
        }
    }

    // check if the player is in the game
    void Player::isAlive() const
    {
        if(!playerAlive)
        {
            throw runtime_error("the player is not in the game");
        }
    }

    // check if the player have a 10 of coins
    void Player::limited_Coins() const
    {
        if(this->SumOfCoins > nine_Coines)
        {
            throw runtime_error(" alote of coins - coup now!");
        }
    }

    // check if the player have a coins
    void Player::have_Coins() const
    {
        if(this->SumOfCoins < 1)
        {
            throw runtime_error(" don't have any coins!");
        }
    }
}