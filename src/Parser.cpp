/**
 * Project Untitled
 */


#include "Parser.h"

/**
 * Parser implementation
 */


/**
 * @param string
 * @return void
 */

Parser::Parser(void)
{

}

Parser::~Parser(void)
{

}



void Parser::loadLevel( std::string path, int*** arr, int* height, int*width) 
{
	
	std::ifstream fichier(path.c_str(), std::ios::in);
	

	if (fichier)
	{
		fichier >> *height >> *width;

		//allocate the array
		*arr = new int*[*width];
		for (int i = 0; i < *width; i++)
			(*arr)[i] = new int[*height];

		
		for (int x = 0; x < *width; x++)
		{
			for (int y = 0; y < *height; y++)
			{
				int tmp;
				fichier >> tmp;
				(*arr)[x][y] = tmp;
			}
		}

		fichier.close();

	}
	else
		std::cout << "Impossible d'ouvrir le level" << std::endl;
    
}

/**
 * @param string
 * @return void
 */
void Parser::saveLevel( std::string path, int** grid, int height, int width) 
{

	std::ofstream fichier(path.c_str(), std::ios::out | std::ios::trunc);

	if (fichier)
	{
		fichier << height << " " << width << std::endl;
		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; y++)
			{
				fichier << grid[x][y] << " ";
			}
			fichier << std::endl;
		}
	}
	
}