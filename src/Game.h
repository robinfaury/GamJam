/**
 * Project Untitled
 */
#ifndef _GAME_H
#define _GAME_H

#include <chrono>

#include "GraphicView.h"
#include "Parser.h"

class Game 
{
private: 
	GraphicView SFMLView;
	Parser p;
    bool editor;

public:
	Game();

	void changeLevel(int i);
	void run();

	~Game();
};

#endif //_GAME_H