#include "Game.h"
#include <SFML/Audio.hpp>

int main(int argc, char* argv[])
{
	sf::Music music;
	if (!music.openFromFile("../GamJam/res/music.ogg"))
		std::cout << "fail";

	music.play();

	Parser p = Parser();
	p.loadLevel("../GamJam/res/sauvegarde.txt");
	
	p.saveLevel("../GamJam/res/sauvegarde2.txt");
	std::cin.get();

	Game boobs;
	boobs.changeLevel();
	boobs.run();


	return 0;
} 
