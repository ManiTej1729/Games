#include "state.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snake_utils.h"

/* Helper function definitions */
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch);
static bool is_tail(char c);
static bool is_head(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static char head_to_body(char c);
static unsigned int get_next_row(unsigned int cur_row, char c);
static unsigned int get_next_col(unsigned int cur_col, char c);
static void find_head(game_state_t* state, unsigned int snum);
static char next_square(game_state_t* state, unsigned int snum);
static void update_tail(game_state_t* state, unsigned int snum);
static void update_head(game_state_t* state, unsigned int snum);

/* Task 1 */
game_state_t* create_default_state() {
    // TODO: Implement this function.
    game_state_t *game_state = (game_state_t *)malloc(sizeof(game_state_t));
    game_state -> num_rows = 18;
    game_state -> board = (char **)malloc(game_state -> num_rows * sizeof(char *));
    for (int i = 0; i < 18; i++) {
        game_state -> board[i] = (char *)malloc(21 * sizeof(char)); 
    }
    game_state -> num_snakes = 1;
    strcpy(game_state -> board[0], "####################");
    strcpy(game_state -> board[game_state -> num_rows - 1], "####################");
    for (int j = 1; j < 17; j++) {
        strcpy(game_state -> board[j], "#                  #");
    }
    game_state -> snakes = (snake_t *)malloc(game_state -> num_snakes * sizeof(snake_t));
    // for (int q = 0; q < game_state -> num_rows; q++) {
    //   free(game_state -> board[q]);
    // }
    // free(game_state -> board);
    game_state -> snakes[0].tail_row = 2;
    game_state -> snakes[0].tail_col = 2;
    game_state -> snakes[0].head_row = 2;
    game_state -> snakes[0].head_col = 4;
    game_state -> snakes[0].live = true;
    game_state -> board[2][2] = 'd';
    game_state -> board[2][4] = 'D';
    game_state -> board[2][3] = '>';
    game_state -> board[2][9] = '*';
    return game_state;
}

/* Task 2 */
void free_state(game_state_t* state) {
  // TODO: Implement this function.
  if (state == NULL) {
    return;
  }
  if (state -> board != NULL) {
    for (int i = 0; i < state->num_rows; i++) {
      // printf("i = %d, num rows: %d\n", i, state -> num_rows);
      if (state -> board != NULL) { 
        // printf("inside free state: %p\n", state -> board[i]);
        // printf("free state: %lu\n", strlen(state -> board[i]));
        // printf("%p\n",&state -> board[i+1]);
        // printf("%s\n", state -> board[i]);
        if(state -> board[i] != NULL){
          free(state -> board[i]);
        }
        // free(state -> board[i]);
      }
    }
  } 
  // if (state -> snakes != NULL) {
    // free(state -> snakes);
  // }
  // if(!state){
  //   free(state);
  // }
  free(state);
  return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
  // TODO: Implement this function.
  for (int i = 0; i < state -> num_rows; i++) {
    fprintf(fp, "%s\n", state -> board[i]);
  }
  return;
}

/*
  Saves the current state into filename. Does not modify the state object.
  (already implemented for you).
*/
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */

/*
  Helper function to get a character from the board
  (already implemented for you).
*/

char get_board_at(game_state_t* state, unsigned int row, unsigned int col) {
  return state->board[row][col];
}

/*
  Helper function to set a character on the board
  (already implemented for you).
*/
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch) {
  state->board[row][col] = ch;
}

/*
  Returns true if c is part of the snake's tail.
  The snake consists of these characters: "wasd"
  Returns false otherwise.
*/
static bool is_tail(char c) {
  // TODO: Implement this function.
  if (c == 'a' || c == 's' || c == 'd' || c == 'w') {
    return true;
  }
  else {
    return false;
  }
  return true;
}

/*
  Returns true if c is part of the snake's head.
  The snake consists of these characters: "WASDx"
  Returns false otherwise.
*/
static bool is_head(char c) {
  // TODO: Implement this function.
  if (c == 'A' || c == 'S' || c == 'D' || c == 'W' || c == 'x') {
    return true;
  }
  else {
    return false;
  }
  return true;
}

/*
  Returns true if c is part of the snake.
  The snake consists of these characters: "wasd^<v>WASDx"
*/
static bool is_snake(char c) {
  // TODO: Implement this function.
  if (c == 'A' || c == 'S' || c == 'D' || c == 'W' || c == 'x' || c == 'a' || c == 's' || c == 'd' || c == 'w' || c == '>' || c == '^' || c == '<' || c == 'v') {
    return true;
  }
  else {
    return false;
  }
  return true;
}

/*
  Converts a character in the snake's body ("^<v>")
  to the matching character representing the snake's
  tail ("wasd").
*/
static char body_to_tail(char c) {
  // TODO: Implement this function.
  if (c == '<') {
    return 'a'; 
  }
  if (c == 'v') {
    return 's'; 
  }
  if (c == '>') {
    return 'd'; 
  }
  if (c == '^') {
    return 'w'; 
  }
  return '?';
}

