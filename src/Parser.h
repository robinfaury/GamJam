/**
 * Project Untitled
 */


#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include "Map.h"

class Parser {
private :
	Map m;
public: 
    
	Parser(void);

	~Parser(void);

	void setMap(Map);
	

    /**
     * @param string
     */
    void loadLevel( std::string);
    
    /**
     * @param string
     */
    void saveLevel( std::string);
};

#endif //_PARSER_H