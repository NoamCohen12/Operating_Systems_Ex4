.PHONY: all clean coverage clean-coverage

CC = g++
CFLAGS = -g 
CGOV = -fprofile-arcs -ftest-coverage

all: main

main: main.o Graph.o
	$(CC) $(CFLAGS) $(CGOV) -o main main.o Graph.o

main.o: main.cpp Graph.hpp
	$(CC) $(CFLAGS) $(CGOV) -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) $(CGOV) -c Graph.cpp

clean:
	rm -f *.o main *.gcno *.gcda *.gcov

clean-coverage:
	rm -f *.gcno *.gcda *.gcov

coverage: clean-coverage all
	./main # Assuming this runs your program and generates .gcda files
	gcov main.cpp Graph.cpp
