all: project

project: nl.o
	gcc nl.o -o project

nl.o:  nl.c
	gcc -c nl.c

clean:
	rm -rf *o project
