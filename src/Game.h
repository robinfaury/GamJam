/**
 * Project Untitled
 */
#ifndef _GAME_H
#define _GAME_H

#include <chrono>

#include "GraphicView.h"
#include "World.h"
#include "Event.h"

class Game 
{
private: 
	GraphicView SFMLView;
	Event event;

	World world;
    bool editor;

public:
	Game();

	void init();
	void changeLevel(int i);
	void run();

	~Game();
};

#endif //_GAME_H