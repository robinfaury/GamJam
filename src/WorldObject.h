/**
 * WorldObject: Abstract class for objects of the world, inherited by DynamicObject and StaticObject
 */


#ifndef _WORLDOBJECT_H
#define _WORLDOBJECT_H

#include <glm.hpp>

class WorldObject 
{

protected: 

    glm::vec2 position;
    glm::vec2 size;
	
public:

	//------------------ Constructors --------------------

	WorldObject();
	WorldObject(glm::vec2 position, glm::vec2 size);

	//-------------------- Getters -----------------------

	glm::vec2 getPosition();
	glm::vec2 getSize();

	//-------------------- Setters -----------------------

	void setPosition(glm::vec2 position);
	void setSize(glm::vec2 size);

};

#endif //_WORLDOBJECT_H