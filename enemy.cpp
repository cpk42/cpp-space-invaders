#include "enemy.hpp"

Enemy::Enemy(WINDOW* win, int row, int col, char c, int d) {
    cur_win = win;
    row_location = row;
    col_location = col;
    character = c;
    direction = d;
    
    getmaxyx(cur_win, row_max, col_max);
    keypad(cur_win, true);
}

Enemy::~Enemy(void) {
    
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

void Enemy::display() {
    direction == 1 ? moveRight() : moveLeft();

    if (col_location == col_max - 2 || col_location == 1) {
        direction *= -1;
        moveDown();
    }

    mvwaddch(cur_win, row_location, col_location, character);
}

int Enemy::getRow() {
    return row_location;
}

int Enemy::getCol() {
    return col_location;
}
