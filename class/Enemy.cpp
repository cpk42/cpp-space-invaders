#include <Invaders.hpp>

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

void Enemy::display(Game* g, Enemy *arr[60], Player *player) {
    getmaxyx(cur_win, row_max, col_max);
    if (row_location >= row_max)
        row_location = row_max - row_location;
    if (col_location >= col_max)
        col_location = col_max - col_location;
    g->getDirection() == 1 ? moveRight() : moveLeft();

    if (col_location == col_max - 2 || col_location == 1) {
        g->setDirection(g->getDirection() * -1);
        for (int i = 0; i < 60; i++)
        {
            arr[i]->moveDown();
        }
        moveRight();
        moveRight();
    }

    if (g->getLives() <= 0)
        return;

    if (mvwinch(cur_win, row_location, col_location) == 'x')
    {
        g->setScore(g->getScore() + 1);
        valid = 0;
        hitAnimation();
        return;
    }
    if (row_location == player->getRow() && col_location == player->getCol()) {
        g->setLives(g->getLives() - 1);
        valid = 0;
        collisionAnimation();
        player->reset();
        return;
    }
    if (row_location == row_max - 2)
    {
        g->setLives(g->getLives() - 1);
        valid = 0;
        bottomRowAnimation();
        return;
    }
    mvwaddch(cur_win, row_location, col_location, character);
}

void Enemy::bottomRowAnimation() {
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

void Enemy::collisionAnimation() {
    for (int i = 1; i < 4; i++) {
        usleep(75000);
        mvwaddch(cur_win, row_location, col_location, ' ');
        mvwaddch(cur_win, row_location, col_location - i, ' ');
        mvwaddch(cur_win, row_location, col_location + i, ' ');
        mvwaddch(cur_win, row_location - i, col_location, ' ');
        mvwaddch(cur_win, row_location + i, col_location, ' ');
        wrefresh(cur_win);
        usleep(75000);
        wattron(cur_win, COLOR_PAIR(3));
        mvwaddch(cur_win, row_location, col_location, ' ');
        mvwaddch(cur_win, row_location, col_location - i, ' ');
        mvwaddch(cur_win, row_location, col_location + i, ' ');
        mvwaddch(cur_win, row_location - i, col_location, ' ');
        mvwaddch(cur_win, row_location + i, col_location, ' ');
        wrefresh(cur_win);
        usleep(75000);
        wattron(cur_win, COLOR_PAIR(4));
        mvwaddch(cur_win, row_location, col_location, ' ');
        mvwaddch(cur_win, row_location, col_location - i, ' ');
        mvwaddch(cur_win, row_location, col_location + i, ' ');
        mvwaddch(cur_win, row_location - i, col_location, ' ');
        mvwaddch(cur_win, row_location + i, col_location, ' ');
        wrefresh(cur_win);
        usleep(75000);
        wattron(cur_win, COLOR_PAIR(2));
        mvwaddch(cur_win, row_location, col_location, ' ');
        mvwaddch(cur_win, row_location, col_location - i, ' ');
        mvwaddch(cur_win, row_location, col_location + i, ' ');
        mvwaddch(cur_win, row_location - i, col_location, ' ');
        mvwaddch(cur_win, row_location + i, col_location, ' ');
        wrefresh(cur_win);
        usleep(75000);
    }
    wattroff(cur_win, COLOR_PAIR(2));
    for (int i = 1; i < 4; i++) {
        mvwaddch(cur_win, row_location, col_location, ' ');
        mvwaddch(cur_win, row_location, col_location - i, ' ');
        mvwaddch(cur_win, row_location, col_location + i, ' ');
        mvwaddch(cur_win, row_location - i, col_location, ' ');
        mvwaddch(cur_win, row_location + i, col_location, ' ');
    }
    wrefresh(cur_win);
}

void Enemy::hitAnimation(void) {
    wattron(cur_win, COLOR_PAIR(1));
    mvwaddch(cur_win, row_location, col_location, 'X');
    wrefresh(cur_win);
    usleep(25000);
    wattroff(cur_win, COLOR_PAIR(1));
    mvwaddch(cur_win, row_location, col_location, ' ');
    wrefresh(cur_win);
    usleep(25000);
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
