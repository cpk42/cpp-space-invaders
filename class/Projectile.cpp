#include <Invaders.hpp>

Projectile::Projectile(WINDOW* win, int row, int col, char c) {
    cur_win = win;
    row_location = row;
    col_location = col;
    character = c;
    is_shooting = 0;
    next = NULL;

    getmaxyx(cur_win, row_max, col_max);
    //halfdelay(1);
}

Projectile::~Projectile(void) {
  cur_win = NULL;
  row_location = 0;
  col_location = 0;
  character = ' ';
  is_shooting = 0;
  next = NULL;
}


void Projectile::fire() {
  mvwaddch(cur_win, row_location - 1, col_location, 'x');
  mvwaddch(cur_win, row_location, col_location, ' ');
  if (row_location-1 > 0)
    row_location = row_location-1;
  else
    mvwaddch(cur_win, row_location - 1, col_location, '-');
}
