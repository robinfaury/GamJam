/**
 * DynamicBlock : block of the world able to move, inherits from DynamicObject
 */

#ifndef _DYNAMICBLOCK_H
#define _DYNAMICBLOCK_H

#include "DynamicObject.h"

class DynamicBlock: public DynamicObject 
{

private:

	int type;

public:

	//------------------ Constructors --------------------

	DynamicBlock();
	DynamicBlock(int type);
	DynamicBlock(glm::vec2 position, glm::vec2 size, Orientation orientation, int type);

	//-------------------- Getters -----------------------

	int getType();

	//-------------------- Setters -----------------------

	void setType(int type);
};

#endif //_DYNAMICBLOCK_H