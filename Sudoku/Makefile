# Makefile for Sudoku program

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses

# File names
TARGET = sudoku
SOURCE = sudoku.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

# Build and run in one command
go: $(TARGET) run

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f *~

.PHONY: all run clean go
