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
#include <chrono>

#include "World.h"
#include "Event.h"
#include "Player.h"
#include "Button.h"

class GraphicView 
{
private:
	World* world;
	sf::RenderWindow* window;
	Event event;
	bool editor;
	bool play;
	sf::Texture lateralTexture;
	sf::Sprite lateral;
	sf::Texture hautTexture;
	sf::Sprite haut;
	sf::Texture textureBackground;
	sf::Sprite background;
	sf::Sprite currentSprite;
	int currentIDTexture;
	
	std::vector<Button> buttons;

	int time;

	std::vector<sf::Texture> blocTextures;
	std::vector<sf::Sprite> sprites;

public:
	GraphicView(){}
	GraphicView(World* world);

	void Init(int height, int width);
	int computeEvent();
	void Draw();

	sf::RenderWindow* getWindow() {return this->window;}

	void setModeEdition(bool state) {this->editor = state;}
	bool isPlay() {return this->play;}

	~GraphicView();
};

#endif //_GRAPHICVIEW_H