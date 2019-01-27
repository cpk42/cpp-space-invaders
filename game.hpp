#ifndef GAME_HPP_
#define GAME_HPP_

#include <ncurses.h>

class Game {
    public:
        Game(void);
        ~Game(void);

        WINDOW* getGameWin(void);
        WINDOW* getDisplayWin(void);

    private:
        int colMax;
        int rowMax;
        WINDOW* gameWin;
        WINDOW* displayWin;
};

#endif