#include <Invaders.hpp>

Player::Player(WINDOW* win, int row, int col, char c) {
    cur_win = win;
    row_location = row;
    col_location = col;
    character = c;
    is_shooting = 0;
    projectile = new Projectile(win, 0, 0, 'x');

    getmaxyx(cur_win, row_max, col_max);
    keypad(cur_win, true);
    halfdelay(1);
}

Player::~Player(void) {

}

void Player::moveUp() {
    mvwaddch(cur_win, row_location, col_location, ' ');
    row_location = --row_location < 1 ? 1 : row_location;
}

void Player::moveDown() {
    mvwaddch(cur_win, row_location, col_location, ' ');
    row_location = ++row_location > row_max - 2 ? row_max - 2 : row_location;
}

void Player::moveLeft() {
    mvwaddch(cur_win, row_location, col_location, ' ');
    col_location = --col_location < 1 ? 1 : col_location;
}

void Player::moveRight() {
    mvwaddch(cur_win, row_location, col_location, ' ');
    col_location = ++col_location > col_max - 2 ? col_max - 2 : col_location;
}

void Player::fire() {
  is_shooting = 1;
  Projectile* node = new Projectile(cur_win, row_location, col_location, 'x');
  node->next = projectile;
  projectile = node;
}

int Player::getMove() {
    int choice = wgetch(cur_win);
    switch (choice) {
        case KEY_UP:
            moveUp();
            break;
        case KEY_DOWN:
            moveDown();
            break;
        case KEY_LEFT:
            moveLeft();
            break;
        case KEY_RIGHT:
            moveRight();
            break;
        case ' ':
            fire();
            break;
        default:
            break;
    }
    return choice;
}

void Player::display() {
    if (isShooting()) {
      Projectile *ptr = projectile;
      while (ptr->next) {
        ptr->fire();
        ptr = ptr->next;
      }
    }
    getmaxyx(cur_win, row_max, col_max);
    if (row_location >= row_max)
        row_location = row_max - 2;
    if (col_location >= col_max)
        col_location = col_max / 2;
    mvwaddch(cur_win, row_location, col_location, character);
}

int Player::getRow() {
    return row_location;
}

int Player::getCol() {
    return col_location;
}

int Player::isShooting() {
    if (is_shooting > 0)
      return (1);
    else
      return (0);
}
