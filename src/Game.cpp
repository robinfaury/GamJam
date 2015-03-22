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
	this->SFMLView.Init(this->world.getMap()->getheight()*30, this->world.getMap()->getwidth()*30);
	this->world.getPlayer()->init();
	for (int i=0; i<this->world.getWorldObjects()->size(); ++i)
		this->world.getWorldObjects()->at(i).init(this->world.getNbFrame(this->world.getWorldObjects()->at(i).getType()));
}

void Game::changeLevel(int i)
{
	this->world.ChargeLevel(i);
}

void Game::run()
{
	int eventID = 0;
	while(eventID != -1)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		eventID = this->SFMLView.computeEvent();
		this->world.getPlayer()->move();
		this->Physique();
		this->SFMLView.Draw();

		auto end_time = std::chrono::high_resolution_clock::now();
		//std::cout <<"frame time : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;
	}
}

void Game::Physique()
{
	if (this->SFMLView.isPlay())
	{
		Player* player = this->world.getPlayer();

		int i = player->getPosition().x/30, j = player->getPosition().y/30;
		std::cout<<i<<j<<this->world.getMap()->getgrid()[j][i]<<"|";
		if (this->world.getMap()->getgrid()[j][i] == 0)
		{
			player->setPosition(player->getPosition()+glm::vec2(0.5, 1));
		}
		if (this->world.getMap()->getgrid()[j][i] == 13)
		{
			player->setPosition(player->getPosition()+glm::vec2(0, 1));
			std::cout<<"DEAD";
		}
		if (this->world.getMap()->getgrid()[j][i] == 1 || this->world.getMap()->getgrid()[j][i] == 5)
		{
			player->setPosition(player->getPosition()+glm::vec2(2, 0));
		}
	}
}

Game::~Game()
{

}