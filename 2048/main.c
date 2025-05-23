#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <ncurses.h>

#include "2048.h"

int main() {

    char board[100][100] = {"--------- --------- --------- ---------",
                            "|       | |       | |       | |       |",
                            "|       | |       | |       | |       |",
                            "|       | |       | |       | |       |",
                            "--------- --------- --------- ---------",
                            "--------- --------- --------- ---------",
                            "|       | |       | |       | |       |",
                            "|       | |       | |       | |       |",
                            "|       | |       | |       | |       |",
                            "--------- --------- --------- ---------",
                            "--------- --------- --------- ---------",
                            "|       | |       | |       | |       |",
                            "|       | |       | |       | |       |",
                            "|       | |       | |       | |       |",
                            "--------- --------- --------- ---------",
                            "--------- --------- --------- ---------",
                            "|       | |       | |       | |       |",
                            "|       | |       | |       | |       |",
                            "|       | |       | |       | |       |",
                            "--------- --------- --------- ---------"};
    int score = 0;
    srand(time(NULL));
    int rand1 = rand() % 4;
    int rand2 = rand() % 4;
    int rand3;
    int rand4;
    do {
        rand3 = rand() % 4;
        rand4 = rand() % 4;
    } while (rand3 == rand1 && rand4 == rand2);
    char start[] = "2";
    justified_print(board, 1, 5 * (rand1) + 2, 10 * (rand2) + 4, start);
    justified_print(board, 1, 5 * (rand3) + 2, 10 * (rand4) + 4, start);
    int ch;
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(1));
    curs_set(0);
    keypad(stdscr, TRUE);
    print_board(board, &score);
    noecho();
    while (1) {
        ch = getch();
        flag_edit = 0;
        if (ch == 'a' || ch == 'A' || ch == KEY_LEFT) {
            shift_left(board);
            combine_left(board, &score);
        }
        if (ch == 's' || ch == 'S' || ch == KEY_DOWN) {
            shift_down(board);
            combine_down(board, &score);
        }
        if (ch == 'd' || ch == 'D' || ch == KEY_RIGHT) {
            shift_right(board);
            combine_right(board, &score);
        }
        if (ch == 'w' || ch == 'W' || ch == KEY_UP) {
            shift_up(board);
            combine_up(board, &score);
        }
        end_win(board, &score);
        if (flag_edit == 1) {
            random_initializer(board);
            end_win(board, &score);
        }
        print_board(board, &score);
    }
    return 0;
}