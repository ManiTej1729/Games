# Makefile for Tic-tac-toe game

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Target executable
TARGET = tictactoe

# Source file
SRC = tictactoe.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Run the game
run: $(TARGET)
	./$(TARGET)

# Clean up
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all run clean
