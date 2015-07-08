#ifndef PEN_H_
#define PEN_H_
#include <string>
#include <iostream>

class Pen{
public:
	void goto_xy(int x, int y);
	void putch(int fcolor, int bcolor, char ch);
	void putstr(int fcolor, int bcolor, const std::string str);
	void clr_scrn(void);
	void hide_cur(void);
	void show_cur(void);
	void store_cur(void);
	void load_cur(void);
	void draw_box(int x, int y, int row, int col, int fcolor, int bcolor,char ch);
	void draw_rect(int x, int y, int row, int col, int fcolor, int bcolor,char ch);
};

#endif
