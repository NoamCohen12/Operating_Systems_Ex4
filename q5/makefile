.PHONY: all clean 

CC = g++
CFLAGS = -g 

all: hello

hello: hello.o 
	$(CC) $(CFLAGS)  -o hello hello.o 

hello.o: hello.cpp 
	$(CC) $(CFLAGS) -c hello.cpp

clean:
	rm -f *.o hello

