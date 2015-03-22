/**
 * Project Untitled
 */


#include "Event.h"

/**
 * Event implementation
 */

Event::Event()
{

}

Event::Event(sf::RenderWindow* window)
{
	this->window = window;
}


int Event::CheckEvent()
{

    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
		{
            this->window->close();
			return -1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
			return 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			return 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			return 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			return 3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			return 4;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			return 5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
			return 6;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
			return 7;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
			return 8;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
			return 9;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			return 10;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			return 11;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			return 12;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
			return 13;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			return 14;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
			return 15;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			return 16;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			return 17;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			return 18;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			return 19;
    }
	return -2;
}

Event::~Event()
{

}