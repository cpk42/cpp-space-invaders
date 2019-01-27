#include <ncurses.h>
#include <iostream>

#include "player.hpp"
#include "enemy.hpp"
#include "game.hpp"
#include "Menu.hpp"

int main(void)
{
    Game* g = new Game("easy");
    Menu* m = new Menu();
    g->setDifficulty(m->selectDifficulty());
    Player* p = new Player(g->getGameWin(), g->getRowMax() - 1, g->getColMax() / 2, '^');
    Enemy* e = new Enemy(g->getGameWin(), 1, 1, '*', 1);
    //Enemy *e_arr[20];
    // for (int i = 0; i < 20; i ++)
    //     e_arr[i] = new Enemy(g->getGameWin(), 1, i * 2, 'o', 1);
    // Enemy* e = new Enemy(g->getGameWin(), 1, 5, 'o', 1);
    // Enemy* e1 = new Enemy(g->getGameWin(), 1, 7, 'o', 1);
    
    do {
       // for (int i = 0; i < 20; i++) {
            // e->display();
            // e_arr[i]->display();
            // wrefresh(g->getGameWin());
       // }
        g->checkResize();
        e->display();
        p->display();
    } while(p->getMove() != 'x');

    delete g;

    return 0;

}
