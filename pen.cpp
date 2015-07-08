#include "pen.h"

// change the position of cursor
void Pen::goto_xy(int x, int y)
{
    std::cout<<"\033["<<x<<";"<<y<<"H";
}
 
// print ch in the front color is fcolor, background color is bcolor
void Pen::putch(int fcolor, int bcolor, char ch)
{
    std::cout<<"\033["<<fcolor<<"m\033["<<bcolor<<"m"<<ch<<"\033[0m";
}
 
// print string in the front color is fcolor, background color is bcolor
void Pen::putstr(int fcolor, int bcolor, const std::string str)
{
    std::cout<<"\033["<<fcolor<<"m\033["<<bcolor<<"m"<<str<<"\033[0m";
}
// clear the screen
void Pen::clr_scrn(void)
{
    std::cout<<"\033[2J";
}
 
// hide the cursor
void Pen::hide_cur(void)
{
   std::cout<<"\033[?25l";
}
 
//show the cursor
void Pen::show_cur(void)
{
    std::cout<<"\033[?25h";
}
 
//save the cursor
void Pen::store_cur(void)
{
    std::cout<<"\033[s";
}
 
//load the cursor
void Pen::load_cur(void)
{
    std::cout<<"\033[u";
}
 
//draw a box
void Pen::draw_box(int x, int y, int row, int col, int fcolor,int bcolor, char ch)
{   int i, j;
    for(i = 0;i <= row; i++)
        for(j = 0; j <= col; j++)
        {
            if(i == 0 || i == row 
                    || j == 0 || j == col)
                std::cout<<"\033["<<i+x<<";"<<j+y<<"H\033["<<fcolor<<";"<<bcolor<<"m"<<ch<<"\033[0m\n";
            else
                std::cout<<"\033["<<i+x<<";"<<j+y<<"H ";
        }
}
 
//draw a rectangle
void Pen::draw_rect(int x, int y, int row, int col, int fcolor,int bcolor, char ch)
{
    int i, j;
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
        {
            std::cout<<"\033["<<i+x<<";"<<j+y<<"H\033["<<fcolor<<";"<<bcolor<<"m"<<ch<<"\033[0m\n";
        }
 
}
