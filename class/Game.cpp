#include <Invaders.hpp>

Game::Game(std::string diff) {

    displaySize = 3;
    lives = 3;
    difficulty = diff;
    score = 0;
    direction = 1;

    // init ncurses
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    // Colors
    start_color();
    init_color(COLOR_CYAN, 1000, 700, 0); // Redefinition for orange
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_CYAN, COLOR_CYAN);

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

    mvwprintw(displayWin, 1, 1, "Score: %i", score);
    mvwprintw(displayWin, 1, (colMax / 2) - 10, "Difficulty: %s", difficulty.c_str());
    mvwprintw(displayWin, 1, colMax - 10, "Lives: %i", lives);

    // refresh each window
    wrefresh(gameWin);
    wrefresh(displayWin);
}

void Game::deathScreen(void) {
    int max_row, max_col;

    wattron(stdscr, COLOR_PAIR(2));

    getmaxyx(stdscr, max_row, max_col);

    for (int i = 0; i < max_row; i++) {
        for (int j = 0; j < max_col; j++) {
              mvwprintw(stdscr, i, j, " ");
        }
        wrefresh(stdscr);
        usleep(25000);
    }
    wattron(stdscr, COLOR_PAIR(1));

    int row = rowMax / 2 - 5;
    int col = colMax / 2 - 30;
    mvprintw(row, col, "   ______                                                  ");
    mvprintw(++row, col, "  / ____/____ _ ____ ___   ___     ____  _   __ ___   _____");
    mvprintw(++row, col, " / / __ / __ `// __ `__ \\ / _ \\   / __ \\| | / // _ \\ / ___/");
    mvprintw(++row, col, "/ /_/ // /_/ // / / / / //  __/  / /_/ /| |/ //  __// /    ");
    mvprintw(++row, col, "\\____/ \\__,_//_/ /_/ /_/ \\___/   \\____/ |___/ \\___//_/     ");
    mvprintw(++row, col + 10, "Final score: %i. Press any key to exit", score);
}

int Game::getRowMax(void) {
    return rowMax;
}

int Game::getColMax(void) {
    return colMax;
}

int Game::getLives(void) {
    return lives;
}

int Game::getGameSpeed(void) {
    return gameSpeed;
}

int Game::getDirection(void) {
    return direction;
}

int Game::getScore(void) {
    return score;
}

void Game::setDifficulty(std::string diff) {
    difficulty = diff;
    gameSpeed = (difficulty == "easy" ? 75000 : difficulty == "medium" ? 50000 : 25000);
}

void Game::setLives(int lives) {
    this->lives = lives;
}

void Game::setDirection(int dir) {
    direction = dir;
}

void Game::setScore(int s) {
    score = s;
}