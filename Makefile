CC = gcc

all: rodriguesfetch

rodriguesfetch: main.o
	${CC} -o rodriguesfetch main.o 

main.o: main.c
	${CC} -c main.c


