/**
 * Project Untitled
 */


#include "Map.h"

/**
 * Map implementation
 */

Map::Map(void)
{

}

void Map::loadLevel(int i)
{
	std::string filename("../GamJam/res/maps/level");
	filename += (i<10)? "0" : "";
	filename += std::to_string(i) + ".txt";
	this->parser.loadLevel(filename, &this->grid, &this->height, &this->width);
	this->maxIDTexture = 0;
	for (int x=0; x<this->width; ++x)
		for (int y=0; y<this->height; ++y)
			if (this->grid[x][y] > this->maxIDTexture)
				this->maxIDTexture = this->grid[x][y];
}

Map::~Map(void)
{
	
	//deallocate the array
	for (int i = 0; i < this->width; i++)
		delete[] this->grid[i];
	delete[] this->grid;
}


int Map::getheight()
{
	return (height);
}
int Map::getwidth()
{
	return(width);
}
int** Map::getgrid()
{
	return(grid);
}