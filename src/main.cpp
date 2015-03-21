#include "Game.h"
#include <SFML/Audio.hpp>

int main(int argc, char* argv[])
{

	sf::Music music;
	if (!music.openFromFile("../GamJam/res/music.ogg"))
		std::cout << "fail";
	
		music.play();
	
		music.setLoop(true);
	

	
	Game boobs;
	boobs.init();
	boobs.run();

	return 0;
} 
