#include "game.h"
#include <thread> 

//get_key will return the key user typed
char Game::get_key()
{
	int n;
	char buf[3];
	n = read(0, buf, sizeof(buf));
	if (3 == n && buf[0] == 27 && buf[1] == 91)
	{
		return buf[2];
	}
	else if (1 == n)
	{
		return buf[0];
	}
	return 0;
}

//need to implement end funtion()
int Game::end() //exit game function
{
	//TODO
	//need to make cursor goto the bottom
	//need to show cursor
	pen.load_cur();
	pen.show_cur();
	pen.clr_scrn();
	exit(0);                        //exit
}

int Game::getKey()                  //key control function
{
	//implement personal version of getKey
	//TODO
	while (getKeyAllowed)
	{
		char key;

		key = get_key();

		if (mode == 0){ // In game handler
			switch (key) {

			case UP:
				snake.head.direction = UP;
				break;

			case DOWN:
				snake.head.direction = DOWN;
				break;

			case RIGHT:
				snake.head.direction = RIGHT;
				break;

			case LEFT:
				snake.head.direction = LEFT;
				break;

			case 'p':
				pauseHandler();
				break;


			default:

				break;
			}
		}
		else if (mode == 1){ // In pause handler
			switch (key) {

			case '1': // unpause
				mode = 0;
				break;

			case '2':
				restart();
				break;
			case '3':
				reInitialize();
			default:

				break;
			}
		}
		else if (mode == 2){ // In pause handler
			switch (key) {
			case '1':
				restart();
				break;

			case '2':
				reInitialize();
			default:

				break;
			}
		}

	}

	return 0;
	//need to implement this function
	//which will take a infinite loop to 
	//set direction of snake head


}


//function use to draw a box
void Game::drawBox()                     //draw the outer range
{
	pen.clr_scrn();
	pen.draw_box(1, 20, ROW, COL, 44, 34, '#');
}

void Game::drawSnake(void)                   // draw snake
{
	//TODO
	int i;
	pen.draw_rect(snake.head.pos.x, snake.head.pos.y + 20, 1, 1, 43, 33, 'x');
	for (int i = 0; i <= snake.body.count() - 1; i++){

		pen.draw_rect(snake.body.body_[i].x, snake.body.body_[i].y + 20, 1, 1, 3, 32, '@');
	}
	//need to draw the snake out
	//draw head
	//use loop to draw body
}

void Game::snakeMove(void)                   //move snake
{

	//TODO
	//check with if statement if snake.head.pos.x reaches wall 
	//row is x
	//check the wall, call end()
	//if snake hits itself or something, end()
	//column is y (+20)
	//iterate through body if the snake hit itself
	//check if it hits food then "body.add(0,0)

	int i;

	if (snake.head.pos.x <= 1 or snake.head.pos.x >= ROW + 1 or snake.head.pos.y <= 0 or snake.head.pos.y >= COL)
	{
		deathHandler("You hit a wall.");
	}
	//for loop to check if body hits itself

	for (i = 0; i<snake.body.count(); i++){
		if (snake.head.pos.x == snake.body.body_[i].x && snake.head.pos.y == snake.body.body_[i].y){
			//prints out where you died, might not need this
			//std::cout << snake.head.pos.x << " " << snake.head.pos.y << std::endl;
			//std::cout << snake.body.body_[i].x << " " << snake.body.body_[i].y << std::endl;
			std::cout << "Don't hit yourself!!!" << std::endl;
			deathHandler("You hit yourself.");
		}
	}
	//for when the snake hits the food
	if (snake.head.pos.x == food.pos.x && snake.head.pos.y == food.pos.y){
		food.update(snake.body.body_, snake.head.pos.x, snake.head.pos.y);
		snake.body.add(0, 0);

	}
	//make movement switch key

	snake.body.move(snake.head.pos.x, snake.head.pos.y);
	switch (snake.head.direction) {

	case UP:
		if (fkey != 'd')
		{
			snake.head.pos.x -= 1;
			fkey = 'u';
		}
		else
		{
			snake.head.pos.x += 1;
		}
		break;

	case DOWN:
		if (fkey != 'u')
		{
			snake.head.pos.x += 1;
			fkey = 'd';
		}
		else
		{
			snake.head.pos.x -= 1;

		}
		break;

	case RIGHT:
		if (fkey != 'l')
		{
			snake.head.pos.y += 1;
			fkey = 'r';
		}
		else
		{
			snake.head.pos.y -= 1;

		}
		break;

	case LEFT:
		if (fkey != 'r')
		{
			snake.head.pos.y -= 1;
			fkey = 'l';
		}
		else
		{
			snake.head.pos.y += 1;
		}
		break;

	}
	//use switch key direction of head, update position of the head
	//if it is not valid, do not change anything
	//if it is valid, change the fkey to valid key 
	//need to check if the head space is valid 
	//if it is valid check if the space has food
	//if it has food-->update food && update body
	//make movement
	//update head position
	//use fkey(fault key) to check the wrong direction
}

