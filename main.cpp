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
    Enemy *e_arr[20];
    for (int i = 0; i < 20; i ++)
        e_arr[i] = new Enemy(g->getGameWin(), 1, i * 2, 'o', 1);
    // Enemy* e = new Enemy(g->getGameWin(), 1, 5, 'o', 1);
    // Enemy* e1 = new Enemy(g->getGameWin(), 1, 7, 'o', 1);
    
    do {
        p->display();
        for (int i = 0; i < 20; i++) {
            e_arr[i]->display();
            // wrefresh(g->getGameWin());
        }
            
        // e->display();
        // e1->display();
        wrefresh(g->getDisplayWin());
    } while(p->getMove() != 'x');


    // free ncruses window
    endwin();

    return 0;

}
