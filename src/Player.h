/**
 * Player: AI player moving forward in the world, helped by the human player to reach the end of the level, inherits from DynamicObject
 **/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "DynamicObject.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>


class Player: public DynamicObject 
{
private:
	double life;
	double experience;
	bool dead;
	bool win;
	int level;
	int gender; // 0 for Male, 1 for Female
	int direction; // 0 for Left, 1 for Right
	int fallsCounter;
	std::vector<sf::Texture> playerTextureAnim;
	sf::Texture playerTexture;
	sf::Sprite player;
	int currentIDPlayer;

public:

	//------------------ Constructors --------------------

	Player();
	Player(int gender);
	Player(glm::vec2 position, glm::vec2 size, Orientation orientation, int gender);

	void init();
	void initTextures();
	void run(int time);
	void stop();

	//-------------------- Getters -----------------------

	double getLife();
	double getExperience();
	int getLevel();
	int getGender();
	int getDirection();
	bool getDead();
	bool getWin();
	int getFallsCounter();
	sf::Sprite* getPlayerSprite() {return &this->player;}

	//-------------------- Setters -----------------------

	void setLife(double life);
	void setExperience(double experience);
	void setLevel(int level);
	void setGender(int gender);
	void setDirection(int direction);
	void setDead(bool dead);
	void setFallsCounter(int fallsCounter);
	void setWin(bool win);

	//------------------ State Changes -------------------

	void earnExperience(double experience);
	void regainLife(double lifeHeal);
	void loseLife(double lifeDamage);
	void changeDirection();
	void incFallsCounter();
};

#endif //_PLAYER_H