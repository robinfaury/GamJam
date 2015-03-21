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
		
		InfoBull("boobs");
	
		std::cin.get();

	return 0;
} 
