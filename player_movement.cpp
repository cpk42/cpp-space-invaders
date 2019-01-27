#include <ncurses.h>
#include <iostream>

#include "player.hpp"
#include "enemy.hpp"
#include "game.hpp"

int check_collision(int playerRow, int playerCol, int enemyRow, int enemyCol) {
    if (playerRow == enemyRow && enemyRow == enemyCol)
        return 1;
    return 0;
}

int main(void)
{

    Game* g = new Game();
    Player* p = new Player(g->getGameWin(), 18, 25, '^');
    Enemy* e = new Enemy(g->getGameWin(), 1, 1, 'o', 1);
    
    do {
        p->display();
        e->display();
        //check_collision(p->getRow(), p->getCol(), e->getRow(), e->getCol()) == 1 ? mvwprintw(gamewin, 1, 1, "collision") : 0;
        wrefresh(g->getDisplayWin());
    } while(p->getMove() != 'x');


    // free ncruses window
    endwin();

    return 0;

}
