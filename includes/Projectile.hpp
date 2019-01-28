#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include <Invaders.hpp>

class Projectile {
public:
  int is_shooting;
  Projectile *next;

  Projectile(void);
  Projectile(WINDOW* win, int row, int col, char c);
  ~Projectile(void);
  Projectile(Projectile &other);
  Projectile &operator=(Projectile const &rhs);
  
  void fire();
private:
    int row_location, col_location;
    int row_max, col_max;
    char character;
    WINDOW* cur_win;
};

#endif
