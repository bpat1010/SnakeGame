#ifndef POS_H_
#define POS_H_

#define ROW  20
#define COL  40

class Position{
	public:
		Position(){};
		Position(int xx,int yy):x(xx),y(yy){}
		int x;
		int y;
};

#endif
