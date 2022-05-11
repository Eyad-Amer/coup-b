/**
 * Heading for the Player function
 *
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#pragma once

#include "Game.hpp"

using namespace std;
namespace coup
{
    class Player
    {
    public:
        int SumOfCoins; // sum of the coins of the player
        string PlayerName; // player name
        string PlayerRole; // player role
        Game *game; // Game
        Player(); // empty constructur
        Player(Game &game, string name); // constructur
        void income(); // income function
        void foreign_aid(); // foreign_aid function
        void coup(Player &player); // coup function
        string role() const; // get the role of the player
        int coins() const; // get the sum of the coins the player have
        string action; // the last action of the player
        void addPlayerCoins(int coin); // add coins to the player
        void subPlayerCoins(int coin); // sub coints to the player
        void isYourTurn() const; // check if is the turn of the player
        void isAlive() const; // check if the player is in the game
        void limited_Coins() const; // check if the player have a 10 of coins
        void have_Coins() const; // check if the player have a coins
        bool playerAlive; // check if the player is alive
        //string getPlayerName(); // get player name

    };
}