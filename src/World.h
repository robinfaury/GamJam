/**
 * Project Untitled
 */

#include "Map.h"

#ifndef _WORLD_H
#define _WORLD_H

class World 
{
private:
	Map map;

public: 
	World();

	void ChargeLevel(int i);

	Map* getMap() {return &this->map;}
    
    void MoveBlock();
};

#endif //_WORLD_H