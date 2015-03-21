/**
 * Project Untitled
 */


#ifndef _MAP_H
#define _MAP_H

#include <iostream>

#include "Parser.h"

class Map 
{
private:
	int** grid;
    int height;
    int width;
	int maxIDTexture;
	Parser parser;

public: 
    
	Map(void);

	void loadLevel(int i);

	~Map(void);

	int getheight();
	int getwidth();
	int** getgrid();
	int getMaxIDTexture() {return this->maxIDTexture;}
	
};

#endif //_MAP_H