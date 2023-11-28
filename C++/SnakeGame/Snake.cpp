#include<iostream>
#include<math.h>
#include <vector>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

// it is similar to class with default public access to it's members
struct Point{

    int x , y;
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};

class Snake{

    public:

    vector<Point> body;

    Snake(int x , int y){ 
        body.push_back(Point(x,y));
    }

    void move(int x , int y){
        body.insert(body.begin(), Point(x,y));
        body.pop_back(); // bcz snake had moved so last element is removed
    }

//     void move(int x, int y) {
//     for (int i = body.size() - 1; i > 0; i--) {
//         body[i].x = body[i - 1].x;
//         body[i].y = body[i - 1].y;
//     }
//     body[0].x = x;
//     body[0].y = y;
// }

    bool collision(){
        Point head = body[0];
        for(int i=0;i<body.size();i++){
            if(head.x == body[i].x && head.y == body[i].y){
                return true;
            }
        }
        return false;
    }

    bool eat(Point food){
        Point head = body[0];
        if(head.x == food.x && head.y == food.y){
            body.push_back(body[body.size()-1]); // increasing the size of snake
            return true;
        }
        return false;
    }

};

int main(){

    //initializing ncurses
    //it is a library in c++ used to initialize and configure the terminal screen use in a text-based user interface (TUI).

    //functions from ncurses library
    initscr();
    // initialize the ncurses library and setup the terminal screen 
    cbreak();
    // it break's the terminal so that so that system can read keyboard input . one character at a time
    noecho();
    // it is used so that kafi word type na ho jaee when user gives inout so that ye kafi or use na hojaee system mai
    curs_set(0);
    // used to disable the arrow of mouse 
    keypad(stdscr, TRUE);
    // enable function keys on the keyboard such as arrow keys shows . true so that function key will noe get disabled 


    int width = 40;
    int height = 20;

    int snake_x = width/2;
    int snake_y = height/2;

    int food_x = rand()%width;
    int food_y = rand()%height;

    Snake snake(snake_x , snake_y); // bcz we are creating object with stack based allocation we don't
    //need to use new keyword and its lifetime is also scope based so that it can automatically 
    //de-allocated itself. but its size has to be known before compile time.

    bool gameOver = false;
    int score = 0;

    while(!gameOver){
        clear(); // for clearing console

        //border
        // +2 is to make border so that snake can move in actuall 20 blocks
        for(int i=0;i<width + 2 ;i++){
            mvprintw(0,i,"#"); //function to print at some position (row , col , wht to print);
            mvprintw(height+1 , i , "#"); // this +1 is to match indexing bcx index start from 0;
        }

        // +1 bcz in above loop one # is already made so we only need to consider the lower wall
        for(int i=1 ;i<height+1 ;i++){
            mvprintw(i,0,"#");
            mvprintw(i,width+1,"#"); // this +1 is to match indexing bcx index start from 0;
        }


    //Snake
    for(int i=0;i<snake.body.size();i++){
        mvprintw(snake.body[i].y , snake.body[i].x , "O"); // x represents col and y represents row.
    }

    //food
    mvprintw(food_y , food_x , "*"); 

    //showing score
    mvprintw(height+2, 0, "Score: %d", score);


    //user input
    // int ch = getch();
    // switch (ch)
    // {
    // case KEY_UP:
    //     snake.move(snake.body[0].x , snake.body[0].y -1);
    //     break;

    // case KEY_DOWN:
    //     snake.move(snake.body[0].x , snake.body[0].y +1);
    //     break;

    // case KEY_LEFT:
    //     snake.move(snake.body[0].x-1 , snake.body[0].y);
    //     break;

    // case KEY_RIGHT:
    //     snake.move(snake.body[0].x +1 , snake.body[0].y);
    //     break;
    
    // case 'q':
    //     gameOver = true;
    //     break;
    // }

    int ch = getch();
switch (ch)
{
case 'W':
case 'w':
    snake.move(snake.body[0].x, snake.body[0].y - 1);
    break;

case 'S':
case 's':
    snake.move(snake.body[0].x, snake.body[0].y + 1);
    break;

case 'A':
case 'a':
    snake.move(snake.body[0].x - 1, snake.body[0].y);
    break;

case 'D':
case 'd':
    snake.move(snake.body[0].x + 1, snake.body[0].y);
    break;

case 'q':
case 'Q':
    gameOver = true;
    break;
}



    //Collision
    if(snake.collision()){
        gameOver = true;
        break;
    }


    //if eat
    if(snake.eat(Point(food_x , food_y))){
        food_x = rand()%width;
        food_y = rand()%height;
        score++;
    }

    snake.move(snake.body[0].x , snake.body[0].y);

    refresh(); // for updating the screen 

    usleep(100000); // wait for 100 miliseconds

    }

    //game over
    clear();
    mvprintw(height/2 , (width/2)- 7 ,"Game Over! *.*"); // bcz game over is of 9 char so 9/2 = 5 , so that it will come in middle exactly
    mvprintw((height/2)+1, (width/2)+7, "Final Score: %d", score);

    refresh();
    usleep(100000);

    //close ncurses so that all the sources will get deallocate 
    endwin();

    return 0;
}