/**
 * Project Untitled
 */


#ifndef _BUTTON_H
#define _BUTTON_H

class Button { 
private:
	int x, y,hauteur,largeur;

public:
	
	Button();
	Button(int, int, int, int);
	~Button();
	int verif(int, int);

};

#endif //_BUTTON_H