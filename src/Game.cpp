/**
 * Project Untitled
 */


#include "Game.h"

/**
 * Game implementation
 */

Game::Game()
{
	this->SFMLView = GraphicView(&this->world/*,this*/);
}

void Game::init(int i)
{
	this->changeLevel(i);
	this->SFMLView.Init(0, 0);
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
	while (eventID != -1 && SFMLView.getsortir()==0)
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
		int bloc = this->world.getMap()->getgrid()[j][i];
		std::cout<<i<<j<<bloc<<"|";
		if (bloc == 0) // vide
		{
			player->setPosition(player->getPosition() + glm::vec2(0, 1)); // tombe
		}
		if (bloc == 13 || bloc == 7 || bloc == 8 || bloc == 10 || bloc == 11 || bloc == 14 || bloc == 15 || bloc == 16 || bloc == 19) // feu, lave, eau ou pics
		{ 
			player->setPosition(player->getPosition()+glm::vec2(0, 1)); // tombe et meurt
			std::cout<<"DEAD";
		}
		if (bloc == 1 || bloc == 5 || bloc == 4) // terre, herbe ou départ
		{
			// avance normalement
			glm::vec2 nextPosition;
			if (player->getDirection() == 1) // right
			{
				nextPosition = player->getPosition() + glm::vec2(2, 0);
			}
			else // left
			{
				nextPosition = player->getPosition() - glm::vec2(2, 0);
			}
			detectCollision(nextPosition);
		}

		if (bloc == 12 || bloc == 17) // neige ou sable
		{
			// avance lentement
			glm::vec2 nextPosition;
			if (player->getDirection() == 1) // right
			{
				nextPosition = player->getPosition() + glm::vec2(1, 0);
			}
			else // left
			{
				nextPosition = player->getPosition() - glm::vec2(1, 0);
			}
			detectCollision(nextPosition);
		}
	}
}

void Game::detectCollision(glm::vec2 nextPosition)
{
	Player* player = this->world.getPlayer();

	int nexti = nextPosition.x / 30;
	int nextj = nextPosition.y / 30;
	nexti--;
	int nextbloc = this->world.getMap()->getgrid()[nextj][nexti];

	if (nextbloc == 0 || nextbloc == 2 || nextbloc == 18) // vide ou fond de caverne
	{
		player->setPosition(nextPosition); // avance
	}
	else if (nextbloc == 7 || nextbloc == 8 || nextbloc == 13 || nextbloc == 14 || nextbloc == 15 || nextbloc == 16 || nextbloc == 10 || nextbloc == 11 || nextbloc == 19) // eau, feu, lave ou pics 
	{
		player->setPosition(nextPosition); // avance et meurt
		std::cout << "DEAD";
	}
	else
	{
		// fait demi-tour
		player->changeDirection();
	}
}

Game::~Game()
{

}