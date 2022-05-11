/**
 * Heading for the Assassin Role
 * 
 * Author: Eyad Amer
 * Since : 2022-05
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Player.hpp"
#include"Game.hpp"

using namespace std;

namespace coup
{
    class Assassin: public Player
    {
        public:
            Assassin(Game &game, string name); // constructor
            static string role(); // get the role of the player
            void coup(Player &player); // to kill the player
            void check_3coins(); // check if the player have 3 or more coins
    };
}