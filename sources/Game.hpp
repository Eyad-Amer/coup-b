/**
 * Heading for the Game function
 *
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Player.hpp"

#pragma once

using namespace std;

namespace coup
{
    
    class Game
    {
    private:
        vector<Player *> get_Players; // get the players
    public:
        Game(); // constructor
        vector<string> playerslist; // the function returns a list of names of the players 
        static bool GameStart; // true if the game is start
        bool start_Game(); // boolean for start the game
        unsigned numOfPlayers; // the num of the players in the game
        unsigned index; // the index of the player in the vector
        string turn(); // name the player that his turn
        vector<string> players(); // the function returns the name of the players in the game
        string winner(); // the function returns the name of the winner
        void addPlayers(Player *player); // add players
        //void removePlayers(Player *player); // remove players
        void nextTurn(); // next turn
        void check_legal() const; // check if it is legal
        static void check_gamefinsh(); // check if the game is finshed
        static void check_gamestart(); // check if the game is start
        void stop() const; // stop the game, we have a winner
        void check_MaxPlayer(); // check if we have a maximum players
    };
}