/**
 * Project Untitled
 */


#ifndef _MAP_H
#define _MAP_H

#include <iostream>

class Map 
{
private:
	int** grid;
    int height;
    int width;

public: 
    
	Map(void);

	Map(int h,int w, int** g);

	~Map(void);
    
    void load();
    
    void save();
};

#endif //_MAP_H