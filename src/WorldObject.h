/**
 * Project Untitled
 */


#ifndef _WORLDOBJECT_H
#define _WORLDOBJECT_H

#include <glm.hpp>

class WorldObject 
{
private: 
    glm::vec2 position;
    glm::vec2 size;

public:
	glm::vec2 getPosition();
};

#endif //_WORLDOBJECT_H