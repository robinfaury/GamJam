#include "Game.h"
#include <iostream>
#include"Parser.h"

int main(int argc, char* argv[])
{
	Game boobs;
	boobs.CreateWorld();
	boobs.Run();
	Parser p = Parser();
	p.loadLevel("../GamJam/res/sauvegarde.txt");
	std::cin.get();

	return 0;
} 
