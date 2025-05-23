# Sudoku Solver

A command-line Sudoku solver implemented in C using the ncurses library for display.

## Description

This Sudoku solver reads an unsolved puzzle from an input file and displays the solution. Features include:

- Automatic solving of Sudoku puzzles
- Produces the lexicographically smallest solution when multiple solutions exist
- Terminal-based visualization using ncurses
- Efficient backtracking algorithm implementation

## Requirements

- GCC compiler
- ncurses library

## Installation

### Install the ncurses library

For Debian/Ubuntu:

```bash
sudo apt-get install libncurses5-dev
```

For macOS:

```bash
brew install ncurses
```

For Fedora/RHEL:

```bash
sudo dnf install ncurses-devel
```

## Compilation and Running

This project includes a Makefile for easy compilation and execution.

### Available Commands

- Build the solver:
  
  ```bash
  make
  ```

- Run the solver:
  
  ```bash
  make run
  ```

- Build and run in one step:
  
  ```bash
  make go
  ```

- Clean compiled files:
  
  ```bash
  make clean
  ```

## Input Format

The solver reads puzzles from `input.txt`. The format should be:

- A 9x9 grid representing the Sudoku puzzle
- Use digits 1-9 for filled cells separated by spaces
- Use 0 for empty cells
- Each row on a separate line

Example:

```txt
1 0 0 3 0 4 8 0 9
0 2 4 0 0 0 0 0 7
0 0 0 9 6 0 5 0 0
2 3 0 0 0 0 0 5 0
5 0 7 0 0 8 0 0 0
0 0 0 0 0 0 4 0 0
0 0 9 5 0 0 0 0 0
3 0 0 8 0 0 0 0 0
0 5 0 6 0 0 0 3 0
```

## Algorithm

The solver uses a backtracking algorithm that:

1. Finds an empty cell
2. Tries placing digits 1-9 in ascending order
3. Checks if the placement is valid according to Sudoku rules
4. Continues to the next cell if valid, backtracks if not
5. Returns the lexicographically smallest valid solution

## Project Structure

- `sudoku.c` - Main source file containing solver logic and display
- `Makefile` - Build configuration
- `input.txt` - Input file containing the unsolved Sudoku puzzle
