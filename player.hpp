#ifndef PLAYER_H_
#define PLAYER_H_

#include <ncurses.h>

class Player {
    public:
        Player(WINDOW* win, int row, int col, char c);
        ~Player(void);

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        int getMove();
        void display();

        int getRow();
        int getCol();

    private:
        int row_location, col_location;
        int row_max, col_max;
        char character;
        WINDOW* cur_win;
};

#endif