/**
* DynamicObject: Abstract class for dynamic objects of the world, inherits from WorldObject and inherited by Player and DynamicBlock
*/


#include "DynamicObject.h"

/**
 * DynamicObject implementation
 */

//------------------ Constructors --------------------

DynamicObject::DynamicObject() : WorldObject()
{
	this->orientation = DOWN;
}

DynamicObject::DynamicObject(glm::vec2 position, glm::vec2 size, Orientation orientation) : WorldObject(position, size)
{
	this->orientation = orientation;
}

//-------------------- Getters -----------------------

Orientation DynamicObject::getOrientation()
{
	return orientation;
}

glm::vec2 DynamicObject::getVelocity()
{
	return velocity;
}

double DynamicObject::getMaxSpeed()
{
	return maxSpeed;
}

double DynamicObject::getMaxAcceleration()
{
	return maxAcceleration;
}

double DynamicObject::getMass()
{
	return mass;
}

//-------------------- Setters -----------------------

void DynamicObject::setOrientation(Orientation orientation)
{
	this->orientation = orientation;
}

void DynamicObject::setVelocity(glm::vec2 velocity)
{
	this->velocity = velocity;
}

//------------------- Movement -----------------------

void DynamicObject::move(glm::vec2 gravity, int time) 
{
	/*
	position += time * velocity;
	velocity += acceleration * time;
	if (acceleration > maxAcceleration)
	{

	}
	if (velocity > maxSpeed)
	{

	}
	*/
}