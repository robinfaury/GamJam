/**
 * Project Untitled
 */


#include "Button.h"

/**
 * Button implementation
 */ 

Button::Button(int a, int b)
{
	x = a;
	y = b;
}

void Button::setImage(std::string path)
{


	if (!this->texture.loadFromFile( path ))
	{
	}
	sprite.setTexture(texture);
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