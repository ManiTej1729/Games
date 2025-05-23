# 2048 Game

A terminal-based implementation of the popular 2048 puzzle game using C and ncurses.

## Overview

2048 is a sliding block puzzle game where the objective is to combine tiles with the same numbers to create a tile with the value 2048. This implementation presents the game in a text-based interface using the ncurses library.

## Features

- Full terminal-based gameplay with ncurses interface
- Keyboard controls (arrow keys or WASD)
- Score tracking
- Win/loss detection

## Requirements

- GCC compiler
- ncurses library
- make (for using the Makefile)

## Building and Running

### Using Make

```bash
# Build the game
make

# Run the game
make run

# Clean build files
make clean
```

### Manual Compilation

```bash
gcc main.c 2048.c -o 2048 -lncurses -lm
./2048
```

## How to Play

1. Use arrow keys or WASD to move tiles
   - ↑ or W: Move tiles up
   - ← or A: Move tiles left
   - ↓ or S: Move tiles down
   - → or D: Move tiles right

2. When two tiles with the same number touch, they merge into one tile with the sum of their values

3. After each move, a new tile with a value of 2 appears at a random empty position

4. The game is won when a tile with the value 2048 is created

5. The game is lost when there are no more valid moves (the board is full and no adjacent tiles can be merged)

## Game Structure

- `main.c`: Contains the game initialization and main loop
- `2048.c`: Implements the game mechanics and board manipulation
- `2048.h`: Header file with function declarations
- `Makefile`: Build configuration
