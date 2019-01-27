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
    Enemy *e_arr[1];
    for (int i = 0; i < 1; i ++)
        e_arr[i] = new Enemy(g->getGameWin(), 1, i * 2, 'o', 1); 
    do {
       for (int i = 0; i < 1; i++) {
            if (e_arr[i]->isValid())
                e_arr[i]->display(g);
       }
        p->display();
        g->checkResize();
        if (g->getLives() == 0) {
            break;
        }
    } while(p->getMove() != 'x');

    delete g;

    return 0;

}
