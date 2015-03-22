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
	//std::cin.get();
	for (int x=0; x<map.getwidth(); ++x)
	{
		for (int y=0; y<map.getheight(); ++y)
			std::cout<<map.getgrid()[x][y];
		std::cout<<std::endl;
	}
	for (int x=0; x<map.getwidth(); ++x)
	{
		for (int y=0; y<map.getheight(); ++y)
		{
			this->worldObject.push_back(DynamicBlock());
			this->worldObject[this->worldObject.size()-1].setType(map.getgrid()[x][y]);
			this->worldObject[this->worldObject.size()-1].setPosition(glm::vec2(y*30, 120+x*30));
			if (map.getgrid()[x][y] == 5)
				player.setPosition(glm::vec2(y*30, 120+x*30));
		}
	}
}

int World::getNbFrame(int type)
{
	if (type == 13)
		return 3;
	if (type == 15)
		return 10;
	if (type == 16)
		return 10;
	if (type == 19)
		return 3;
	return 1;
}

void World::SaveLevel()
{
	this->map.saveLevel();
}

/**
 * @return void
 */
void World::MoveBlock() {
    return;
}