/*
  Converts a character in the snake's head ("WASD")
  to the matching character representing the snake's
  body ("^<v>").
*/
static char head_to_body(char c) {
  // TODO: Implement this function.
  if (c == 'A') {
    return '<'; 
  }
  if (c == 'S') {
    return 'v'; 
  }
  if (c == 'D') {
    return '>'; 
  }
  if (c == 'W') {
    return '^'; 
  }
  return '?';
}

/*
  Returns cur_row + 1 if c is 'v' or 's' or 'S'.
  Returns cur_row - 1 if c is '^' or 'w' or 'W'.
  Returns cur_row otherwise.
*/
static unsigned int get_next_row(unsigned int cur_row, char c) {
  // TODO: Implement this function.
  if (c == 'v' || c == 's' || c == 'S') {
    return cur_row + 1;
  }
  if (c == '^' || c == 'w' || c == 'W') {
    // printf("hello?\n");
    return cur_row - 1;
  }
  // printf("is it?\n");
  return cur_row;
}

/*
  Returns cur_col + 1 if c is '>' or 'd' or 'D'.
  Returns cur_col - 1 if c is '<' or 'a' or 'A'.
  Returns cur_col otherwise.
*/
static unsigned int get_next_col(unsigned int cur_col, char c) {
  // TODO: Implement this function.
  if (c == '>' || c == 'd' || c == 'D') {
    return cur_col + 1;
  }
  if (c == '<' || c == 'a' || c == 'A') {
    // printf("hello?\n");
    return cur_col - 1;
  }
  return cur_col;
}

/*
  Task 4.2

  Helper function for update_state. Return the character in the cell the snake is moving into.

  This function should not modify anything.
*/
static char next_square(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  // printf("qwerty\n");
  // printf("%d %d\n", state -> snakes[snum].head_row, state -> snakes[snum].head_col);
  char insitu = get_board_at(state, state -> snakes[snum].head_row, state -> snakes[snum].head_col);
  if (is_head(insitu) && insitu != 'x') {
    return state -> board[get_next_row(state -> snakes[snum].head_row, insitu)][get_next_col(state -> snakes[snum].head_col, insitu)];
  }
  return '?';
}

/*
  Task 4.3

  Helper function for update_state. Update the head...

  ...on the board: add a character where the snake is moving

  ...in the snake struct: update the row and col of the head

  Note that this function ignores food, walls, and snake bodies when moving the head.
*/
static void update_head(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  char insitu = get_board_at(state, state -> snakes[snum].head_row, state -> snakes[snum].head_col);
  if (is_head(insitu) && insitu != 'x') {
    set_board_at(state, state -> snakes[snum].head_row, state -> snakes[snum].head_col, head_to_body(insitu));
    state -> snakes[snum].head_row = get_next_row(state -> snakes[snum].head_row, insitu);
    state -> snakes[snum].head_col = get_next_col(state -> snakes[snum].head_col, insitu);
    set_board_at(state, state -> snakes[snum].head_row, state -> snakes[snum].head_col, insitu);
  }
  return;
}

/*
  Task 4.4

  Helper function for update_state. Update the tail...

  ...on the board: blank out the current tail, and change the new
  tail from a body character (^<v>) into a tail character (wasd)

  ...in the snake struct: update the row and col of the tail
*/
static void update_tail(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  char insitu = get_board_at(state, state -> snakes[snum].tail_row, state -> snakes[snum].tail_col);
  if (is_tail(insitu)) {
    set_board_at(state, state -> snakes[snum].tail_row, state -> snakes[snum].tail_col, ' ');
    set_board_at(state, get_next_row(state -> snakes[snum].tail_row, insitu), get_next_col(state -> snakes[snum].tail_col, insitu), body_to_tail(get_board_at(state, get_next_row(state -> snakes[snum].tail_row, insitu), get_next_col(state -> snakes[snum].tail_col, insitu))));
    state -> snakes[snum].tail_row = get_next_row(state -> snakes[snum].tail_row, insitu);
    state -> snakes[snum].tail_col = get_next_col(state -> snakes[snum].tail_col, insitu);
    // set_board_at(state, state -> snakes[snum].tail_row, state -> snakes[snum].tail_col, insitu);
    // state -> board[state -> snakes[snum].tail_row][state -> snakes[snum].tail_col] = body_to_tail(get_board_at(state, state -> snakes[snum].tail_row, state -> snakes[snum].tail_col));
  }
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: Implement this function.
  // printf("%d\n", state -> num_snakes);
  for (unsigned int i = 0; i < state -> num_snakes; i++) {
    // printf("i: %d\n", i);
    // printf("head row: %d, head_col: %d\n", state -> snakes[i].head_row, state -> snakes[i].head_col);
    if (state -> snakes[i].live) {
      char ch = next_square(state, i);
      // printf("%c\n", ch);
      if (ch == '*') {
        // printf("one\n");
        update_head(state, i);
        add_food(state);
      }
      else if (ch == '#' || is_head(ch) || is_tail(ch) || is_snake(ch)) {
        // printf("two\n");
        set_board_at(state, state -> snakes[i].head_row, state -> snakes[i].head_col, 'x');
        state -> snakes[i].live = false;
      }
      else {
        // printf("three\n");
        update_head(state, i);
        update_tail(state, i);
      }
    }
  }
  
  return;
}

