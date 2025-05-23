#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asserts.h"
// Necessary due to static functions in state.c
#include "state.c"

/* Look at asserts.c for some helpful assert functions */

int greater_than_forty_two(int x) {
  return x > 42;
}

bool is_vowel(char c) {
  char* vowels = "aeiouAEIOU";
  for (int i = 0; i < strlen(vowels); i++) {
    if (c == vowels[i]) {
      return true;
    }
  }
  return false;
}

/*
  Example 1: Returns true if all test cases pass. False otherwise.
    The function greater_than_forty_two(int x) will return true if x > 42. False otherwise.
    Note: This test is NOT comprehensive
*/
bool test_greater_than_forty_two() {
  int testcase_1 = 42;
  bool output_1 = greater_than_forty_two(testcase_1);
  if (!assert_false("output_1", output_1)) {
    return false;
  }

  int testcase_2 = -42;
  bool output_2 = greater_than_forty_two(testcase_2);
  if (!assert_false("output_2", output_2)) {
    return false;
  }

  int testcase_3 = 4242;
  bool output_3 = greater_than_forty_two(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  return true;
}

/*
  Example 2: Returns true if all test cases pass. False otherwise.
    The function is_vowel(char c) will return true if c is a vowel (i.e. c is a,e,i,o,u)
    and returns false otherwise
    Note: This test is NOT comprehensive
*/
bool test_is_vowel() {
  char testcase_1 = 'a';
  bool output_1 = is_vowel(testcase_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }

  char testcase_2 = 'e';
  bool output_2 = is_vowel(testcase_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }

  char testcase_3 = 'i';
  bool output_3 = is_vowel(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char testcase_4 = 'o';
  bool output_4 = is_vowel(testcase_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char testcase_5 = 'u';
  bool output_5 = is_vowel(testcase_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }

  char testcase_6 = 'k';
  bool output_6 = is_vowel(testcase_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }

  return true;
}

/* Task 4.1 */

bool test_is_tail() {
  // TODO: Implement this function.
  char testcase_1 = 'a';
  bool output_1 = is_tail(testcase_1);
  if (!assert_true("character a", output_1)) {
    return false;
  }

  char testcase_2 = 's';
  bool output_2 = is_tail(testcase_2);
  if (!assert_true("character s", output_2)) {
    return false;
  }

  char testcase_3 = 'd';
  bool output_3 = is_tail(testcase_3);
  if (!assert_true("character d", output_3)) {
    return false;
  }

  char testcase_4 = 'w';
  bool output_4 = is_tail(testcase_4);
  if (!assert_true("character w", output_4)) {
    return false;
  }

  char testcase_5 = 'x';
  bool output_5 = is_tail(testcase_5);
  if (!assert_false("character x", output_5)) {
    return false;
  }

  char testcase_6 = 'm';
  bool output_6 = is_tail(testcase_6);
  if (!assert_false("character m", output_6)) {
    return false;
  }

  char testcase_7 = 'G';
  bool output_7 = is_tail(testcase_7);
  if (!assert_false("character G", output_7)) {
    return false;
  }

  char testcase_8 = 'R';
  bool output_8 = is_tail(testcase_8);
  if (!assert_false("character R", output_8)) {
    return false;
  }
    
  return true;
}

bool test_is_head() {
  // TODO: Implement this function.
  char testcase_1 = 'A';
  bool output_1 = is_head(testcase_1);
  if (!assert_true("character A", output_1)) {
    return false;
  }

  char testcase_2 = 'S';
  bool output_2 = is_head(testcase_2);
  if (!assert_true("character S", output_2)) {
    return false;
  }

  char testcase_3 = 'D';
  bool output_3 = is_head(testcase_3);
  if (!assert_true("character D", output_3)) {
    return false;
  }

  char testcase_4 = 'W';
  bool output_4 = is_head(testcase_4);
  if (!assert_true("character W", output_4)) {
    return false;
  }

  char testcase_5 = 'x';
  bool output_5 = is_head(testcase_5);
  if (!assert_true("character x", output_5)) {
    return false;
  }

  char testcase_6 = 'm';
  bool output_6 = is_head(testcase_6);
  if (!assert_false("character m", output_6)) {
    return false;
  }

  char testcase_7 = 'G';
  bool output_7 = is_head(testcase_7);
  if (!assert_false("character G", output_7)) {
    return false;
  }

  char testcase_8 = 'R';
  bool output_8 = is_head(testcase_8);
  if (!assert_false("character R", output_8)) {
    return false;
  }
   
  return true;
}

bool test_is_snake() {
  // TODO: Implement this function.
  char testcase_1 = 'A';
  bool output_1 = is_snake(testcase_1);
  if (!assert_true("character A", output_1)) {
    return false;
  }

  char testcase_2 = 'S';
  bool output_2 = is_snake(testcase_2);
  if (!assert_true("character S", output_2)) {
    return false;
  }

  char testcase_3 = 'D';
  bool output_3 = is_snake(testcase_3);
  if (!assert_true("character D", output_3)) {
    return false;
  }

  char testcase_4 = 'W';
  bool output_4 = is_snake(testcase_4);
  if (!assert_true("character W", output_4)) {
    return false;
  }

  char testcase_5 = 'x';
  bool output_5 = is_snake(testcase_5);
  if (!assert_true("character x", output_5)) {
    return false;
  }

  char testcase_6 = 'm';
  bool output_6 = is_snake(testcase_6);
  if (!assert_false("character m", output_6)) {
    return false;
  }

  char testcase_7 = 'G';
  bool output_7 = is_snake(testcase_7);
  if (!assert_false("character G", output_7)) {
    return false;
  }

  char testcase_8 = 'R';
  bool output_8 = is_snake(testcase_8);
  if (!assert_false("character R", output_8)) {
    return false;
  }

  char testcase_9 = 'a';
  bool output_9 = is_snake(testcase_9);
  if (!assert_true("character a", output_9)) {
    return false;
  }

  char testcase_10 = 's';
  bool output_10 = is_snake(testcase_10);
  if (!assert_true("character s", output_10)) {
    return false;
  }

  char testcase_11 = 'd';
  bool output_11 = is_snake(testcase_11);
  if (!assert_true("character d", output_11)) {
    return false;
  }

  char testcase_12 = 'w';
  bool output_12 = is_snake(testcase_12);
  if (!assert_true("character w", output_12)) {
    return false;
  }

  return true;
}

bool test_body_to_tail() {
  // TODO: Implement this function.  assert_equals_char
  char testcase_1 = '<';
  char output_1 = 'a';
  if (!assert_equals_char("output", output_1, body_to_tail(testcase_1))) {
    return false;
  }

  char testcase_2 = 'v';
  char output_2 = 's';
  if (!assert_equals_char("output", output_2, body_to_tail(testcase_2))) {
    return false;
  }

  char testcase_3 = '>';
  char output_3 = 'd';
  if (!assert_equals_char("output", output_3, body_to_tail(testcase_3))) {
    return false;
  }

  char testcase_4 = '^';
  char output_4 = 'w';
  if (!assert_equals_char("output", output_4, body_to_tail(testcase_4))) {
    return false;
  }

  char testcase_5 = 'p';
  char output_5 = '?';
  if (!assert_equals_char("output", output_5, body_to_tail(testcase_5))) {
    return false;
  }

  char testcase_6 = '&';
  char output_6 = '?';
  if (!assert_equals_char("output", output_6, body_to_tail(testcase_6))) {
    return false;
  }

  char testcase_7 = '\n';
  char output_7 = '?';
  if (!assert_equals_char("output", output_7, body_to_tail(testcase_7))) {
    return false;
  }

  char testcase_8 = '9';
  char output_8 = '?';
  if (!assert_equals_char("output", output_8, body_to_tail(testcase_8))) {
    return false;
  }

  char testcase_9 = 'T';
  char output_9 = '?';
  if (!assert_equals_char("output", output_9, body_to_tail(testcase_9))) {
    return false;
  }

  return true;
}

bool test_head_to_body() {
  // TODO: Implement this function.
  char testcase_1 = 'A';
  char output_1 = '<';
  if (!assert_equals_char("output", output_1, head_to_body(testcase_1))) {
    return false;
  }

  char testcase_2 = 'S';
  char output_2 = 'v';
  if (!assert_equals_char("output", output_2, head_to_body(testcase_2))) {
    return false;
  }

  char testcase_3 = 'D';
  char output_3 = '>';
  if (!assert_equals_char("output", output_3, head_to_body(testcase_3))) {
    return false;
  }

  char testcase_4 = 'W';
  char output_4 = '^';
  if (!assert_equals_char("output", output_4, head_to_body(testcase_4))) {
    return false;
  }

  char testcase_5 = 'p';
  char output_5 = '?';
  if (!assert_equals_char("output", output_5, head_to_body(testcase_5))) {
    return false;
  }

  char testcase_6 = '&';
  char output_6 = '?';
  if (!assert_equals_char("output", output_6, head_to_body(testcase_6))) {
    return false;
  }

  char testcase_7 = '\n';
  char output_7 = '?';
  if (!assert_equals_char("output", output_7, head_to_body(testcase_7))) {
    return false;
  }

  char testcase_8 = '9';
  char output_8 = '?';
  if (!assert_equals_char("output", output_8, head_to_body(testcase_8))) {
    return false;
  }

  char testcase_9 = 'T';
  char output_9 = '?';
  if (!assert_equals_char("output", output_9, head_to_body(testcase_9))) {
    return false;
  }
  return true;
}

bool test_get_next_row() {
  // TODO: Implement this function.
  char testcase_1 = 's';
  unsigned int test_case_1 = 3;
  int output_1 = 4;
  if (!assert_equals_int("output", output_1, (int) get_next_row(test_case_1, testcase_1))) {
    return false;
  }

  char testcase_2 = 'S';
  unsigned int test_case_2 = 4;
  int output_2 = 5;
  if (!assert_equals_int("output", output_2, (int) get_next_row(test_case_2, testcase_2))) {
    return false;
  }

  char testcase_3 = 'v';
  unsigned int test_case_3 = 5;
  int output_3 = 6;
  if (!assert_equals_int("output", output_3, (int) get_next_row(test_case_3, testcase_3))) {
    return false;
  }

  char testcase_4 = 'w';
  unsigned int test_case_4 = 3;
  int output_4 = 2;
  if (!assert_equals_int("output", output_4, (int) get_next_row(test_case_4, testcase_4))) {
    return false;
  }

  char testcase_5 = 'W';
  unsigned int test_case_5 = 4;
  int output_5 = 3;
  if (!assert_equals_int("output", output_5, (int) get_next_row(test_case_5, testcase_5))) {
    return false;
  }

  char testcase_6 = '^';
  unsigned int test_case_6 = 5;
  int output_6 = 4;
  if (!assert_equals_int("output", output_6, (int) get_next_row(test_case_6, testcase_6))) {
    return false;
  }

  char testcase_7 = 'a';
  unsigned int test_case_7 = 3;
  int output_7 = 3;
  if (!assert_equals_int("output", output_7, (int) get_next_row(test_case_7, testcase_7))) {
    return false;
  }

  char testcase_8 = 'D';
  unsigned int test_case_8 = 4;
  int output_8 = 4;
  if (!assert_equals_int("output", output_8, (int) get_next_row(test_case_8, testcase_8))) {
    return false;
  }

  char testcase_9 = '<';
  unsigned int test_case_9 = 5;
  int output_9 = 5;
  if (!assert_equals_int("output", output_9, (int) get_next_row(test_case_9, testcase_9))) {
    return false;
  }

  return true;
}

bool test_get_next_col() {
  // TODO: Implement this function.
  char testcase_1 = 'd';
  unsigned int test_case_1 = 3;
  int output_1 = 4;
  if (!assert_equals_int("output", output_1, (int) get_next_col(test_case_1, testcase_1))) {
    return false;
  }

  char testcase_2 = 'D';
  unsigned int test_case_2 = 4;
  int output_2 = 5;
  if (!assert_equals_int("output", output_2, (int) get_next_col(test_case_2, testcase_2))) {
    return false;
  }

  char testcase_3 = '>';
  unsigned int test_case_3 = 5;
  int output_3 = 6;
  if (!assert_equals_int("output", output_3, (int) get_next_col(test_case_3, testcase_3))) {
    return false;
  }

  char testcase_4 = 'a';
  unsigned int test_case_4 = 3;
  int output_4 = 2;
  if (!assert_equals_int("output", output_4, (int) get_next_col(test_case_4, testcase_4))) {
    return false;
  }

  char testcase_5 = 'A';
  unsigned int test_case_5 = 4;
  int output_5 = 3;
  if (!assert_equals_int("output", output_5, (int) get_next_col(test_case_5, testcase_5))) {
    return false;
  }

  char testcase_6 = '<';
  unsigned int test_case_6 = 5;
  int output_6 = 4;
  if (!assert_equals_int("output", output_6, (int) get_next_col(test_case_6, testcase_6))) {
    return false;
  }

  char testcase_7 = 'w';
  unsigned int test_case_7 = 3;
  int output_7 = 3;
  if (!assert_equals_int("output", output_7, (int) get_next_col(test_case_7, testcase_7))) {
    return false;
  }

  char testcase_8 = 'S';
  unsigned int test_case_8 = 4;
  int output_8 = 4;
  if (!assert_equals_int("output", output_8, (int) get_next_col(test_case_8, testcase_8))) {
    return false;
  }

  char testcase_9 = '^';
  unsigned int test_case_9 = 5;
  int output_9 = 5;
  if (!assert_equals_int("output", output_9, (int) get_next_col(test_case_9, testcase_9))) {
    return false;
  }
  return true;
}

bool test_customs() {
  if (!test_greater_than_forty_two()) {
    printf("%s\n", "test_greater_than_forty_two failed.");
    return false;
  }
  if (!test_is_vowel()) {
    printf("%s\n", "test_is_vowel failed.");
    return false;
  }
  if (!test_is_tail()) {
    printf("%s\n", "test_is_tail failed");
    return false;
  }
  if (!test_is_head()) {
    printf("%s\n", "test_is_head failed");
    return false;
  }
  if (!test_is_snake()) {
    printf("%s\n", "test_is_snake failed");
    return false;
  }
  if (!test_body_to_tail()) {
    printf("%s\n", "test_body_to_tail failed");
    return false;
  }
  if (!test_head_to_body()) {
    printf("%s\n", "test_head_to_body failed");
    return false;
  }
  if (!test_get_next_row()) {
    printf("%s\n", "test_get_next_row failed");
    return false;
  }
  if (!test_get_next_col()) {
    printf("%s\n", "test_get_next_col failed");
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  init_colors();

  if (!test_and_print("custom", test_customs)) {
    return 0;
  }

  return 0;
}
