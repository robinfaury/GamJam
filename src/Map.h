/**
 * Project Untitled
 */


#ifndef _MAP_H
#define _MAP_H

class Map 
{
private:
	int** grid;
    int height;
    int width;

public: 
    
    
    void load();
    
    void save();
};

#endif //_MAP_H