/**
* WorldObject: Abstract class for objects of the world, inherited by DynamicObject and StaticObject
*/


#include "WorldObject.h"

/**
 * WorldObject implementation
 */

//------------------ Constructors --------------------

WorldObject::WorldObject()
{
	position = glm::vec2(0, 0);
	size = glm::vec2(1, 1);
}

WorldObject::WorldObject(glm::vec2 position, glm::vec2 size)
{
	this->position = position;
	this->size = size;
}

//-------------------- Getters -----------------------

glm::vec2 WorldObject::getPosition()
{
	return position;
}

glm::vec2 WorldObject::getSize()
{
	return size;
}

//-------------------- Setters -----------------------

void WorldObject::setPosition(glm::vec2 position)
{
	this->position = position;
}

void WorldObject::setSize(glm::vec2 size)
{
	this->size = size;
}

