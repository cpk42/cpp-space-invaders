#include "game.hpp"

Game::Game() {

    // init ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    halfdelay(1);

    // get screen dimensions
    getmaxyx(stdscr, colMax, rowMax);

    // create game window (height, width, start_row, start_col)
    gameWin = newwin(20, 50, (colMax / 2) - 10, 10);
    box(gameWin, 0, 0);

    // create display window
    WINDOW* displayWin = newwin(6, 50, 1, 10);
    box(displayWin, 0, 0);
    
    // refresh();
    // wrefresh(gameWin);
    wrefresh(displayWin);
}

WINDOW* Game::getGameWin(void) {
    return gameWin;
}

WINDOW* Game::getDisplayWin(void) {
    return displayWin;
}