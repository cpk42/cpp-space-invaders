#include <Invaders.hpp>

Menu::Menu(void) {

    // Get screen size
    getmaxyx(stdscr, rowMax, colMax);

    // Create window for user input
    menuWin = newwin(5, colMax - 20, (rowMax / 2) - 5, 10);
    box(menuWin, 0, 0);

    keypad(menuWin, true);
}

Menu::~Menu(void) {
    endwin();
}

Menu::Menu(Menu &other) {
    *this = other;
}

Menu& Menu::operator=(Menu const &rhs) {
    if (this != &rhs) {
        menuWin = rhs.menuWin;
        colMax = rhs.colMax;
        rowMax = rhs.rowMax;
    }
    return *this;
}

void Menu::printEasy() {
    int row = rowMax / 2 - 5;
    int col = colMax / 2 - 18;
    mvprintw(row, col," ______     ______     ______     __  __ \n");
    mvprintw(++row, col, "/\\  ___\\   /\\  __ \\   /\\  ___\\   /\\ \\_\\ \\\n");
    mvprintw(++row, col, "\\ \\  __\\   \\ \\  __ \\  \\ \\___  \\  \\ \\____ \\\n");
    mvprintw(++row, col, " \\ \\_____\\  \\ \\_\\ \\_\\  \\/\\_____\\  \\/\\_____\\\n");
    mvprintw(++row, col, "  \\/_____/   \\/_/\\/_/   \\/_____/   \\/_____/\n");
    mvprintw(++row, col + 15, "Press any key to start");
}

void Menu::printMedium() {
    int row = rowMax / 2 - 5;
    int col = colMax / 2 - 25;
    mvprintw(row, col, " __    __     ______     _____     __     __  __     __    __");
    mvprintw(++row, col, "/\\ \"-./  \\   /\\  ___\\   /\\  __-.  /\\ \\   /\\ \\/\\ \\   /\\ \"-./  \\");
    mvprintw(++row, col, "\\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\/\\ \\ \\ \\ \\  \\ \\ \\_\\ \\  \\ \\ \\-./\\ \\");
    mvprintw(++row, col, " \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\____-  \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\");
    mvprintw(++row, col, "  \\/_/  \\/_/   \\/_____/   \\/____/   \\/_/   \\/_____/   \\/_/  \\/_/");
    mvprintw(++row, col + 25, "Press any key to start");
}

void Menu::printHard() {
    int row = rowMax / 2 - 5;
    int col = colMax / 2 - 18;
    mvprintw(row, col, " __  __     ______     ______     _____ ");
    mvprintw(++row, col, "/\\ \\_\\ \\   /\\  __ \\   /\\  == \\   /\\  __-.");
    mvprintw(++row, col, "\\ \\  __ \\  \\ \\  __ \\  \\ \\  __<   \\ \\ \\/\\ \\");
    mvprintw(++row, col, " \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\ \\____-");
    mvprintw(++row, col, "  \\/_/\\/_/   \\/_/\\/_/   \\/_/ /_/   \\/____/");
    mvprintw(++row, col + 15, "Press any key to start");
}

std::string Menu::selectDifficulty()
{
    std::string choices[3] = {"easy", "medium", "hard"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for (int i = 0; i < 3; i++)
        {
            if(i == highlight)
                wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, i + 1, 1, choices[i].c_str());
            wattroff(menuWin, A_REVERSE);
        }
        choice = wgetch(menuWin);

        switch(choice)
        {
            case KEY_UP:
                highlight = --highlight == -1 ? 2 : highlight;
                break;
            case KEY_DOWN:
                highlight = ++highlight == 3 ? 0 : highlight;
                break;
            default:
                break;
        }
        if (choice == 10)
            break;
    }

    if (choices[highlight] == "easy")
        printEasy();
    else if (choices[highlight] == "medium")
        printMedium();
    else if (choices[highlight] == "hard")
        printHard();
    getch();
    return choices[highlight];
}