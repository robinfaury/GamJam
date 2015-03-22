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
		//TODO:
		// tourner le sprite qd changement de direction
		// sortie de la map haud et bas
		// mort = fin du jeu
		//détecter arrivée drapeau

		Player* player = this->world.getPlayer();

		int i = player->getPosition().x/30, j = (player->getPosition().y - 120)/30;
		int bloc = this->world.getMap()->getgrid()[j][i];
		//std::cout << "x:" << player->getPosition().x << "y:" << player->getPosition().y << "|";
		//std::cout<<"i:"<<i<<"j:"<<j<<"bloc:"<<bloc<<"|";
		bool fall = false;
		if (bloc == 0 || bloc == 2 || bloc == 18) // vide
		{
			player->setPosition(player->getPosition() + glm::vec2(0, 5)); // tombe
			player->incFallsCounter();
			//std::cout << "falls counter:" << player->getFallsCounter() << std::endl;
			fall = true;
		}
		if (bloc == 13 || bloc == 7 || bloc == 8 || bloc == 10 || bloc == 11 || bloc == 14 || bloc == 15 || bloc == 16 || bloc == 19) // feu, lave, eau ou pics
		{ 
			player->setPosition(player->getPosition()+glm::vec2(0, 5)); // tombe et meurt
			player->setDead(true);
			std::cout<<"DEAD";
			fall = true;
		}

		if (!fall)
		{
			if (player->getFallsCounter() > (3 * 30) / 5)
			{
				player->setDead(true);
				std::cout << "-----DEAD--------";
			}
			else
			{
				player->setFallsCounter(0);
				if (bloc == 1 || bloc == 3 || bloc == 5 || bloc == 4 || bloc == 6 || bloc == 9) // terre, herbe, bois, départ ou arrivée
				{
					// avance normalement
					glm::vec2 nextPosition;
					if (player->getDirection() == 1) // right
					{
						nextPosition = player->getPosition() + glm::vec2(3, 0);
					}
					else // left
					{
						nextPosition = player->getPosition() - glm::vec2(3, 0);
					}
					detectCollision(nextPosition);
				}

				if (bloc == 12 || bloc == 17) // neige ou sable
				{
					// avance lentement
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
			}
		}
	}
}

void Game::detectCollision(glm::vec2 nextPosition)
{
	Player* player = this->world.getPlayer();

	int nexti = nextPosition.x / 30;
	int nextj = (nextPosition.y - 120) / 30;
	if (player->getDirection() == 1)
	{
		nexti++;
	}
	nextj--;
	if (nexti < 0 || nexti >= this->world.getMap()->getheight() - 1)
	{
		std::cout << "---------- DEAD SORTIE ------------";
		player->setDead(true);
	}
	else if (nextj < 0 || nextj >= this->world.getMap()->getwidth())
	{
		std::cout << "---------- DEAD SORTIE ------------";
		player->setDead(true);
	}
	else
	{ 
		int nextbloc = this->world.getMap()->getgrid()[nextj][nexti];

		if (nextbloc == 0 || nextbloc == 2 || nextbloc == 18) // vide ou fond de caverne
		{
			player->setPosition(nextPosition); // avance
		}
		else if (nextbloc == 7 || nextbloc == 8 || nextbloc == 13 || nextbloc == 14 || nextbloc == 15 || nextbloc == 16 || nextbloc == 10 || nextbloc == 11 || nextbloc == 19) // eau, feu, lave ou pics 
		{
			player->setPosition(nextPosition); // avance et meurt
			player->setDead(true);
			std::cout << "DEAD";
		}
		else
		{
			// fait demi-tour
			std::cout << "------------------ CHANGE DIR --------------------------";
			player->initTextures();
			player->changeDirection();
		}
	}
}

void Game::printWorld()
{
	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			int bloc = this->world.getMap()->getgrid()[i][j];
			std::cout <<  bloc << " ";
		}
		std::cout << std::endl;
	}
}

Game::~Game()
{

}