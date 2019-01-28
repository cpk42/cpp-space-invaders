#include <Invaders.hpp>

void makeFormation(Enemy* e_arr[], Game *g) {
    char enemies[4] = {'o', 'O', '0', '@'};
    for (int i = 0; i < 20; i++) {
        e_arr[i] = new Enemy(g->getGameWin(), 1, (i + 1) * 3, enemies[rand() % 4], 1);
    }
    for (int i = 20; i < 40; i++) {
        e_arr[i] = new Enemy(g->getGameWin(), 2, (i - 20 + 2) * 3, enemies[rand() % 4], 1);
    }
    for (int i = 40; i < 60; i++) {
        e_arr[i] = new Enemy(g->getGameWin(), 3, (i - 40 + 3) * 3, enemies[rand() % 4], 1);
    }
}


int main(void)
{

    srand(0);
    int clock = 0;
    int done;

    Game* g = new Game("easy");
    Menu* m = new Menu();
    g->setDifficulty(m->selectDifficulty());
    Player* p = new Player(g->getGameWin(), g->getRowMax() - 1, g->getColMax() / 2, '^');
    Enemy *e_arr[60];
    makeFormation(e_arr, g);
    nodelay(g->getGameWin(), true);
    do {
        done = 1;
        for (int i = 0; i < 60; i++) {
            if (e_arr[i]->isValid()) {
                e_arr[i]->display(g, e_arr, p);
                done = 0;
            }    
        }
       // while (p->isShooting())
       //  p->fire();
        p->display();
        g->checkResize();
        if (g->getLives() <= 0 || done)
            break;
        if (clock % 10 == 0 && clock < 100)
            g->drawBorders(g->getGameWin());
        clock++;
        
        usleep(g->getGameSpeed());
    } while(p->getMove() != 'x');
    
    g->deathScreen();
    while (getch() != 10);

    delete g;

    return 0;
}
