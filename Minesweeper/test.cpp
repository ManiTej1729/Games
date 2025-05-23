#include <ncurses.h>

int main() {
    initscr(); // Initialize ncurses
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL); // Enable all mouse events
    // mousemask(0, NULL);

    int ch;
    MEVENT event;

    while ((ch = getch()) != KEY_F(1)) {
        if (ch == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                // Move the cursor to the position where the mouse was clicked
                move(event.y, event.x);

                // Check for left mouse button click
                if (event.bstate & BUTTON1_CLICKED) {
                    printw("l");
                }
                // Check for right mouse button click
                else if (event.bstate & BUTTON3_CLICKED) {
                    printw("r");
                }

                refresh(); // Refresh the screen
            }
        }
    }

    endwin(); // End ncurses

    return 0;
}
