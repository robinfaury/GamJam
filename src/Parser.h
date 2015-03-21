/**
 * Project Untitled
 */


#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include<fstream>
#include<string>
#include <stdio.h>

class Parser 
{
private :

public: 
    
	Parser(void);

	~Parser(void);
	

    /**
     * @param string
     */
    void loadLevel( std::string, int*** arr, int* height, int* width);
    
    /**
     * @param string
     */
    void saveLevel( std::string, int** arr, int height, int width);
};

#endif //_PARSER_H