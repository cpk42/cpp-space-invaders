#include <ncurses.h>
#include <iostream>

int main(int argc, char **argv)
{
    // Ncurses start
    initscr();
    noecho();
    cbreak();

    // Get screen size
    int rowMax, colMax;
    getmaxyx(stdscr, rowMax, colMax);

    // Create window for user input
    WINDOW* menuwin = newwin(6, colMax - 12, rowMax - 8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);

    std::string choices[3] = {"easy", "medium", "hard"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for (int i = 0; i < 3; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

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

    printw("Your choice was: %s", choices[highlight].c_str());
    getch();

    // Free memory
    endwin();

    return 0;
}