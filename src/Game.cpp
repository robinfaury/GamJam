/**
 * Project Untitled
 */


#include "Game.h"

/**
 * Game implementation
 */

Game::Game()
{
	this->SFMLView = GraphicView(&this->world);
}

void Game::init()
{
	this->changeLevel(1);
	this->SFMLView.Init(30*30, 30*30);
	this->event = Event(this->SFMLView.getWindow());
}

void Game::changeLevel(int i)
{
	this->world.ChargeLevel(i);
}

void Game::run()
{
	int eventID = 0;
	while(eventID != 1)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		eventID = this->event.CheckEvent();

		this->SFMLView.Draw();

		auto end_time = std::chrono::high_resolution_clock::now();
		std::cout <<"frame time : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;
	}
}

Game::~Game()
{

}