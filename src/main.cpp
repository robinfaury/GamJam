#include "Game.h"
#include <SFML/Audio.hpp>
#include <iostream>
int main(int argc, char* argv[])
{
	sf::Music music;
	if (!music.openFromFile("../GamJam/res/music.ogg"))
		std::cout << "fail";

	music.play();

	music.setLoop(true);

	Game boobs;
	boobs.init(1);
	boobs.run();
	
	while (1){
	std::cout << std::endl;
	std::cout << "Entrez le numéro du niveau voulu" << std::endl;
	char nb[1];
    std::cin.getline(nb, 3);
	std::string c = nb;
	int nbb = atoi(c.c_str());
	
	Game boobs2;
	boobs2.init(nbb);
	boobs2.run();
	}
	return 0;
} 
