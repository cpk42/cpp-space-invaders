#include <ncurses.h>
#include <iostream>

#include "player.hpp"

int main(void)
{
    // init ncurses
    initscr();
    noecho();
    cbreak();

    // get screen dimensions
    int colMax, rowMax;
    getmaxyx(stdscr, colMax, rowMax);

    // create window for user input
    WINDOW* gamewin = newwin(20, 50, (colMax / 2) - 10, 10);
    box(gamewin, 0, 0);
    refresh();
    wrefresh(gamewin);

    Player* p = new Player(gamewin, 1, 1, '^');
    
    do {
        p->display();
        wrefresh(gamewin);
    } while(p->getMove() != 'x');

    // free ncruses window
    endwin();

    return 0;

}
