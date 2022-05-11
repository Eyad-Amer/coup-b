/**
 * Heading for the Contessa Role
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
    class Contessa : public Player
    {
        public:
            Contessa(Game &game, string name); // constructor
            static string role(); // get the role of the player
            void block(Player &player); // block the player that has a assassin role
    };
}