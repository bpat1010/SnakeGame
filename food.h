#ifndef FOOD_H_
#define FOOD_H_
#include "pos.h"
#include <vector>
#include<stdio.h>
#include<stdlib.h>

class Food{
public:
	Position pos;
	
	//need to update the random food position
	//need to be implemented
	void update(std::vector<Position> &body,int hx,int hy);
};

#endif
