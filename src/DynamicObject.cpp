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

glm::vec2 DynamicObject::getAcceleration()
{
	return acceleration;
}

glm::vec2 DynamicObject::getDirection()
{
	return direction;
}

glm::vec2 DynamicObject::getRotation()
{
	return rotation;
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

void DynamicObject::setAcceleration(glm::vec2 acceleration)
{
	this->acceleration = acceleration;
}

void DynamicObject::setDirection(glm::vec2 direction)
{
	this->direction = direction;
}

void DynamicObject::setRotation(glm::vec2 rotation)
{
	this->rotation = rotation;
}


void DynamicObject::setMaxSpeed(double maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

void DynamicObject::setMaxAcceleration(double maxAcceleration)
{
	this->maxAcceleration = maxAcceleration;
}

void DynamicObject::setMass(double mass)
{
	this->mass = mass;
}

//------------------- Movement -----------------------

void DynamicObject::move() 
{
	this->position.x += this->direction.x;
	this->position.y += this->direction.y;
}