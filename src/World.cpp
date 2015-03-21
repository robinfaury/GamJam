/**
 * Project Untitled
 */


#include "World.h"

/**
 * World implementation
 */

World::World()
{

}

void World::ChargeLevel(int i)
{
	this->map.loadLevel(i);
}

/**
 * @return void
 */
void World::MoveBlock() {
    return;
}

