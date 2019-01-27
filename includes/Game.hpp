#ifndef GAME_HPP_
#define GAME_HPP_

#include <Invaders.hpp>

class Game {
    public:
        Game(std::string difficulty);
        ~Game(void);

        WINDOW* getGameWin(void);
        WINDOW* getDisplayWin(void);

        void drawBorders(WINDOW* win);
        void checkResize(void);

        void displayWinInfo(void);
        int getColMax(void);
        int getRowMax(void);
        int getLives(void);


        void setDifficulty(std::string diff);
        void setLives(int lives);

    private:
        int colMax;
        int rowMax;
        int lives;
        int score;
        int displaySize;
        std::string difficulty;
        WINDOW* gameWin;
        WINDOW* displayWin;
};

#endif