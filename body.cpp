#include "body.h"

void Body::move(int x1,int y1){
	//TODO
	//update body location, body.cpp
	
	for (int i = count() - 1; i > 0; i--){
		this->body_[i].x = this->body_[i - 1].x;
		this->body_[i].y = this->body_[i - 1].y;
		this->body_[0].x = x1;
		this->body_[0].y = y1;
	}
	//You need to iterate through the body and 
	//shift the previous body position to itself 
	//in order to make movement 
}
