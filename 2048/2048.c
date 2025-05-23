#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <ncurses.h>

#include "2048.h"

int flag_edit = 0;

void print_board(char board[][100], int *ptr) {
    clear();
    for (int i = 0; i < 20; i++) {
        printw("%s\n", board[i]);
    }
    printw("SCORE: %d\n", *ptr);
    refresh();
}

void justified_print(char (*board)[100], int num_of_digits, int row, int col, char number[]) {
    for (int i = 0; i < num_of_digits; i++) {
        board[row][col - (num_of_digits / 2) + i] = number[i];
    }
}

char *clears(char (*board)[100], int row, int col) {
    char *move = (char *)malloc(4 * sizeof(char));
    int index = 0;
    int flag = 0;
    for (int i = -3; i < 4; i++) {
        if (board[row][col + i] != ' ') {
            move[index] = board[row][col + i];
            index++;
            board[row][col + i] = ' ';
            flag = 1;
        }
    }
    if (flag == 1) {
        return move;
    }
    return NULL;
}

bool is_empty(char board[][100], int row, int col) {
    row = 5 * row + 2;
    col = 10 * col + 4;
    if (board[row][col] == ' ') {
        return true;
    }
    return false;
}

void shift(char (*board)[100], int row1, int col1, int row2, int col2) {
    row1 = 5 * row1 + 2;
    col1 = 10 * col1 + 4;
    row2 = 5 * row2 + 2;
    col2 = 10 * col2 + 4;
    flag_edit = 1;
    char *move = clears(board, row1, col1);
    int num_of_digits = strlen(move);
    justified_print(board, num_of_digits, row2, col2, move);
}

int char_to_int(char str[]) {
    int size = strlen(str);
    int number = 0;
    for (int i = 0; i < size; i++) {
        number += ((int) str[i] - 48) * pow(10, size - i - 1);
    }
    return number;
}

int number_of_digits(int number) {
    int digits = 0;
    do {
        digits++;
        number = number / 10; 
    } while (number != 0);
    return digits;
}

void combine(char (*board)[100], int row1, int col1, int row2, int col2, int *score) {
    row1 = 5 * row1 + 2;
    col1 = 10 * col1 + 4;
    row2 = 5 * row2 + 2;
    col2 = 10 * col2 + 4;
    char *twice = clears(board, row1, col1);
    int number = 2 * char_to_int(twice);
    int digits = number_of_digits(number);
    sprintf(twice, "%d", number);
    justified_print(board, digits, row2, col2, twice);
    *score += number;
}

void random_initializer(char (*board)[100]) {
    int rand3;
    int rand4;
    do {
        rand3 = rand() % 4;
        rand4 = rand() % 4;
    } while (!is_empty(board, rand3, rand4));
    char initial[] = "2";
    justified_print(board, 1, 5 * (rand3) + 2, 10 * (rand4) + 4, initial);
}

int find_empty(char board[][100], int flag, int index) { // flag = 1 -> row, flag != 1 -> col
    if (flag == 1) {
        for (int i = 0; i < 4; i++) {
            if (is_empty(board, index, i)) {
                return i;
            }
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (is_empty(board, i, index)) {
                return i;
            }
        }
    }
    return -1;
}

int find_non_empty(char board[][100], int flag, int index, int start) {
    if (start == 0) {
        return -1;
    }
    if (flag == 1) {
        for (int i = start; i < 4; i++) {
            if (!is_empty(board, index, i)) {
                return i;
            }
        }
    }
    else {
        for (int i = start; i < 4; i++) {
            if (!is_empty(board, i, index)) {
                return i;
            }
        }
    }
    return -1;
}

int find_empty_rev(char board[][100], int flag, int index) { // flag = 1 -> row, flag != 1 -> col
    if (flag == 1) {
        for (int i = 3; i >= 0; i--) {
            if (is_empty(board, index, i)) {
                return i;
            }
        }
    }
    else {
        for (int i = 3; i >= 0; i--) {
            if (is_empty(board, i, index)) {
                return i;
            }
        }
    }
    return -1;
}

int find_non_empty_rev(char board[][100], int flag, int index, int start) {
    if (start == -2) {
        return -1;
    }
    if (flag == 1) {
        for (int i = start; i >= 0; i--) {
            if (!is_empty(board, index, i)) {
                return i;
            }
        }
    }
    else {
        for (int i = start; i >= 0; i--) {
            if (!is_empty(board, i, index)) {
                return i;
            }
        }
    }
    return -1;
}

void shift_left(char (*board)[100]) {
    int ptr1 = -1, ptr2 = 0;
    int score = 0;
    for (int i = 0; i < 4; i++) {
        while (1) {
            ptr1 = find_empty(board, 1, i);
            ptr2 = find_non_empty(board, 1, i, ptr1 + 1);
            if (ptr1 == -1 || ptr2 == -1) {
                break;
            }
            shift(board, i, ptr2, i, ptr1);
        }
    }
}

