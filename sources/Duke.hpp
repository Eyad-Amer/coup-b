/**
 * Heading for the Duke Role
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

using namespace std;

namespace coup
{
    class Duke : public Player
    {
        public:
            Duke(Game &game, const string &name); // constructor
            static string role(); // get the role of the player
            void tax(); // tax 3 Coins from the cash register
            void block(Player &player); // block the player that has a foreigen_aid
    };
}