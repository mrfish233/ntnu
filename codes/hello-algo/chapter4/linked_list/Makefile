all: linked_list.o main.c
	-gcc main.c linked_list.o -Wall -Wextra -o main
linked_list: linked_list.c
	-gcc -c linked_list.c -Wall -Wextra -o linked_list.o
clean:
	rm -rf main *.o
