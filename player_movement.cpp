#include <ncurses.h>
#include <iostream>

#include "player.hpp"

int main(void)
{
    // init ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    // get screen dimensions
    int colMax, rowMax;
    getmaxyx(stdscr, colMax, rowMax);

    // create window for user input
    WINDOW* gamewin = newwin(20, 50, (colMax / 2) - 10, 10);
    box(gamewin, 0, 0);
    refresh();
    wrefresh(gamewin);

    Player* p = new Player(gamewin, 18, 25, '^');
    
    do {
        p->display();
        wrefresh(gamewin);
    } while(p->getMove() != 'x');

    // free ncruses window
    endwin();

    return 0;

}
