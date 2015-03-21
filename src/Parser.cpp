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
	m = Map();
}

Parser::~Parser(void){
	m.~Map();
}

void Parser::loadLevel( std::string path) {
	
	std::ifstream fichier(path.c_str(), std::ios::in);
	
	if (fichier)
	{
		int height,width;
		fichier >> height >> width;
		//allocate the array
		int** arr = new int*[height];
		for (int i = 0; i < height; i++)
			arr[i] = new int[width];

		
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int tmp;
				fichier >> tmp;
				arr[i][j] = tmp;
			}
		}

		m = Map(height, width, arr);

		for (int i = 0; i < height; i++)
			delete[] arr[i];
		delete[] arr;

		fichier.close();

	}
	else
		std::cout << "Impossible d'ouvrir le level" << std::endl;
    
}

/**
 * @param string
 * @return void
 */
void Parser::saveLevel( std::string) {
    return;
}