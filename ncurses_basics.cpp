#include <ncurses.h>

int main(int argc, char **argv)
{
    // initialize screen, sets up memory, clears the screen
    initscr();

    // Make ctrl + c exit from ncurses
    cbreak();

    // Does not accept special characters
    //raw();

    // Whatever user types does not show on screen
    noecho();

    // Create new window
    int height = 10;
    int width = 20;
    int row = 5;
    int col = 5;
    WINDOW * win = newwin(height, width, row, col);
    refresh();

    /* NUCURSES ATTRIBUTES 
     * A_NORMAL
     * A_STANDOUT
     * A_REVERSE
     * A_BLINK
     * A_DIM
     * A_BOLD
     * A_PROTECT
     * A_INVIS
     * A_ALTCHARSET
     * A_CHARTEXT
     */

    attron(A_REVERSE);
    printw("Reverse text\n");
    attroff(A_REVERSE);

    /* COLORS
     * COLOR_PAIR(n)
     * COLOR_BLACK
     * COLOR_RED
     * COLOR_GREEN
     * COLOR_YELLOW
     * COLOR_BLUE
     * COLOR_MAGENTA
     */

    if (!has_colors())
    {
        printw("Terminal does not support colors");
        getch();
        return -1;
    }

    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("This is some text");
    attroff(COLOR_PAIR(1));

    // get row / col information
    int cur_row, cur_col, begin_row, begin_col, max_row, max_col;
    getyx(stdscr, cur_row, cur_col);
    getbegyx(stdscr, begin_row, begin_col);
    getmaxyx(stdscr, max_row, max_col);
    printw("%d, %d, %d, %d, %d, %d", cur_row, cur_col, begin_row, begin_col, max_row, max_col);

    // put border around window and output to screen, input can be character code for border
    box(win, '*', 0);

    // print to a specific window & refresh specific window
    wprintw(win, "a great box");
    wrefresh(win);

    // move cursor and print at specific location
    mvwprintw(win, 1, 1, "in the box");
    wrefresh(win);

    // moves cursor to the specified lovation (10 lines down, 15 columns over)
    move(10, 15);

    // prints a string (const char *) to the window
    printw("Hola mundo");

    // Refreshes screen to match what's in memory
    refresh();

    // waits for user input, returns int value of that key
    int c = getch();
    
    // clears the screen
    clear();

    // move and print
    mvprintw(0, 0, "%d", c);

    getch();

    // deallocates memory and ends ncurses
    endwin();
}