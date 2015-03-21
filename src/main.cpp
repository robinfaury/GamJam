#include "Game.h"
#include <SFML/Audio.hpp>

int main(int argc, char* argv[])
{

	sf::Music music;
	if (!music.openFromFile("../GamJam/res/music.ogg"))
		std::cout << "fail";

	music.play();

	
	Game boobs;
	boobs.changeLevel(1);
	boobs.run();

	return 0;
} 
