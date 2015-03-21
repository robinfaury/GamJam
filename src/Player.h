/**
 * Player: AI player moving forward in the world, helped by the human player to reach the end of the level, inherits from DynamicObject
 **/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "DynamicObject.h"


class Player: public DynamicObject 
{
private:
	double life;
	double experience;
	int level;

public:

	//------------------ Constructors --------------------

	Player();
	Player(glm::vec2 position, glm::vec2 size, Orientation orientation);

	//-------------------- Getters -----------------------

	double getLife();
	double getExperience();
	int getLevel();

	//-------------------- Setters -----------------------

	void setLife(double life);
	void setExperience(double experience);
	void setLevel(int level);

	//------------------ State Changes -------------------

	void earnExperience(double experience);
	void regainLife(double lifeHeal);
	void loseLife(double lifeDamage);
};

#endif //_PLAYER_H