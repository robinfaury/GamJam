/**
 * DynamicBlock : block of the world able to move, inherits from DynamicObject
 */

#ifndef _DYNAMICBLOCK_H
#define _DYNAMICBLOCK_H

#include "DynamicObject.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

class DynamicBlock: public DynamicObject 
{

private:

	int type;
	std::vector<sf::Texture> blocTextureAnim;
	sf::Sprite bloc;
	int currentIDPlayer;

public:

	//------------------ Constructors --------------------

	DynamicBlock();
	DynamicBlock(int type);
	DynamicBlock(glm::vec2 position, glm::vec2 size, Orientation orientation, int type);

	void init(int nbFrame);
	void draw(int time);

	//-------------------- Getters -----------------------

	int getType();
	sf::Sprite* getSprite() {return &this->bloc;}

	//-------------------- Setters -----------------------

	void setType(int type);
};

#endif //_DYNAMICBLOCK_H