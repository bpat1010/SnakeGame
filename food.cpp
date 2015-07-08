#include "food.h"

//need to update the random food position
//need to be implemented
void Food::update(std::vector<Position> &body,int hx,int hy){
    int i;
    int flag = 0;
    while(1)
    {
        pos.x = (rand() % (ROW - 2)) + 2;
        pos.y = (rand() % (COL - 2)) + 2;
 
        //TODO
		//check food position = to food position
		//item goes in and if it is or is not part of part of body going into flag and jumps out
		//if food does not go into body it is flagged and resets to the beginning of the while loop
		if (pos.x != hx && pos.y != hy)
			for (i = 0; i < body.size(); i++)
			{
				if (pos.x != body[i].x && pos.y != body[i].y)
					flag = 1;
			}
		//need to check if the food position is valid
 
        if(flag)
        {
            break;
        }
        continue;
    }
}
