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
}

Player::Player(glm::vec2 position, glm::vec2 size, Orientation orientation) : DynamicObject(position, size, orientation)
{
	life = 1.0f;
	experience = 0.0f;
	level = 0;
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