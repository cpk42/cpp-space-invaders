#ifndef ENEMY_H_
#define ENEMY_H_

#include <ncurses.h>

class Enemy {
    public:
        Enemy(WINDOW* win, int row, int col, char c, int d);
        ~Enemy(void);

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void display();
        void moveSideToSide();

    private:
        int row_location, col_location;
        int row_max, col_max;
        char character;
        int direction;
        WINDOW* cur_win;
};

#endif