/**
 * Project Untitled
 */


#ifndef _BUTTON_H
#define _BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <iostream>


class Button 
{ 
private:
	int x, y,hauteur,largeur,id;
	std::string nom;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	
	Button();
	Button(int x, int y);
	~Button();
	int verif(int, int);
	void setImage(std::string path);

	sf::Sprite* getSprite() {return &this->sprite;}

};

#endif //_BUTTON_H