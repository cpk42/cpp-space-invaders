#ifndef ENEMY_H_
#define ENEMY_H_

#include <Invaders.hpp>

class Enemy {
    public:
        Enemy(WINDOW* win, int row, int col, char c, int d);
        ~Enemy(void);

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void display(Game* g);
        void moveSideToSide();
        void deathAnimation();

        int getRow(void);
        int getCol(void);
        int isValid(void);

    private:
        int row_location, col_location;
        int row_max, col_max;
        char character;
        int direction;
        int valid;
        WINDOW* cur_win;
};

#endif