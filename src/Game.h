/**
 * Project Untitled
 */
#ifndef _GAME_H
#define _GAME_H

#include <chrono>

#include "GraphicView.h"

class Game 
{
private: 
	GraphicView SFMLView;
    bool editor;

public:
	Game();

	void CreateWorld();
	void Run();

	~Game();
};

#endif //_GAME_H