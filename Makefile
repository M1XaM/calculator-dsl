CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = test
SRC = src/main.cpp

.PHONY: all build run clean

all: build

build:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: build
	./$(TARGET) inputTests/basic.faf

clean:
	rm -f $(TARGET)
