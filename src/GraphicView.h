/**
 * Project Untitled
 */


#ifndef _GRAPHICVIEW_H
#define _GRAPHICVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "World.h"

class GraphicView 
{
private:
	World* world;
	sf::RenderWindow* window;


	std::vector<sf::Texture> blocTextures;
	std::vector<sf::Sprite> sprites;

public:
	GraphicView(){}
	GraphicView(World* world);

	void Init(int height, int width);
	void Draw();

	sf::RenderWindow* getWindow() {return this->window;}

	~GraphicView();
};

#endif //_GRAPHICVIEW_H