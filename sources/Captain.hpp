/**
 * Heading for the Captain Role
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
    class Captain : public Player
    {
        public:
            Captain(Game &game, string name); // constructor
            static string role(); // get the role of the player
            void block(Player &player); // block the player that has a foreigen_aid
            void steal(Player &player); // steal 2 coins from anther player
    };
}