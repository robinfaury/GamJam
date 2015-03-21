/**
* DynamicObject: Abstract class for dynamic objects of the world, inherited by Player and DynamicBlock
*/


#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "WorldObject.h"
#include "Orientation.h"

class DynamicObject : public WorldObject 
{

protected:

	Orientation orientation;
	glm::vec2 velocity;
	glm::vec2 acceleration;
	glm::vec2 direction;
	glm::vec2 rotation;

	double maxSpeed;
	double maxAcceleration;
	double mass;

public:
    
	//------------------ Constructors --------------------

	DynamicObject();
	DynamicObject(glm::vec2 position, glm::vec2 size, Orientation orientation);

	//-------------------- Getters -----------------------

	Orientation getOrientation();
	glm::vec2 getVelocity();
	glm::vec2 getAcceleration();
	glm::vec2 getDirection();
	glm::vec2 getRotation();

	double getMaxSpeed();
	double getMaxAcceleration();
	double getMass();

	//-------------------- Setters -----------------------
	
	void setOrientation(Orientation orientation);
	void setVelocity(glm::vec2 velocity);
	void setAcceleration(glm::vec2 acceleration);
	void setDirection(glm::vec2 direction);
	void setRotation(glm::vec2 rotation);

	void setMaxSpeed(double maxSpeed);
	void setMaxAcceleration(double maxAcceleration);
	void setMass(double mass);

	//------------------- Movement -----------------------

    void move(glm::vec2 gravity, int time);
};

#endif //_DYNAMICOBJECT_H