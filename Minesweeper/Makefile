CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lncurses

TARGET = minesweeper
SRC = minesweeper.cpp

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