/* Task 5 */
game_state_t* load_board(FILE* fp) {
  // TODO: Implement this function.
  game_state_t *state = (game_state_t *)malloc(sizeof(game_state_t));
  state -> board = (char **)malloc(sizeof(char *));
  state -> board[0] = (char *)malloc(sizeof(char));
  char ch;
  unsigned int char_count = 0;
  unsigned int num_rows = 0;
  int flag = 0;
  // printf("fhuyw\n");
  while (!feof(fp)) {
    // printf("fubf\n");
    ch = (char) fgetc(fp);
    if (flag == 1) {
      state -> board = (char **)realloc(state -> board, (num_rows + 1) * sizeof(char *));
      state -> board[num_rows] = (char *)malloc(sizeof(char));
    }
    char_count++;
    state -> board[num_rows] = (char *)realloc(state -> board[num_rows], (char_count + 1) * sizeof(char));
    // if (char_count == 29) {
    //   printf("%d %lu\n", char_count, strlen(state -> board[num_rows]));
    // }
    if (ch != '\n') {
      state -> board[num_rows][char_count - 1] = ch;
      flag = 0;
    }
    else {
      state -> board[num_rows][char_count - 1] = '\0';
      // printf("%s %d\n", state -> board[num_rows], c);
      num_rows++;
      flag = 1;
      // printf("strlen: %lu\n", strlen(state -> board[num_rows - 1]));
      // printf("Load board address: %p\n", &state->board[num_rows - 1]);
      char_count = 0;
    }
  }
  state -> num_rows = num_rows;
  state -> num_snakes = 0;
  state -> snakes = NULL;
  // for (int i = 0; i < state -> num_rows; i++) {
  //   printf("%s\n", state -> board[i]);
  // }
  return state;
}

/*
  Task 6.1

  Helper function for initialize_snakes.
  Given a snake struct with the tail row and col filled in,
  trace through the board to find the head row and col, and
  fill in the head row and col in the struct.
*/
static void find_head(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  // printf("noob");
  unsigned int curr_row = state -> snakes[snum].tail_row;
  unsigned int curr_col = state -> snakes[snum].tail_col;
  // printf("\n");
  char ch = get_board_at(state, curr_row, curr_col);
  // printf("%c\n", ch);
  // printf("%d %d\n", curr_row, curr_col);
  // int num = 0;
  while (1) {
    // printf("infinite?\n");
    // for (int i = 0; i < state -> num_rows; i++) {
    //   printf("%s\n", state -> board[i]);
    // }
    curr_row = get_next_row(curr_row, ch);
    curr_col = get_next_col(curr_col, ch);
    ch = get_board_at(state, curr_row, curr_col);
    // printf("%c\n", get_board_at(state, curr_row, curr_col));
    // printf("%d %d\n", curr_row, curr_col);
    // for (int p = 0; p < state -> num_rows; p++) {
    //   printf("%s\n", state -> board[p]);
    // }
    // if (num < 10) {
    //   // printf("%d %d %c\n", curr_row, curr_col, state -> board[curr_row][curr_col]);
    //   if (ch == ' ') {
    //     // printf("space\n");
    //   }
    //   num++;
    // }
    if (is_head(ch)) {
      // printf("%d %d\n", curr_row, curr_col);
      state -> snakes[snum].head_row = curr_row;
      state -> snakes[snum].head_col = curr_col;
      break;
    }
  }
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  // TODO: Implement this function.
  // printf("num rows: %d\n", state -> num_rows);
  // printf("4d\n");
  state -> snakes = (snake_t *)malloc(sizeof(snake_t));
  state -> num_snakes = 0;
  for (int i = 0; i < state -> num_rows; i++) {
    int j = 0;
    unsigned int size_index = 1;
    // printf("2b\n");
    while (state -> board[i][j] != '\0') {
      // printf(" 1a\n");
      if (is_tail(state -> board[i][j])) {
        // printf("i j ch: %d %d %c", i, j, state -> board[i][j]);
        state -> snakes[state -> num_snakes].tail_row = (unsigned int) i;
        state -> snakes[state -> num_snakes].tail_col = (unsigned int) j;
        find_head(state, state -> num_snakes);
        // printf("\n");
        state -> snakes[state -> num_snakes].live = true;
        state -> num_snakes++;
        size_index++;
        state -> snakes = (snake_t *)realloc(state -> snakes, size_index * sizeof(snake_t)); 
      }
      j++;
    }
  }
  // printf("out\n");
  return state;
}
