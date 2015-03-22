/**
 * Project Untitled
 */
#ifndef _GAME_H
#define _GAME_H

#include <chrono>

#include "GraphicView.h"
#include "World.h"


class Game 
{
private: 
	GraphicView SFMLView;

	World world;

public:
	Game();

	void init();
	void changeLevel(int i);
	void run();
	void Physique();
	void detectCollision(glm::vec2 nextPosition);
	void printWorld();

	~Game();
};

#endif //_GAME_H