#ifndef BODY_H_
#define BODY_H_
#include <vector>
#include "pos.h"

class Body{
public:
	std::vector<Position> body_;
	//add function will add postion to the back of body
	void add(int x,int y){
		body_.push_back(Position(x,y));
	}

	void clear(){
		body_.clear();
	}

	//count function will return the actual size of the body
	int count(){return body_.size();}
	
	//move function will use to make movement
	//need to be implemented
	void move(int x,int y);
	
};

#endif
