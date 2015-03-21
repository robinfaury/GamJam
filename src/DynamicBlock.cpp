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
}

DynamicBlock::DynamicBlock(int type) : DynamicObject()
{
	this->type = type;
}

DynamicBlock::DynamicBlock(glm::vec2 position, glm::vec2 size, Orientation orientation, int type) : DynamicObject(position, size, orientation)
{
	this->type = type;
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