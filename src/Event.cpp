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
			return 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			return 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			return 3;
		}
    }
	return 0;
}

Event::~Event()
{

}