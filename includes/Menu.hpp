#ifndef MENU_H_
#define MENU_H_

#include <Invaders.hpp>

class Menu {
    public:
        Menu(void);
        ~Menu(void);
        Menu(Menu &other);
        Menu &operator=(Menu const &rhs);

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