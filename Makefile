OBJECTS = main.o
c2cpp: $(OBJECTS)
	cc $(OBJECTS) -o c2cpp
main.o: main.c

clean:
	rm -rf *.o
