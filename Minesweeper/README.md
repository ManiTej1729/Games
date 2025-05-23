# Minesweeper

A terminal-based implementation of the classic Minesweeper game using C++ and ncurses.

## Game Description

Minesweeper is a single-player puzzle game where the objective is to clear a rectangular board containing hidden "mines" without detonating any of them. You reveal information about the number of neighboring mines by clicking on cells.

## Features

- Three difficulty levels:
  - Easy: 9×9 board with 10 mines
  - Medium: 16×16 board with 40 mines
  - Hard: 16×30 board with 99 mines
- Color-coded interface using ncurses
- Mouse input support
- Flag placement (right-click) to mark potential mines
- Automatic clearing of connected empty cells

## Requirements

- C++ compiler
- ncurses library
- make (optional, for using the Makefile)

## Setup and Installation

### Installing Dependencies

#### On Debian/Ubuntu

```sh
sudo apt-get install libncurses5-dev libncursesw5-dev
```

#### On CentOS/RHEL/Fedora

```sh
sudo dnf install ncurses-devel
```

#### On macOS

```sh
brew install ncurses
```

### Building and Running

#### Using Make

```sh
# Build the game
make

# Run the game
make run

# Clean build files
make clean
```

#### Manual Compilation

```sh
g++ minesweeper.cpp -o minesweeper -lncurses
./minesweeper
```

## How to Play

1. **Start the game** and select a difficulty level by clicking on Easy, Medium, or Hard.

2. **Controls**:
   - Left-click: Reveal a cell
   - Right-click: Place/remove a flag on a suspected mine
   - Press 'q' to quit the game

3. **Game Rules**:
   - If you reveal a mine, you lose
   - Numbers indicate how many mines are adjacent to that cell
   - Your goal is to flag all mines and reveal all non-mine cells
   - The game is won when all non-mine cells are revealed

## Implementation Details

The game uses a visual grid representation with:

- Green squares for unrevealed cells
- Blue squares for flagged cells
- Numbers (or blank spaces) for revealed cells
- Red squares for mines when the game ends
