#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void update_board(char (*board)[3], int pos, char ch) {
    if (pos % 3 != 0) {
        board[pos / 3][pos % 3 - 1] = ch;
    }
    else {
        board[(pos / 3) - 1][2] = ch;
    }
}

bool free_win(char (*board)[3]) {
    for (int i = 0; i < 3; i++) {
        int X_count = 0;
        int space_count = 0;
        int storage = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                X_count++;
            }
            else if (board[i][j] == ' ') {
                space_count++;
                storage = j;
            }
        }
        if (X_count == 2 && space_count == 1) {
            board[i][storage] = 'X';
            return true;
        }
    }
    for (int i = 0; i < 3; i++) {
        int X_count = 0;
        int space_count = 0;
        int storage = 0;
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == 'X') {
                X_count++;
            }
            else if (board[j][i] == ' ') {
                space_count++;
                storage = j;
            }
        }
        if (X_count == 2 && space_count == 1) {
            board[storage][i] = 'X';
            return true;
        }
    }
    int X_count = 0;
    int space_count = 0;
    int storage = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][i] == 'X') {
            X_count++;
        }
        else if (board[i][i] == ' ') {
            space_count++;
            storage = i;
        }
    }
    if (X_count == 2 && space_count == 1) {
        board[storage][storage] = 'X';
        return true;
    }
    X_count = 0;
    space_count = 0;
    storage = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][2 - i] == 'X') {
            X_count++;
        }
        else if (board[i][2 - i] == ' ') {
            space_count++;
            storage = i;
        }
    }
    if (X_count == 2 && space_count == 1) {
        board[storage][2 - storage] = 'X';
        return true;
    }
    return false;
}

void safe_play(char (*board)[3], int *ptr) {
    for (int i = 0; i < 3; i++) {
        int O_count = 0;
        int space_count = 0;
        int storage = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O') {
                O_count++;
            }
            else if (board[i][j] == ' ') {
                space_count++;
                storage = j;
            }
        }
        if (O_count == 2 && space_count == 1) {
            board[i][storage] = 'X';
            *ptr = 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        int O_count = 0;
        int space_count = 0;
        int storage = 0;
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == 'O') {
                O_count++;
            }
            else if (board[j][i] == ' ') {
                space_count++;
                storage = j;
            }
        }
        if (O_count == 2 && space_count == 1) {
            board[storage][i] = 'X';
            *ptr = 1;
        }
    }
    int O_count = 0;
    int space_count = 0;
    int storage = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][i] == 'O') {
            O_count++;
        }
        else if (board[i][i] == ' ') {
            space_count++;
            storage = i;
        }
    }
    if (O_count == 2 && space_count == 1) {
        board[storage][storage] = 'X';
        *ptr = 1;
    }
    O_count = 0;
    space_count = 0;
    storage = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][2 - i] == 'O') {
            O_count++;
        }
        else if (board[i][2 - i] == ' ') {
            space_count++;
            storage = i;
        }
    }
    if (O_count == 2 && space_count == 1) {
        board[storage][2 - storage] = 'X';
        *ptr = 1;
    }
}

bool corner_check(int pos) {
    if (pos == 1 || pos == 3 || pos == 7 || pos == 9) {
        return true;
    }
    return false;
}

bool mid_check(int pos) {
    if (pos == 2 || pos == 4 || pos == 6 || pos == 8) {
        return true;
    }
    return false;
}

void print_board(char (*board)[3]) {
    for (int i = 0; i < 3; i++) {
        printf("  %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("-------------\n");
        }
    }
}

char get_board_at(char (*board)[3], int pos) {
    if (pos % 3 != 0) {
        return board[pos / 3][pos % 3 - 1];
    }
    else {
        return board[(pos / 3) - 1][2];
    }
}

int leftover_index(char (*board)[3]) {
    for (int i = 1; i < 10; i++) {
        if (get_board_at(board, i) == ' ') {
            return i;
        }
    }
    return 0;
}

int genereate_intersection(int a, int b) {
    if (a == 1) {
        if (b == 6) {
            return 3;
        }
        else if (b == 8) {
            return 7;
        }
    }
    if (a == 3) {
        if (b == 4) {
            return 1;
        }
        else if (b == 8) {
            return 9;
        }
    }
    if (a == 7) {
        if (b == 2) {
            return 1;
        }
        else if (b == 6) {
            return 9;
        }
    }
    if (a == 9) {
        if (b == 2) {
            return 3;
        }
        else if (b == 4) {
            return 7;
        }
    }
    return 0;
}

bool adjacent(int a, int b) {
    if (a == 1) {
        if (b == 2 || b == 4) {
            return true;
        }
    }
    if (a == 3) {
        if (b == 2 || b == 6) {
            return true;
        }
    }
    if (a == 7) {
        if (b == 8 || b == 4) {
            return true;
        }
    }
    if (a == 9) {
        if (b == 6 || b == 8) {
            return true;
        }
    }
    return false;
}

