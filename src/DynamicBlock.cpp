/**
* DynamicBlock : block of the world able to move, inherits from DynamicObject
*/

#include "DynamicBlock.h"

/**
 * DynamicBlock implementation
 */

//------------------ Constructors --------------------

DynamicBlock::DynamicBlock() : DynamicObject()
{
	this->type = 0;
	this->currentIDPlayer = 0;
}

DynamicBlock::DynamicBlock(int type) : DynamicObject()
{
	this->type = type;
}

DynamicBlock::DynamicBlock(glm::vec2 position, glm::vec2 size, Orientation orientation, int type) : DynamicObject(position, size, orientation)
{
	this->type = type;
}

void DynamicBlock::init(int nbFrame)
{
	this->blocTextureAnim.clear();
	for (int i=0; i<nbFrame; ++i)
	{
		std::string filename("../GamJam/res/textures/blocs/bloc");
		if (this->type<10)
			filename += "0";
		else
			filename += "";
		filename += std::to_string(this->type);
		if (nbFrame > 1)
			filename += "_"+std::to_string(i+1);
		filename +=  + ".png";
		this->blocTextureAnim.push_back(sf::Texture());
		if (!this->blocTextureAnim[this->blocTextureAnim.size()-1].loadFromFile(filename))
			std::cout<<"ERROR : "<<filename<<std::to_string(i)<<" isn't loaded"<<std::endl;
	}
	this->bloc.setTexture(this->blocTextureAnim[0]);
	this->bloc.setPosition(this->position.x, this->position.y);

	this->direction = glm::vec2(0, 0);
}

void DynamicBlock::draw(int time)
{
	if (time%7==0)
	{
		this->currentIDPlayer = ++this->currentIDPlayer%this->blocTextureAnim.size();
		this->bloc.setTexture(this->blocTextureAnim[this->currentIDPlayer]);
	}
	this->bloc.setPosition(this->position.x, this->position.y);
}

//-------------------- Getters -----------------------

int DynamicBlock::getType()
{
	return type;
}

//-------------------- Setters -----------------------

void DynamicBlock::setType(int type)
{
	this->type = type;
}