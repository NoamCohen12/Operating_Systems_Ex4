.PHONY: all clean 

CC = g++
CFLAGS = -g 

all: main

main: main.o Graph.o
	$(CC) $(CFLAGS)  -o main main.o Graph.o

main.o: main.cpp Graph.hpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Graph.cpp

clean:
	rm -f *.o main

