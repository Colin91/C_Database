all: program
program: main.o Linked_List.o Circular_Buffer.o
	gcc main.o Linked_List.o Circular_Buffer.o -o program

main.o: main.c
	gcc -c main.c


Linked_List.o: Linked_List.c
	gcc -c Linked_List.c


Circular_Buffer.o: Circular_Buffer.c
	gcc -c Circular_Buffer.c

clean:
	rm -rf *o program
