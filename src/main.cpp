#include "Game.h"

int main(int argc, char* argv[])
{

	Parser p = Parser();
	p.loadLevel("../GamJam/res/sauvegarde.txt");
	
	p.saveLevel("../GamJam/res/sauvegarde2.txt");
	std::cin.get();

	Game boobs;
	boobs.changeLevel();
	boobs.run();


	return 0;
} 
