/**
 * Project Untitled
 */


#include "Button.h"

/**
 * Button implementation
 */ 

Button::Button(int a, int b, int c, int d, std::string path,int idd){
	x = a;
	y = b;
	hauteur = c;
	largeur = d;
	nom = path;
	id = idd;

	sf::Texture Image;
	sf::Sprite Sprite;


	if (!Image.loadFromFile(path+".png"))
	{
		// Erreur...
	}
	Image.setSmooth(true);
	Sprite.setTexture(Image);
}

void Button::setImage(std::string path){
	sf::Texture Image;
	sf::Sprite Sprite;


	if (!Image.loadFromFile( nom+path  + ".png"))
	{
		// Erreur...
	}
	Image.setSmooth(true);
	Sprite.setTexture(Image);
}

Button::Button(void)
{
	
}

Button::~Button(void){

}
int Button::verif(int x2, int y2) {
	if (x2 >= x && x2 <= x + largeur && y2 >= y && y2 <= y + hauteur)
		return 1;
	
	return 0;
}