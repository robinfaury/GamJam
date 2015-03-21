#include "Game.h"
#include <SFML/Audio.hpp>
#include "InfoBull.h"
int main(int argc, char* argv[])
{

	sf::Music music;
	if (!music.openFromFile("../GamJam/res/music.ogg"))
		std::cout << "fail";
	
		music.play();
	
		music.setLoop(true);

		std::cin.get();

		Game boobs;
		boobs.init();
		boobs.run();


	return 0;
} 