void Game::start(){
	int quit = 0;
	while (!quit)
	{
		system("stty -echo -icanon");   //cancel cacheï¼›
		pen.hide_cur();
		pen.clr_scrn();
		drawBox();

		//TODO
		pen.goto_xy(6, 33);
		pen.putstr(31, 1, "Welcome To My Snake Game");
		pen.goto_xy(8, 33);
		pen.putstr(31, 1, "1.New Game");
		pen.goto_xy(10, 33);
		pen.putstr(31, 1, "2.Load Game"); //need to implement, pause feature
		pen.goto_xy(12, 33);
		pen.putstr(31, 1, "3.High-Score"); //add lifetime highscore, add a restart feature after end(), add a score counter
		pen.goto_xy(14, 33);
		pen.putstr(31, 1, "4.Exit");
		pen.goto_xy(16, 33);
		pen.putstr(31,1, "Press P to pause anytime");
		//pen.goto a certain position
		//pen.putstr to enter whatever you want to
		//need to draw a welcome page
		//need to add more feature in the switch below


		fflush(stdout); //flush the buffer
		int back = 0;
		while (!back)
		{
			int ret;
			char key = '0';
			int i;
			key = get_key();            //get key
			switch (key)
			{

			case '2':
				break;
			case '3':
				break;
			case '4':
				end();
				break;
			
			case '1':  //case 49: // start game,??? is the key you use to start game
				gameStart();
				
				std::thread f1([&](){
					handler();
				});
				std::thread f2([&](){
					getKey();
				});

				f1.join();
				f2.join();

				back = 1;
				quit = 1;
				break;
			}
		}
	}
	end();    // end of game
}
//score feature
void Game::Score(){
	int s=0;//store counter for food
	std::string q;
	if (snake.body.count() > 3) { 
		s = (snake.body.count() - 3);
	}
	q = "Score: " + std::to_string(s);
	pen.goto_xy(3, 10);
	pen.putstr(31,1, q);

}
//handler is use to draw food and update snake position
//spped feature
void Game::Speed(){
	int s;
	if ( (snake.body.count() - 3) > 5) {
		speed = 50000;
	}
	else if ( (snake.body.count() - 3) > 10) {
		speed = 25000;
	}
}

//handler is use to draw food and update snake position

void Game::handler(){

	//TODO

	//use a infinite loop
	while (true && !terminateHandler){ //infinite loop to keep printing
		if (mode == 0){
			drawBox();
			pen.draw_rect(food.pos.x, food.pos.y + 20, 1, 1, 46, 36, '#');
			snakeMove();
			if (mode == 0){ // If snake does not crash, then keep updating
				Score();
				Speed();
				drawSnake();
				fflush(stdout);
				usleep(speed);//changes speed of game
			}
		}
	}

	//draw the game box
	//draw the food
	//move the snake, draw the snake
	//flush the cache
	//use usleep(speed) to control speed
}
//include exit feature
//can now return to main menu
//pause game and resume game 
void Game::pauseHandler()
{
	mode = 1;
	system("stty -echo -icanon"); 
	pen.clr_scrn();
	drawBox();

	pen.goto_xy(6, 33);
	pen.putstr(31, 1, "Game Paused.");
	pen.goto_xy(8, 33);
	pen.putstr(31, 1, "1. Resume");

	pen.goto_xy(10, 33);
	pen.putstr(31, 1, "2. Restart"); //need to implement, pause feature
	pen.goto_xy(12, 33);
	pen.putstr(31, 1, "3. Return to main menu"); //add lifetime highscore, add a restart feature after end(), add a score counter
	fflush(stdout); //flush the buffer
}
//death message if you hit wall 
void Game::deathHandler(std::string message)
{	
	mode = 2;
	system("stty -echo -icanon"); 
	pen.clr_scrn();
	drawBox();

	pen.goto_xy(6, 27);
	pen.putstr(31, 1, "You died! - " + message);

	pen.goto_xy(8, 33);
	pen.putstr(31, 1, "1. Restart");
	pen.goto_xy(10, 33);
	pen.putstr(31, 1, "2. Return to main menu"); //need to implement, pause feature
	fflush(stdout);
}
//initialize values again
void Game::reInitialize(){
	getKeyAllowed = false;
	terminateHandler = true;
	mode = 0;
	system("stty -echo -icanon");   //cancel cacheï¼›
	pen.clr_scrn();
	drawBox();
	fflush(stdout);
	start();
}
//restart feature
void Game::restart(){
	gameStart();
	system("stty -echo -icanon");   //cancel cacheï¼›
	pen.clr_scrn();
	drawBox();
	fflush(stdout);
	mode = 0;
}

void Game::gameStart(){
	mode = 0; 
	getKeyAllowed = true;
	terminateHandler = false;
	snake.head.pos.x = 10;                  //init the head position
	snake.head.pos.y = 20;
	snake.body.clear(); // Clear the body nodes
	snake.body.add(10, 19);            //init the body position
	snake.body.add(10, 18);
	snake.body.add(10, 17);
	fkey = 'r';                           //direction
	snake.head.direction = RIGHT;                //head direction
	speed = 100000;
	food.update(snake.body.body_, snake.head.pos.x, snake.head.pos.y); //init food position

}