void shift_up(char (*board)[100]) {
    int ptr1 = -1, ptr2 = 0;
    int score = 0;
    for (int i = 0; i < 4; i++) {
        while (1) {
            ptr1 = find_empty(board, 0, i);
            ptr2 = find_non_empty(board, 0, i, ptr1 + 1);
            if (ptr1 == -1 || ptr2 == -1) {
                break;
            }
            shift(board, ptr2, i, ptr1, i);
        }
    }
}

void shift_right(char (*board)[100]) {
    int ptr1 = -1, ptr2 = 0;
    int score = 0;
    for (int i = 0; i < 4; i++) {
        while (1) {
            ptr1 = find_empty_rev(board, 1, i);
            ptr2 = find_non_empty_rev(board, 1, i, ptr1 - 1);
            if (ptr1 == -1 || ptr2 == -1) {
                break;
            }
            shift(board, i, ptr2, i, ptr1);
        }
    }
}

void shift_down(char (*board)[100]) {
    int ptr1 = -1, ptr2 = 0;
    int score = 0;
    for (int i = 0; i < 4; i++) {
        while (1) {
            ptr1 = find_empty_rev(board, 0, i);
            ptr2 = find_non_empty_rev(board, 0, i, ptr1 - 1);
            if (ptr1 == -1 || ptr2 == -1) {
                break;
            }
            shift(board, ptr2, i, ptr1, i);
        }
    }
}

char *get_at(char board[][100], int row, int col) {
    row = 5 * row + 2;
    col = 10 * col + 4;
    char *move = (char *)malloc(4 * sizeof(char));
    int index = 0;
    int flag = 0;
    for (int i = -3; i < 4; i++) {
        if (board[row][col + i] != ' ') {
            move[index] = board[row][col + i];
            index++;
            flag = 1;
        }
    }
    if (flag == 1) {
        return move;
    }
    return NULL;
}

void combine_left(char (*board)[100], int *score) {
    char *ptr1;
    char *ptr2;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if ((ptr1 = get_at(board, i, j)) != NULL && (ptr2 = get_at(board, i, j + 1)) != NULL) {
                if (strcmp(ptr1, ptr2) == 0) {
                    combine(board, i, j + 1, i, j, score);
                    shift_left(board);
                    flag_edit = 1;
                }
            }
        }
    }
}

void combine_up(char (*board)[100], int *score) {
    char *ptr1;
    char *ptr2;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if ((ptr1 = get_at(board, j, i)) != NULL && (ptr2 = get_at(board, j + 1, i)) != NULL) {
                if (strcmp(ptr1, ptr2) == 0) {
                    combine(board, j + 1, i, j, i, score);
                    shift_up(board);
                    flag_edit = 1;
                }
            }
        }
    }
}

void combine_right(char (*board)[100], int *score) {
    char *ptr1;
    char *ptr2;
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if ((ptr1 = get_at(board, i, j)) != NULL && (ptr2 = get_at(board, i, j - 1)) != NULL) {
                if (strcmp(ptr1, ptr2) == 0) {
                    combine(board, i, j - 1, i, j, score);
                    shift_right(board);
                    flag_edit = 1;
                }
            }
        }
    }
}

void combine_down(char (*board)[100], int *score) {
    char *ptr1;
    char *ptr2;
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if ((ptr1 = get_at(board, j, i)) != NULL && (ptr2 = get_at(board, j - 1, i)) != NULL) {
                if (strcmp(ptr1, ptr2) == 0) {
                    combine(board, j - 1, i, j, i, score);
                    shift_down(board);
                    flag_edit = 1;
                }
            }
        }
    }
}

bool combine_check(char board[][100]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((strcmp(get_at(board, i, j), get_at(board, i, j + 1))) * (strcmp(get_at(board, i, j), get_at(board, i + 1, j))) == 0) {
                return true;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (strcmp(get_at(board, i, 3), get_at(board, i + 1, 3)) == 0) {
            return true;
        }
        if (strcmp(get_at(board, 3, i), get_at(board, 3, i + 1)) == 0) {
            return true;
        }
    }
    return false;
}

void end_win(char board[][100], int *score) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[5 * i + 2][10 * j + 4] == ' ') {
                return;
            }
            if (strcmp(get_at(board, i, j), "2048") == 0) {
                print_board(board, score);
                printw("You Win!\n");
                refresh();
                getch();
                endwin();
                exit(0);
            }
        }
    }
    if (!combine_check(board)) {
        print_board(board, score);
        printw("You Lose!\n");
        refresh();
        getch();
        endwin();
        exit(0);
    }
}
