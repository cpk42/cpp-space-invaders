#include <Invaders.hpp>

// Add to game class later
#define GAME_SPEED 75000


int main(void)
{
    Game* g = new Game("easy");
    Menu* m = new Menu();
    g->setDifficulty(m->selectDifficulty());
    Player* p = new Player(g->getGameWin(), g->getRowMax() - 1, g->getColMax() / 2, '^');
    Enemy *e_arr[1];
    for (int i = 0; i < 1; i ++)
        e_arr[i] = new Enemy(g->getGameWin(), 1, i * 2, 'o', 1);
    nodelay(g->getGameWin(), true);
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
        usleep(GAME_SPEED);
    } while(p->getMove() != 'x');

    delete g;

    return 0;

}
