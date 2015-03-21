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
	int gender; // 0 for Male, 1 for Female

public:

	//------------------ Constructors --------------------

	Player();
	Player(int gender);
	Player(glm::vec2 position, glm::vec2 size, Orientation orientation, int gender);

	//-------------------- Getters -----------------------

	double getLife();
	double getExperience();
	int getLevel();
	int getGender();

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