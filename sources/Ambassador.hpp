/**
 * Heading for the Ambassador Role
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
    class Ambassador: public Player
    {
        public:
            Ambassador(Game &game, string name); // constructor
            static string role(); // get the role of the player
            void transfer(Player &x, Player &y); // transfer 1 coin from player to player
            void block(Player &player); // block the player that want steal
    };
}
