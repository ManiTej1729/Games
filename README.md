# Personal Games Collection

This repository contains a collection of classic games implemented in various programming languages. Most games are built in C/C++ with a few web-based implementations.

## Games Available

| Game | Description | Technology | Requirements |
|------|-------------|------------|--------------|
| [2048](#2048) | Sliding number puzzle game | C | Terminal |
| [Minesweeper](#minesweeper) | Grid-based logic puzzle | C++ | Terminal |
| [Snake](#snake) | Classic snake game | C | Terminal |
| [Sudoku](#sudoku) | Number placement puzzle | C | Terminal |
| [Tetris](#tetris) | Falling block puzzle game | C | Terminal |
| [Tic-tac-toe](#tic-tac-toe) | Classic X and O game | C | Terminal |
| [Wordle](#wordle) | Word guessing game | HTML/JS | Web Browser & Internet |

## Game Details

### 2048

A sliding tile puzzle game where you combine numbered tiles to reach 2048.

- **Language**: C
- **How to Play**:

  ```bash
  cd 2048
  make
  ./2048
  ```

- See the [2048 README](2048/README.md) for more details.

### Minesweeper

The classic grid-based puzzle game where you need to clear a minefield without detonating any mines.

- **Language**: C++
- **How to Play**:

  ```bash
  cd minesweeper
  make
  ./minesweeper
  ```

- See the [Minesweeper README](minesweeper/README.md) for more details.

### Snake

Control a snake to eat food and grow without colliding with walls or your own body.

- **Language**: C
- **How to Play**:

  ```bash
  cd snake
  make
  ./snake
  ```

- See the [Snake README](snake/README.md) for more details.

### Sudoku

The number placement puzzle where you fill a 9×9 grid with digits so that each column, row, and 3×3 section contains all digits from 1 to 9.

- **Language**: C
- **How to Play**:

  ```bash
  cd sudoku
  make
  ./sudoku
  ```

- See the [Sudoku README](sudoku/README.md) for more details.

### Tetris

The classic falling block puzzle game.

- **Language**: C
- **How to Play**:
  
  ```bash
  cd tetris
  make
  ./tetris
  ```

- See the [Tetris README](tetris/README.md) for more details.

### Tic-tac-toe

The classic game of X's and O's against an unbeatable AI.

- **Language**: C
- **How to Play**:

  ```bash
  cd Tic-tac-toe
  make
  ./tictactoe
  ```

- See the [Tic-tac-toe README](Tic-tac-toe/README.md) for more details.

### Wordle

A word guessing game where you have six attempts to guess a five-letter word.

- **Technology**: HTML, CSS, JavaScript
- **How to Play**:
  - Open `wordle/index.html` in any web browser
  - **Note**: Internet connection is required as the game uses CDN resources
- See the [Wordle README](wordle/README.md) for more details.

## General Requirements

### For C/C++ Games

- GCC/G++ compiler
- Make utility
- Terminal with ANSI color support (for some games)

### For Web-Based Games

- Modern web browser (Chrome, Firefox, Safari, etc.)
- Internet connection (for CDN resources)

## Maintenance

Each game directory contains its own Makefile (except Wordle) and README with specific instructions for that game.

To clean all compiled executables at once:

```
find . -name "Makefile" -execdir make clean \;
```

Enjoy the games!
