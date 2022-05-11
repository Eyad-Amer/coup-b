/**
 * Game function
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

const int MaxPlayer = 6;

using namespace std;
namespace coup
{
    // constructor
    Game::Game()
    {
        this->numOfPlayers = 0;
        this->index = 0;
        GameStart = false;
    }

    // the function returns the name of the players in the game
    vector<string> Game::players()
    {
        vector<string> NamesOfPlayers;
        for (Player *player : get_Players)
        {
            if (player->playerAlive)
            {
                NamesOfPlayers.push_back(player->PlayerName);
            }
        }
        return NamesOfPlayers;
    }

    // name the player that his turn
    string Game::turn()
    {
        return this->get_Players.at(this->index)->PlayerName;
    }

    // the function returns the name of the winner
    string coup::Game::Game::winner()
    {
        if (!GameStart || numOfPlayers != 1)
        {
            throw runtime_error("no one is winner");
        }
        
        return this->players().at(0);
    }

    // add players to the game
    void Game::addPlayers(Player *player)
    {
        check_MaxPlayer();
        if (!GameStart)
        {
            // this->playerslist.push_back(player->PlayerName);
            this->get_Players.push_back(player);
            this->numOfPlayers++;
        }
        else
        {
            throw runtime_error("can not add a players");
        }
    }

    // check if we have a maximum players
    void Game::check_MaxPlayer()
    {
        if (get_Players.size() == MaxPlayer)
        {
            throw runtime_error("maximum players");
        }
    }

    // check if the game is start
    bool Game::start_Game() 
    {
        if (!GameStart)
        {
            GameStart = true;
        }
        return GameStart;
    }

    // next turn
    void Game::nextTurn() 
    {
        this->index = (this->index + 1) % this->get_Players.size();
        while (!this->get_Players.at(this->index)->playerAlive)
        {
            stop();
            this->index = (this->index + 1) % this->get_Players.size();
        }
        start_Game();
    }

    // stop the game, we have a winner
    void Game::stop() const
    {
        if (this->numOfPlayers == 1)
        {
            GameStart = false;
            throw runtime_error("we have only one player");
        }
    }

    // check if the game is finshed
    void Game::check_gamefinsh() 
    {
        if (!GameStart)
        {
            throw runtime_error("the game is noy begin");
        }
    }

    // check if the game is start
    void Game::check_gamestart() 
    {
        if (GameStart)
        {
            throw runtime_error("the game is begin");
        }
    }
}