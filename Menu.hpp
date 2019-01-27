#ifndef MENU_H_
#define MENU_H_

#include <ncurses.h>
#include <iostream>
#include "game.hpp"

class Menu {
    public:
        Menu(void);
        ~Menu(void);

        std::string selectDifficulty(void);
        void printEasy(void);
        void printMedium(void);
        void printHard(void);

    private:
        WINDOW* menuWin;
        int colMax;
        int rowMax;
};

#endif