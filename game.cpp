#include "game.hpp"

Game::Game(std::string diff) {

    displaySize = 3;
    lives = 3;
    difficulty = diff;
    score = 0;

    // init ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    // get screen dimensions
    getmaxyx(stdscr, rowMax, colMax);

    gameWin = newwin(rowMax - displaySize, colMax, displaySize - 1, 0);
    displayWin = newwin(displaySize, colMax, 0, 0);

    drawBorders(gameWin);
    drawBorders(displayWin);
}

Game::~Game(void) {
    endwin();
}

WINDOW* Game::getGameWin(void) {
    return gameWin;
}

WINDOW* Game::getDisplayWin(void) {
    return displayWin;
}

void Game::drawBorders(WINDOW* win) {
  int x, y, i;

  getmaxyx(win, y, x);

  // 4 corners
  mvwprintw(win, 0, 0, "+");
  mvwprintw(win, y - 1, 0, "+");
  mvwprintw(win, 0, x - 1, "+");
  mvwprintw(win, y - 1, x - 1, "+");

  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(win, i, 0, "|");
    mvwprintw(win, i, x - 1, "|");
  }

  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(win, 0, i, "-");
    mvwprintw(win, y - 1, i, "-");
  }
}

void Game::checkResize(void) {
    int new_x, new_y;

    getmaxyx(stdscr, new_y, new_x);

    if (new_y != rowMax || new_x != colMax) {
        colMax = new_x;
        rowMax = new_y;

        wresize(gameWin, new_y - 3, new_x);
        wresize(displayWin, 3, new_x);
        mvwin(displayWin, 0, 0);

        wclear(stdscr);
        wclear(gameWin);
        wclear(displayWin);

        drawBorders(gameWin);
        drawBorders(displayWin);
    }

    // draw to our windows
    mvwprintw(displayWin, 1, 1, "Score: %i", score);
    mvwprintw(displayWin, 1, (colMax / 2) - 10, "Difficulty: %s", difficulty.c_str());
    mvwprintw(displayWin, 1, colMax - 10, "Lives: %i", lives);

    // refresh each window
    wrefresh(gameWin);
    wrefresh(displayWin);
}

int Game::getRowMax(void) {
    return rowMax;
}

int Game::getColMax(void) {
    return colMax;
}

void Game::setDifficulty(std::string diff) {
    difficulty = diff;
}