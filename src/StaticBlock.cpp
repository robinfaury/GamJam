/**
* StaticBlock : block of the world inable to move, inherits from WorldObject
*/


#include "StaticBlock.h"

/**
 * StaticBlock implementation
 */

//------------------ Constructors --------------------

StaticBlock::StaticBlock()
{
	this->type = 1;
}
StaticBlock::StaticBlock(int type)
{
	this->type = type;
}

StaticBlock::StaticBlock(glm::vec2 position, glm::vec2 size, int type) : WorldObject(position, size)
{
	this->type = type;
}

//-------------------- Getters -----------------------

int StaticBlock::getType()
{
	return type;
}

//-------------------- Setters -----------------------

void StaticBlock::setType(int type)
{
	this->type = type;
};

