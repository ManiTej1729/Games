CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses -lm

TARGET = 2048
SRC = main.c 2048.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
