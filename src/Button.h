/**
 * Project Untitled
 */


#ifndef _BUTTON_H
#define _BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <iostream>


class Button { 
private:
	int x, y,hauteur,largeur,id;
	std::string nom;

public:
	
	Button();
	Button(int, int, int, int, std::string,int);
	~Button();
	int verif(int, int);
	void setImage(std::string path);
};

#endif //_BUTTON_H