int intersection(int a, int b) {
    if ((a == 2 && b == 4) || (a == 4 && b == 2)) {
        return 1;
    }
    if ((a == 2 && b == 6) || (a == 6 && b == 2)) {
        return 3;
    }
    if ((a == 8 && b == 4) || (a == 4 && b == 8)) {
        return 7;
    }
    if ((a == 6 && b == 8) || (a == 8 && b == 6)) {
        return 9;
    }
    return 0;
}

int main() {
    int player;
    int cheater[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int flag_for_safe_play = 0;
    int *ptr = &flag_for_safe_play;
    int flag_for_intersection = 0;
    int flag_for_fir_inp = 0;
    int flag_for_fir_inp_cen = 0;
    int flag_for_fir_inp_mid = 0;
    int flag2_for_fir_inp = 0;
    int flag_for_tie = 1;
    int flag_for_mid_win = 0;
    int flag_for_mid_tie = 0;
    int flag_for_mid_tie_mid = 0;
    int storage = 0;
    int corner_array[] = {1, 3, 7, 9};
    int mid_array[] = {2, 4, 6, 8};
    scanf("%d", &player);
    system("clear");
    if (player == 1) {
        char board[3][3] = {{' ', ' ', ' '},
                            {' ', ' ', ' '},
                            {' ', ' ', ' '}};
        print_board(board);
        int O;
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1);  // first input
        update_board(board, O, 'O');
        cheater[O - 1] = 1;
        if (corner_check(O)) {
            update_board(board, 5, 'X');
            cheater[4] = 1;
            flag_for_fir_inp = 1;
            storage = O;
        }
        else if (mid_check(O)) {
            update_board(board, 5, 'X');
            cheater[4] = 1;
            flag_for_fir_inp_mid = 1;
            storage = O;
        }
        else {
            update_board(board, 1, 'X');
            cheater[0] = 1;
            flag_for_fir_inp_cen = 1;
        }
        system("clear");
        print_board(board);
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1);  // second input
        update_board(board, O, 'O');
        cheater[O - 1] = 1;
        safe_play(board, ptr);
        if (flag_for_fir_inp == 1 && flag_for_safe_play == 0) {
            if (storage + O == 10 && corner_check(O) == true) {
                update_board(board, 2, 'X');
                cheater[1] = 1;
                flag2_for_fir_inp = 1;
            }
            else if (storage + O != 10 && corner_check(O) == true) {
                safe_play(board, ptr);
            }
            if (mid_check(O)) { 
                if (adjacent(storage, O)) {
                    safe_play(board, ptr);
                }
                else {
                    update_board(board, genereate_intersection(storage, O), 'X');
                    cheater[genereate_intersection(storage, O) - 1] = genereate_intersection(storage, O);
                    flag_for_intersection = 1;
                }
            }
        }
        else if (flag_for_fir_inp_cen == 1 && flag_for_safe_play == 0) { // O == 9
            update_board(board, 3, 'X');
            cheater[2] = 1;
        }
        else if (flag_for_safe_play == 0 && flag_for_fir_inp_mid == 1) {
            if (O == 10 - storage) {
                if (storage == 2 || storage == 8) {
                    update_board(board, storage + 1, 'X');
                    cheater[storage] = 1;
                }
                else if (storage == 4 || storage == 6) {
                    update_board(board, storage + 3, 'X');
                    cheater[storage + 2] = 1;
                }
                flag_for_mid_win = 1;
            }
            else {
                if (corner_check(O)) {
                    update_board(board, genereate_intersection(O, storage), 'X');
                    cheater[genereate_intersection(storage, O) - 1] = 1;
                }
                else if (mid_check(O)) {
                    update_board(board, intersection(storage, O), 'X');
                    cheater[intersection(storage, O) - 1] = 1;
                    flag_for_mid_tie_mid = 1;
                }
                flag_for_mid_tie = 1;
            }
        }
        system("clear");
        print_board(board);
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1);  // third input
        update_board(board, O, 'O');
        cheater[O - 1] = 1;
        flag_for_safe_play = 0;
        if (free_win(board)) {
            system("clear");
            print_board(board);
            printf(ANSI_COLOR_RED "You lost!\n" ANSI_COLOR_RESET);
            sleep(2);
            system("clear");
            flag_for_tie = 0;
            exit(0);
        }
        safe_play(board, ptr);
        if (flag2_for_fir_inp == 0 && flag_for_safe_play == 0 && corner_check(storage) == true) {
            for (int i = 0; i < 4; i++) {
                if (get_board_at(board, mid_array[i]) == ' ') {
                    update_board(board, mid_array[i], 'X');
                    cheater[mid_array[i] - 1] = 1;
                    break;
                }
            }
        }
        else if(flag_for_safe_play == 0 && flag_for_fir_inp_mid == 1 && flag_for_mid_win == 1) {
            storage = 10 - storage;
            if (storage == 2 || storage == 8) {
                update_board(board, storage + 1, 'X');
                cheater[storage] = 1;
            }
            else if (storage == 4 || storage == 6) {
                update_board(board, storage + 3, 'X');
                cheater[storage + 2] = 1;
            }
        }
        else if (flag_for_safe_play == 0 && flag_for_mid_tie == 1 && flag_for_mid_tie_mid == 1) {
            for (int i = 0; i < 4; i++) {
                if (get_board_at(board, corner_array[i]) == ' ') {
                    update_board(board, corner_array[i], 'X');
                    cheater[corner_array[i] - 1] = 1;
                    break;
                }
            }
        }
        system("clear");
        print_board(board);
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1);  // fourth input
        update_board(board, O, 'O');
        cheater[O - 1] = 1;
        flag_for_safe_play = 0;
        if (free_win(board)) {
            system("clear");
            print_board(board);
            printf(ANSI_COLOR_RED "You lost!\n" ANSI_COLOR_RESET);
            sleep(2);
            system("clear");
            flag_for_tie = 0;
            exit(0);
        }
        safe_play(board, ptr);
        if (flag_for_safe_play == 0) {
            update_board(board, leftover_index(board), 'X');
            cheater[leftover_index(board) - 1] = 1;
        }
        system("clear");
        print_board(board);
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1);  // fifth input
        cheater[O - 1] = 1;
        update_board(board, O, 'O');
        if (free_win(board)) {
            system("clear");
            print_board(board);
            printf(ANSI_COLOR_RED "You lost!\n" ANSI_COLOR_RESET);
            sleep(2);
            system("clear");
            flag_for_tie = 0;
            exit(0);
        }
        system("clear");
        print_board(board);
        if (flag_for_tie == 1) {
            printf(ANSI_COLOR_YELLOW "That's a TIE...\n" ANSI_COLOR_RESET); 
            sleep(2);
            system("clear");
        }
    }
    else if (player == 2) {
        char board[3][3] = {{'X', ' ', ' '},
                            {' ', ' ', ' '},
                            {' ', ' ', ' '}};
        print_board(board);
        int flag_for_corner_check = 0;
        int flag_for_mid_check = 0;
        int O;
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1);  // first input
        int store = O;
        update_board(board, O, 'O');
        cheater[O - 1] = 1;
        if (mid_check(O)) {
            if (O == 2 || O == 8) {
                update_board(board, 7, 'X');
                cheater[6] = 7;
            }
            else if (O == 4 || O == 6) {
                update_board(board, 3, 'X');
                cheater[2] = 3;
            }
            flag_for_mid_check = 1;
        }
        else if (corner_check(O)) {
            if (get_board_at(board, 3) == 'O') {
                update_board(board, 7, 'X');
                cheater[6] = 7;
            }
            else {
                update_board(board, 3, 'X');
                cheater[2] = 3;
            }
            flag_for_corner_check = 1;
        }
        else {
            update_board(board, 9, 'X');
            cheater[8] = 9;
        }
        system("clear");
        print_board(board);
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1);  // second input
        update_board(board, O, 'O');
        cheater[O - 1] = 1;
        if (free_win(board)) {
            system("clear");
            print_board(board);
            printf(ANSI_COLOR_RED "You lost!\n" ANSI_COLOR_RESET);
            sleep(2);
            system("clear");
            flag_for_tie = 0;
            exit(0);
        }
        if (flag_for_corner_check == 1) {
            for (int i = 0; i < 4; i++) {
                if (get_board_at(board, corner_array[i]) == ' ') {
                    update_board(board, corner_array[i], 'X');
                    cheater[corner_array[i] - 1] = corner_array[i];
                }
            }
        }
        else if (flag_for_mid_check == 1) {
            if (store == 2 || store == 4) {
                update_board(board, 9, 'X');
                cheater[8] = 9;
            }
            else if (store == 6) {
                update_board(board, 7, 'X');
                cheater[6] = 7;
            }
            else {
                update_board(board, 3, 'X');
                cheater[2] = 3;
            }
        }
        else {
            safe_play(board, ptr);
        }
        system("clear");
        print_board(board);
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1); // third input
        update_board(board, O, 'O');
        cheater[O - 1] = 1;
        if (free_win(board)) {
            system("clear");
            print_board(board);
            printf(ANSI_COLOR_RED "You lost!\n" ANSI_COLOR_RESET);
            sleep(2);
            system("clear");
            flag_for_tie = 0;
            exit(0);
        }
        safe_play(board, ptr);
        system("clear");
        print_board(board);
        do {
            scanf("%d", &O);
            system("clear");
            print_board(board);
        } while (cheater[O - 1] == 1);  // fourth input
        update_board(board, O, 'O');
        cheater[O - 1] = 1;
        if (free_win(board)) {
            system("clear");
            print_board(board);
            printf(ANSI_COLOR_RED "You lost!\n" ANSI_COLOR_RESET);
            sleep(2);
            system("clear");
            flag_for_tie = 0;
            exit(0);
        }
        update_board(board, leftover_index(board), 'X');
        cheater[leftover_index(board) - 1] = leftover_index(board);
        system("clear");
        print_board(board);
        if (flag_for_tie == 1) {
            printf(ANSI_COLOR_YELLOW "That's a TIE...\n" ANSI_COLOR_RESET);
            sleep(2); 
            system("clear");
        }
    }
    else if (player != 1 || player != 2) {
        printf("Enter a valid player number\n");
    }

    return 0;
}