CXX = g++
CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o PyTypeObject.o PyIntObject.o PyStrObject.o PyDictObject.o
TARGET = python

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
