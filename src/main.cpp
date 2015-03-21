#include "Game.h"
#include "Player.h"
#include <SFML/Audio.hpp>

int main(int argc, char* argv[])
{

	/*sf::Music music;
	if (!music.openFromFile("../GamJam/res/music.ogg"))
		std::cout << "fail";
	
		music.play();
	
		music.setLoop(true);
	
	*/

	Game boobs;
	boobs.init();
	boobs.run();

	/*Player p = Player();
	p.setDirection(glm::vec2(1, 0));
	p.setVelocity(glm::vec2(5, 0));
	p.setAcceleration(glm::vec2(2, 0));
	p.setPosition(glm::vec2(0, 0));
	std::cout << "position :" <<p.getPosition().x << "," << p.getPosition().y << std::endl;
	p.move(glm::vec2(0, 0), 10);
	std::cout << "position :" << p.getPosition().x << "," << p.getPosition().y << std::endl;
	p.move(glm::vec2(0, 0), 10);
	std::cout << "position :" << p.getPosition().x << "," << p.getPosition().y << std::endl;
	p.move(glm::vec2(0, 0), 10);
	std::cout << "position :" << p.getPosition().x << "," << p.getPosition().y << std::endl;*/

	return 0;
} 
