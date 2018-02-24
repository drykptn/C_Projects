all: run exe 

run: main.o
	gcc main.o -o main

exe:
	./main input.txt -ansi pedantic-errors -Wall

clean:
	rm *.o main
