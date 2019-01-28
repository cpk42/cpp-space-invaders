#ifndef GAME_HPP_
#define GAME_HPP_

#include <Invaders.hpp>

class Game {
    public:
        Game(void);
        Game(std::string difficulty);
        ~Game(void);
        Game(Game &other);
        Game &operator=(Game const &rhs);

        WINDOW* getGameWin(void);
        WINDOW* getDisplayWin(void);

        void drawBorders(WINDOW* win);
        void checkResize(void);
        void deathScreen(void);

        void displayWinInfo(void);
        int getColMax(void);
        int getRowMax(void);
        int getLives(void);
        int getGameSpeed(void);
        int getDirection(void);
        int getScore(void);

        void setDifficulty(std::string diff);
        void setLives(int lives);
        void setDirection(int dir);
        void setScore(int score);

    private:
        int colMax;
        int rowMax;
        int lives;
        int score;
        int displaySize;
        int gameSpeed;
        int direction;
        std::string difficulty;
        WINDOW* gameWin;
        WINDOW* displayWin;
};

#endif