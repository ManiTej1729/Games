#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

void REMOVE(int (*arr), int n) {
    for (int i = 0; i < 9; i++) {
        if (arr[i] == n) {
            arr[i] = 0;
            return;
        }
    }
}

int *box_indices(int row, int col) {
    int ROW = row/3;
    int COL = col/3;
    int *indices =(int *) malloc(sizeof(int[9][2]));
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            indices[2 * index] = 3*ROW + i;
            indices[2 * index + 1] = 3*COL + j;
            index++;
        }
    }
    return indices;
}

int *availablity(int arr[][9], int row, int col, int col_array[]) {
    int temp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *box = box_indices(row, col);
    for (int i = 0; i < 9; i++) {
        if (arr[row][i] != 0) {
            temp[arr[row][i] - 1] = 0;
        }
        if (col_array[i] != 0) {
            temp[col_array[i] - 1] = 0;
        }
        if (arr[box[2 * i]][box[2 * i + 1]] != 0) {
            temp[arr[box[2 * i]][box[2 * i + 1]] - 1] = 0;
        }
    }
    int *final = (int *)malloc(9 * sizeof(int));
    for (int q = 0; q < 9; q++) {
        final[q] = temp[q];
    }
    return final;
}

int *find_zero(int arr[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) {
                int *array = (int *)malloc(2 * sizeof(int));
                array[0] = i;
                array[1] = j;
                return array;
            }
        }
    }
    return NULL;
}

void update_availability(int arr[][9], int (*avail)[9][9], int row, int col) {
    int add = arr[row][col];
    for (int i = 0; i < 9; i++) {
        if (arr[row][i] == 0) {
            REMOVE(avail[row][i], add);
        }
    }
    for (int i = 0; i < 9; i++) {
        if (arr[i][col] == 0) {
            REMOVE(avail[i][col], add);
        }
    }
    int *box = box_indices(row, col);
    for (int i = 0; i < 18; i += 2) {
        if (arr[box[i]][box[i + 1]] == 0) {
            REMOVE(avail[box[i]][box[i + 1]], add);
        }
    }
}

void remove_update(int arr[][9], int (*avail)[9][9], int row, int col) {
    int col_array[9];
    for (int i = 0; i < 9; i++) {
        if (arr[row][i] == 0 && i != col) {
            for (int j = 0; j < 9; j++) {
                col_array[j] = arr[j][i];
            }
            int *temp2 = availablity(arr, row, i, col_array);
            for (int j = 0; j < 9; j++) {
                avail[row][i][j] = temp2[j]; 
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (arr[i][col] == 0 && i != row) {
            for (int j = 0; j < 9; j++) {
                col_array[j] = arr[j][col];
            }
            int *temp3 = availablity(arr, i, col, col_array);
            for (int j = 0; j < 9; j++) {
                avail[i][col][j] = temp3[j];
            }
        }
    }
    int *box = box_indices(row, col);
    for (int i = 0; i < 18; i += 2) {
        if (arr[box[i]][box[i + 1]] == 0 && (box[i] != row || box[i + 1] != col)) {
            for (int j = 0; j < 9; j++) {
                col_array[j] = arr[j][box[i + 1]];
            }
            int *temp4 = availablity(arr, box[i], box[i + 1], col_array);
            for (int j = 0; j < 9; j++) {
                avail[box[i]][box[i + 1]][j] = temp4[j]; 
            }
        }
    }
}

void print_to_screen(int arr[][9]) {
    clear();
    printw("------------- ------------- -------------\n");
    for (int i = 0; i < 9; i++) {
        printw("|");
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) {
                printw("   |");
            }
            else {
                printw(" %d |", arr[i][j]);
            }
            if (j == 2 || j == 5) {
                printw(" |");
            }
        }
        printw("\n------------- ------------- -------------\n");
        if (i == 2 || i == 5) {
            printw("------------- ------------- -------------\n");
        }
    }
    refresh();
    napms(10);
}

int solve(int (*arr)[9], int (*avail)[9][9]) {
    if (find_zero(arr) == NULL) {
        return 1;
    }
    int *array = find_zero(arr);
    for (int i = 0; i < 9; i++) {
        if (avail[array[0]][array[1]][i] == 0) {
            continue;
        }
        arr[array[0]][array[1]] = avail[array[0]][array[1]][i];
        print_to_screen(arr);
        update_availability(arr, avail, array[0], array[1]);
        if (solve(arr, avail) == 1) {
            return 1;
        }
        else {
            arr[array[0]][array[1]] = 0;
            print_to_screen(arr);
            remove_update(arr, avail, array[0], array[1]);
        }
    }
    return 0;
}

int main() {
    int arr[9][9];
    // Open the input file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input.txt\n");
        return 1;
    }
    
    // Read Sudoku board from file
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (fscanf(file, "%d", &arr[i][j]) != 1) {
                printf("Error reading from input.txt\n");
                fclose(file);
                return 1;
            }
        }
    }
    initscr();
    curs_set(0);
    print_to_screen(arr);
    int col_array[9][9]; 
    for (int l = 0; l < 9; l++) {
        for (int m = 0; m < 9; m++) {
            col_array[l][m] = arr[m][l];
        }
    }
    int available[9][9][9]; 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int *temp = availablity(arr, i, j, col_array[j]);
            for (int k = 0; k < 9; k++) {
                available[i][j][k] = temp[k];
            }
        }
    }
    solve(arr, available);
    print_to_screen(arr);
    getch();
    endwin();
    return 0;
}
