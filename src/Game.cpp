/**
 * Project Untitled
 */


#include "Game.h"

/**
 * Game implementation
 */

Game::Game()
{
	this->SFMLView.Init(30*30, 30*30);
}

void Game::changeLevel(int i)
{
	std::string filename("../GamJam/res/maps/level");
	filename += (i<10)? "0" : "";
	filename += std::to_string(i) + ".txt";
	p.loadLevel(filename);
}

void Game::run()
{
	int eventID = 0;
	while(eventID != 1)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		eventID = this->SFMLView.CheckEvent();

		this->SFMLView.Draw();

		auto end_time = std::chrono::high_resolution_clock::now();
		std::cout <<"frame time : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;
	}
}

Game::~Game()
{

}