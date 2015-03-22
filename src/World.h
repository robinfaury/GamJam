/**
 * Project Untitled
 */

#include "Map.h"
#include "Player.h"
#include "DynamicBlock.h"

#ifndef _WORLD_H
#define _WORLD_H

class World 
{
private:
	Map map;
	Player player;
	std::vector<DynamicBlock> worldObject;

public: 
	World();

	void ChargeLevel(int i);
	void SaveLevel();
	int getNbFrame(int type);

	Map* getMap() {return &this->map;}
	Player* getPlayer() {return &this->player;}
	std::vector<DynamicBlock>* getWorldObjects() {return &this->worldObject;}
    
    void MoveBlock();
};

#endif //_WORLD_H