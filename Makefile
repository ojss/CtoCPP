#I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all: c2cpp

c2cpp: main.o converter_helper.o converter_helpers.h
	$(CC) main.o converter_helper.o -o c2cpp

main.o: main.c
	$(CC) $(CFLAGS) main.c

converter_helper.o: converter_helper.c converter_helpers.h
	$(CC) $(CFLAGS) converter_helper.c

clean:
	rm *o c2cpp toC.cpp
