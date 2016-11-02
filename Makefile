all: project

project: nl.o
	gcc nl.o -o project

nl.o:  nl.c functions.h
	gcc -c nl.c

clean:
	rm -rf *o project
