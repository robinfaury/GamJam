/**
* StaticBlock : block of the world inable to move, inherits from WorldObject
*/


#ifndef _STATICBLOCK_H
#define _STATICBLOCK_H

#include "WorldObject.h"


class StaticBlock: public WorldObject 
{
private:

	int type;

public:

	//------------------ Constructors --------------------

	StaticBlock();
	StaticBlock(int type);
	StaticBlock(glm::vec2 position, glm::vec2 size, int type);

	//-------------------- Getters -----------------------

	int getType();

	//-------------------- Setters -----------------------

	void setType(int type);
};

#endif //_STATICBLOCK_H