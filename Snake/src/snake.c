#include <stdio.h>
#include <string.h>

#include "snake_utils.h"
#include "state.h"

int main(int argc, char* argv[]) {
  bool io_stdin = false;
  char* in_filename = NULL;
  char* out_filename = NULL;
  game_state_t* state = NULL;

  // Parse arguments
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-i") == 0 && i < argc - 1) {
      if (io_stdin) {
        fprintf(stderr, "Usage: %s [-i filename | --stdin] [-o filename]\n", argv[0]);
        return 1;
      }
      in_filename = argv[i + 1];
      i++;
      continue;
    } else if (strcmp(argv[i], "--stdin") == 0) {
      if (in_filename != NULL) {
        fprintf(stderr, "Usage: %s [-i filename | --stdin] [-o filename]\n", argv[0]);
        return 1;
      }
      io_stdin = true;
      continue;
    }
    if (strcmp(argv[i], "-o") == 0 && i < argc - 1) {
      out_filename = argv[i + 1];
      i++;
      continue;
    }
    fprintf(stderr, "Usage: %s [-i filename | --stdin] [-o filename]\n", argv[0]);
    return 1;
  }

  // Do not modify anything above this line.

  /* Task 7 */

  // Read board from file, or create default board
  // printf("0\n");
  if (in_filename != NULL) {
    // printf("1\n");
    // TODO: Load the board from in_filename
    // TODO: If the file doesn't exist, return -1
    // TODO: Then call initialize_snakes on the state you made
    FILE *fp1 = fopen(in_filename, "r");
    if (fp1 == NULL) {
      // printf("2\n");
      return -1;
    }
    // printf("22\n");
    state = load_board(fp1);
    // printf("9a\n");
    state = initialize_snakes(state);
    // printf("5e\n");
    fclose(fp1);
  } 
  else if (io_stdin) {
    // TODO: Load the board from stdin
    // TODO: Then call initialize_snakes on the state you made
    // printf("4\n");
    unsigned int num_rows = state -> num_rows;
    for (int lines = 0; lines < num_rows; lines++) {
      // printf("5\n");
      scanf("%s", state -> board[lines]);
    }
    save_board(state, "snake game");
    FILE *fp2 = fopen("snake game", "r");
    if (fp2 == NULL) {
      // printf("6\n");
      return -1;
    }
    state = load_board(fp2);
    state = initialize_snakes(state);
    fclose(fp2);
    // printf("7\n");
  } 
  else {
    // TODO: Create default state
    // printf("8\n");
    state = create_default_state();
  }
  // TODO: Update state. Use the deterministic_food function
  // printf("ok?\n");
  update_state(state, deterministic_food);
  // printf("segfault?\n");
  // Write updated board to file or stdout
  if (out_filename != NULL) {
    // printf("9\n");
    // TODO: Save the board to out_filename
    save_board(state, out_filename);
    // printf("saved\n");
  } 
  else {
    // printf("10\n");
    // TODO: Print the board to stdout
    // printf("is it done\n");
    for (int i = 0; i < state -> num_rows; i++) {
      // printf("11\n");
      int j = 0;
      while (1) {
        // printf("12\n");
        // printf("then why no?\n");
        if (state -> board[i][j] == '\0') {
          // printf("13\n");
          break;
        }
        printf("%c", state -> board[i][j]);
        j++;
        // printf("14\n");
      }
    }
  }
  // state -> snakes = NULL;
  // TODO: Free the state
  // printf("free?\n");
  free_state(state);

  return 0;
}
