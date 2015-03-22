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
	int level;
	int gender; // 0 for Male, 1 for Female
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
	void run(int time);
	void stop();

	//-------------------- Getters -----------------------

	double getLife();
	double getExperience();
	int getLevel();
	int getGender();
	sf::Sprite* getPlayerSprite() {return &this->player;}

	//-------------------- Setters -----------------------

	void setLife(double life);
	void setExperience(double experience);
	void setLevel(int level);
	void setGender(int gender);

	//------------------ State Changes -------------------

	void earnExperience(double experience);
	void regainLife(double lifeHeal);
	void loseLife(double lifeDamage);
};

#endif //_PLAYER_H