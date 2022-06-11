CC = gcc
FLAGS = -Wpedantic -std=gnu99

all: P11.o P12.o P21.o P22.o main.o main

P11.o: P11.c myHeader.h
	$(CC) $(FLAGS) -c P11.c -o P11.o

P12.o: P12.c myHeader.h
	$(CC) $(FLAGS) -c P12.c -o P12.o

P21.o: P21.c myHeader.h
	$(CC) $(FLAGS) -c P21.c -o P21.o

P22.o: P22.c myHeader.h
	$(CC) $(FLAGS) -c P22.c -o P22.o


main.o: main.c myHeader.h
	$(CC) $(FLAGS) -c main.c -o main.o
main: main.o 
	$(CC) $(FLAGS) main.o P11.o P12.o P21.o P22.o -o main -lm

clean:
	rm -r *.o main