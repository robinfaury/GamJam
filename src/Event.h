/**
 * Project Untitled
 */


#ifndef _EVENT_H
#define _EVENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Event 
{
private:
	sf::Event event;
	sf::RenderWindow* window;

	bool clics[3][2];


public:
	Event();
	Event(sf::RenderWindow* window);

	int CheckEvent();

	~Event();
};

#endif //_EVENT_H