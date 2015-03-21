/**
 * Project Untitled
 */


#include "Map.h"

/**
 * Map implementation
 */

Map::Map(void){

}

Map::Map(int h, int w, int** g)
{
	height = h;
	width = w;

	grid = new int*[height];
	for (int i = 0; i < height; i++)
		grid[i] = new int[width];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			grid[i][j] = g[i][j];
		}
	}

}

Map::~Map(void){

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