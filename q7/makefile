.PHONY: all clean 

CC = g++
CFLAGS = -g -pthread

all: race

race: race.o 
	$(CC) $(CFLAGS)  -o race race.o 

race.o: race.cpp 
	$(CC) $(CFLAGS) -c race.cpp

clean:
	rm -f *.o race

