#ifndef PLAYER_H_
#define PLAYER_H_

#include <Invaders.hpp>

class Player {
    public:
        Player(void);
        Player(WINDOW* win, int row, int col, char c);
        ~Player(void);
        Player(Player &other);
        Player &operator=(Player const &rhs);

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        int getMove();
        void display();
        void shoot();
        void fire();
        void reset();

        int getRow();
        int getCol();
        int isShooting();

    private:
        int row_location, col_location;
        int row_max, col_max;
        int is_shooting;
        char character;
        WINDOW* cur_win;
        Projectile *projectile;
};

#endif
