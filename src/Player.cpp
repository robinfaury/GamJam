/**
* Player: AI player moving forward in the world, helped by the human player to reach the end of the level, inherits from DynamicObject
**/


#include "Player.h"

/**
 * Player implementation
 */ 

//------------------ Constructors --------------------

Player::Player() : DynamicObject()
{
	life = 1.0f;
	experience = 0.0f;
	level = 0;
	mass = 50;
	maxSpeed = 30;
	maxAcceleration = 10;
	this->player.setOrigin(0, 60);
	this->currentIDPlayer = 0;
}

Player::Player(int gender) : DynamicObject()
{
	life = 1.0f;
	experience = 0.0f;
	level = 0;
	this->gender = gender;
	if (gender == 0)
	{
		mass = 50;
		maxSpeed = 30;
		maxAcceleration = 10;
	}
	else
	{
		mass = 70;
		maxSpeed = 20;
		maxAcceleration = 5;
	}
}

Player::Player(glm::vec2 position, glm::vec2 size, Orientation orientation, int gender) : DynamicObject(position, size, orientation)
{
	life = 1.0f;
	experience = 0.0f;
	level = 0;
	this->gender = gender;
	if (gender == 0)
	{
		mass = 50;
		maxSpeed = 30;
		maxAcceleration = 10;
	}
	else
	{
		mass = 70;
		maxSpeed = 20;
		maxAcceleration = 5;
	}
}

void Player::init()
{
	this->direction = 1;
	this->dead = false;
	this->fallsCounter = 0;
	this->gender = 0;

	initTextures();

	stop();
}

void Player::initTextures()
{
	std::string genderString;
	if (this->direction == 1)
	{
		if (gender == 0)
		{
			for (int i = 1; i<7; ++i)
			{
				std::string filename("../GamJam/res/textures/players/boy/player");
				filename += std::to_string(i + 1) + ".png";
				this->playerTextureAnim.push_back(sf::Texture());
				if (!this->playerTextureAnim[this->playerTextureAnim.size() - 1].loadFromFile(filename))
					std::cout << "ERROR : " << filename << std::to_string(i) << ".png isn't loaded" << std::endl;
			}
			if (!this->playerTexture.loadFromFile("../GamJam/res/textures/players/boy/player1.png"))
				std::cout << "ERROR : " << "../GamJam/res/textures/players/boy/player1.png isn't loaded" << std::endl;
			
		}
		else
		{
			for (int i = 1; i<6; ++i)
			{
				std::string filename("../GamJam/res/textures/players/girl/player");
				filename += std::to_string(i + 1) + ".png";
				this->playerTextureAnim.push_back(sf::Texture());
				if (!this->playerTextureAnim[this->playerTextureAnim.size() - 1].loadFromFile(filename))
					std::cout << "ERROR : " << filename << std::to_string(i) << ".png isn't loaded" << std::endl;
			}
			if (!this->playerTexture.loadFromFile("../GamJam/res/textures/players/girl/player1.png"))
				std::cout << "ERROR : " << "../GamJam/res/textures/players/girl/player1.png isn't loaded" << std::endl;
		}
	}
	else
	{
		if (gender == 0)
		{
			for (int i = 1; i<7; ++i)
			{
				std::string filename("../GamJam/res/textures/players/boy/player");
				filename += std::to_string(i + 1) + "b.png";
				this->playerTextureAnim.push_back(sf::Texture());
				if (!this->playerTextureAnim[this->playerTextureAnim.size() - 1].loadFromFile(filename))
					std::cout << "ERROR : " << filename << std::to_string(i) << ".png isn't loaded" << std::endl;
			}
			if (!this->playerTexture.loadFromFile("../GamJam/res/textures/players/boy/player1.png"))
				std::cout << "ERROR : " << "../GamJam/res/textures/players/boy/player1b.png isn't loaded" << std::endl;

		}
		else
		{
			for (int i = 1; i<6; ++i)
			{
				std::string filename("../GamJam/res/textures/players/girl/player");
				filename += std::to_string(i + 1) + "b.png";
				this->playerTextureAnim.push_back(sf::Texture());
				if (!this->playerTextureAnim[this->playerTextureAnim.size() - 1].loadFromFile(filename))
					std::cout << "ERROR : " << filename << std::to_string(i) << ".png isn't loaded" << std::endl;
			}
			if (!this->playerTexture.loadFromFile("../GamJam/res/textures/players/girl/player1.png"))
				std::cout << "ERROR : " << "../GamJam/res/textures/players/girl/player1b.png isn't loaded" << std::endl;
		}
	}
}
void Player::run(int time)
{
	if (time%7==0)
	{
		this->currentIDPlayer = ++this->currentIDPlayer%this->playerTextureAnim.size();
		this->player.setTexture(this->playerTextureAnim[this->currentIDPlayer]);
	}
	this->player.setPosition(this->position.x, this->position.y);
}

void Player::stop()
{
	this->direction = 1;
	this->player.setTexture(this->playerTexture);
	this->player.setPosition(this->position.x, this->position.y);
}

//-------------------- Getters -----------------------

double Player::getLife()
{
	return life;
}

double Player::getExperience()
{
	return experience;
}

int Player::getLevel()
{
	return level;
}

int Player::getGender()
{
	return gender;
}

int Player::getDirection()
{
	return direction;
}

bool Player::getDead()
{
	return dead;
}

int Player::getFallsCounter()
{
	return fallsCounter;
}

bool Player::getWin()
{
	return win;
}

//-------------------- Setters -----------------------

void Player::setLife(double life)
{
	this->life = life;
}

void Player::setExperience(double experience)
{
	this->experience = experience;
}

void Player::setLevel(int level)
{
	this->level = level;
}

void Player::setGender(int gender)
{
	this->gender = gender;
}

void Player::setDirection(int direction)
{
	this->direction = direction;
}

void Player::setDead(bool dead)
{
	this->dead = dead;
}

void Player::setFallsCounter(int fallsCounter)
{
	this->fallsCounter = fallsCounter;
}

void Player::setWin(bool win)
{
	this->win = win;
}

//------------------ State Changes -------------------

void Player::earnExperience(double experience)
{
	this->experience += experience;
	double overflow = this->experience - 1;
	if (overflow > 0)
	{
		level++;
		this->experience = overflow;
	}
}

void Player::regainLife(double lifeHeal)
{
	life += lifeHeal;
	if (life > 1)
	{
		life = 1;
	}
}
void Player::loseLife(double lifeDamage)
{
	life -= lifeDamage;
	if (life < 0)
	{
		life = 0;
	}
}

void Player::changeDirection()
{
	if (direction == 0)
	{
		direction = 1;
	}
	else
	{
		direction = 0;
	}
}

void Player::incFallsCounter()
{
	this->fallsCounter++;
}