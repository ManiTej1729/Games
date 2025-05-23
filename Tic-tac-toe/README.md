# Tic-tac-toe Game

A command-line implementation of the classic Tic-tac-toe game where you play against an Computer opponent that never loses. The game features color-coded outputs and strategic Computer gameplay.

## Overview

Tic-tac-toe (also known as Noughts and Crosses or Xs and Os) is a paper-and-pencil game for two players who take turns marking the spaces in a three-by-three grid with X or O. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner.

In this implementation, you play against the computer, which uses various strategies to ensure it never loses a game. You can play as either Player 1 (O) or Player 2 (X).

## How to Build and Run

### Using Make

```bash
make        # Compile the game
make run    # Compile and run the game
make clean  # Remove the executable
```

### Manual Compilation

```bash
gcc tictactoe.c -o tictactoe
./tictactoe
```

## Gameplay

1. Choose whether you want to be Player 1 (O) or Player 2 (X)
2. Enter a number from 1-9 corresponding to the position on the board:

   ```txt
     1 | 2 | 3
   -------------
     4 | 5 | 6
   -------------
     7 | 8 | 9
   ```

3. The Computer will make its move
4. Continue until there's a winner or the game ends in a tie

## Features

- Color-coded text output using ANSI color codes
- Two difficulty options (Player 1 or Player 2)
- Unbeatable Computer that uses strategic gameplay
- Clear screen after each move for better readability
- Input validation to prevent illegal moves

## Computer Strategy

The Computer uses several strategies to play optimally:

- It prioritizes winning moves when possible
- It blocks your winning moves
- It creates "forks" (two potential winning paths)
- It takes the center when available
- It uses corner and edge strategies based on player moves

## Notes

- The Computer is designed to never lose. At best, you can achieve a tie.
- The Computer always plays as 'X', making it the first player when you choose Player 2.
