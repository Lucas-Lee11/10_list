all: main.o linked_list.o
	gcc -o prgrm main.o linked_list.o

main.o: main.c linked_list.h
	gcc -c main.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

run: prgrm
	./prgrm
