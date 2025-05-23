#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <ncurses.h>

extern int flag_edit;

void print_board(char board[][100], int *ptr);
void justified_print(char (*board)[100], int num_of_digits, int row, int col, char number[]);
char *clears(char (*board)[100], int row, int col);
bool is_empty(char board[][100], int row, int col);
void shift(char (*board)[100], int row1, int col1, int row2, int col2);
int char_to_int(char str[]);
int number_of_digits(int number);
void combine(char (*board)[100], int row1, int col1, int row2, int col2, int *score);
void random_initializer(char (*board)[100]);
int find_empty(char board[][100], int flag, int index);
int find_non_empty(char board[][100], int flag, int index, int start);
int find_empty_rev(char board[][100], int flag, int index);
int find_non_empty_rev(char board[][100], int flag, int index, int start);
void shift_left(char (*board)[100]);
void shift_up(char (*board)[100]);
void shift_right(char (*board)[100]);
void shift_down(char (*board)[100]);
char *get_at(char board[][100], int row, int col);
void combine_left(char (*board)[100], int *score);
void combine_up(char (*board)[100], int *score);
void combine_right(char (*board)[100], int *score);
void combine_down(char (*board)[100], int *score);
bool combine_check(char board[][100]);
void end_win(char board[][100], int *score);