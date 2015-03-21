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

	double getMaxSpeed();
	double getMaxAcceleration();
	double getMass();

	//-------------------- Setters -----------------------
	
	void setOrientation(Orientation orientation);
	void setVelocity(glm::vec2 velocity);

	//------------------- Movement -----------------------

    void move(glm::vec2 gravity, int time);
};

#endif //_DYNAMICOBJECT_H