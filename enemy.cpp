#include "enemy.hpp"

Enemy::Enemy(WINDOW* win, int row, int col, char c, int d) {
    cur_win = win;
    row_location = row;
    col_location = col;
    character = c;
    direction = d;
    valid = 1;
    
    getmaxyx(cur_win, row_max, col_max);
}

Enemy::~Enemy(void) {
    delete this;
}

void Enemy::moveUp() {
    mvwaddch(cur_win, row_location, col_location, ' ');
    row_location = --row_location < 1 ? 1 : row_location;
}

void Enemy::moveDown() {
    mvwaddch(cur_win, row_location, col_location, ' ');
    row_location = ++row_location > row_max - 2 ? row_max - 2 : row_location;
}

void Enemy::moveLeft() {
    mvwaddch(cur_win, row_location, col_location, ' ');
    col_location = --col_location < 1 ? 1 : col_location; 
}

void Enemy::moveRight() {
    mvwaddch(cur_win, row_location, col_location, ' ');
    col_location = ++col_location > col_max - 2 ? col_max - 2 : col_location;
}

void Enemy::display(Game* g) {
    getmaxyx(cur_win, row_max, col_max);
    if (row_location >= row_max)
        row_location = row_max - row_location;
    if (col_location >= col_max)
        col_location = col_max - col_location;
    direction == 1 ? moveRight() : moveLeft();

    if (col_location == col_max - 2 || col_location == 1) {
        direction *= -1;
        moveDown();
    }

    if (row_location == row_max - 2)
    {
        g->setLives(g->getLives() - 1);
        valid = 0;
        deathAnimation();
        return;
    }
    mvwaddch(cur_win, row_location, col_location, character);
}

void Enemy::deathAnimation() {
    wattron(cur_win, COLOR_PAIR(1));
    mvwaddch(cur_win, row_location, col_location, 'X');
    wrefresh(cur_win);
    usleep(100000);
    wattroff(cur_win, COLOR_PAIR(1));
    mvwaddch(cur_win, row_location, col_location, ' ');
    wrefresh(cur_win);
    usleep(100000);
    wattron(cur_win, COLOR_PAIR(1));
    mvwaddch(cur_win, row_location, col_location, 'X');
    wrefresh(cur_win);
    usleep(100000);
    wattroff(cur_win, COLOR_PAIR(1));
    mvwaddch(cur_win, row_location, col_location, ' ');
    wrefresh(cur_win);
    usleep(100000);
    wattron(cur_win, COLOR_PAIR(1));
    mvwaddch(cur_win, row_location, col_location, 'X');
    wrefresh(cur_win);
    wattroff(cur_win, COLOR_PAIR(1));
    mvwaddch(cur_win, row_location, col_location, ' ');    
}

int Enemy::getRow() {
    return row_location;
}

int Enemy::getCol() {
    return col_location;
}

int Enemy::isValid() {
    return valid;
}
