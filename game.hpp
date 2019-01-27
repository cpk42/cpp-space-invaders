#ifndef GAME_HPP_
#define GAME_HPP_

#include <ncurses.h>
#include <iostream>

class Game {
    public:
        Game(std::string difficulty);
        ~Game(void);

        WINDOW* getGameWin(void);
        WINDOW* getDisplayWin(void);

        void drawBorders(WINDOW* win);
        void checkResize(void);

        void displayWinInfo(void);
        int getColMax(void);
        int getRowMax(void);
        void setDifficulty(std::string diff);

    private:
        int colMax;
        int rowMax;
        int lives;
        int score;
        int displaySize;
        std::string difficulty;
        WINDOW* gameWin;
        WINDOW* displayWin;
};

#endif